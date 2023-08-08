#include <iostream>
#include <string>
#include <curl/curl.h>
#include <rapidjson/document.h>
  
// Callback function
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

// Function to retrieve API data under given specifications
std::string fetchDataFromAPI(const std::string& apiUrl, const std::string& username, const std::string& password) {
    CURL* curl = curl_easy_init();
    std::string response;

    if (curl) {
        // Set the URL
        curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());

        // Set the write callback function to handle the response
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Set Basic Authentication credentials
        std::string credentials = username + ":" + password;
        curl_easy_setopt(curl, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
        curl_easy_setopt(curl, CURLOPT_USERPWD, credentials.c_str());

        // Perform the request
        CURLcode res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK) {
            std::cerr << "Error during API request: " << curl_easy_strerror(res) << std::endl;
        }

        // Clean up
        curl_easy_cleanup(curl);
    }

    return response;
}

int main() {
    std::string apiUrl = "https://api.eventfinda.co.nz/v2/events.json?rows=1&fields=event:(url)";
    // Need to add as env variables for security
    std::string username = "eventure";
    std::string password = "5jryqspxvxkk";

    // Fetch data from the API
    std::string responseData = fetchDataFromAPI(apiUrl, username, password);

    // Print the response data
    // std::cout << "API Response:\n" << responseData << std::endl;

    // Parse the JSON string
    rapidjson::Document doc;
    doc.Parse(responseData.c_str());

    // Check if parsing was successful
    if (!doc.HasParseError() && doc.IsObject()) {

        // Check response contains appropriate data
        if (doc.MemberCount() >= 2) {
            auto lastMember = doc.MemberEnd() - 1;
            const rapidjson::Value& itemArray = lastMember->value;
            // Check item array format
            if (itemArray.IsArray()) {
                // Iterate over object instances
                for (rapidjson::SizeType i = 0; i < itemArray.Size(); ++i) {
                    const rapidjson::Value& item = itemArray[i];
                    // Check item format
                    if (item.IsObject()) {
                        // URL data
                        if (item.HasMember("url") && item["url"].IsString()) {
                            const char* url = item["url"].GetString();
                            std::cout << "Response url: " << url << std::endl;
                        }
                    }
                }
            } else {
                std::cerr << "Object itemArray is not an array" << std::endl;
            }
        } else {
            std::cerr << "Value not found or empty" << std::endl;
        }
    } else {
        std::cerr << "Failed to parse JSON data" << std::endl;
    }

    return 0;
}

