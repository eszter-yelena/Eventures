[![C/C++ CI](https://github.com/flari949/COSC345-Eventures/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/flari949/COSC345-Eventures/actions/workflows/c-cpp.yml)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/198761ccc0644b26b6df4f6158db10e4)](https://app.codacy.com/gh/flari949/COSC345-Eventures/dashboard?utm_source=gh&utm_medium=referral&utm_content=&utm_campaign=Badge_grade)
[![Documentation](https://codedocs.xyz/lukePiper03/COSC345-Eventures.svg)](https://codedocs.xyz/lukePiper03/COSC345-Eventures/)
[![codecov](https://codecov.io/gh/lukePiper03/COSC345-Eventures/graph/badge.svg?token=HPN71JUDL7)](https://codecov.io/gh/lukePiper03/COSC345-Eventures)
# COSC345-Project
## About The Project
The Eventures application project is a group project for the COSC345 university paper at the University Of Otago. This project aims to design and create a useful application for the betterment of a user or society with the primary programming language as C/C++. The project requires the incorporation of two or more publicly available datasets (of different data domains) that can be combined to create additional meaning.

### Eventures
Eventures aims to combine [EventFinda](eventfinda.co.nz) event data along with [Land Information New Zealand](https://data.linz.govt.nz) geographical map data to superimpose event data on a visual interface for a unique and valuable exploration and discovery application.

## Link to Questionnaire: https://www.surveymonkey.com/r/QFQFH97

## Project Setup and Installation Guide
**Tested with Software Versions:**
  - C++ compiler supporting the C++17 standard
  - Qt-unified-windows-x64 (Installation Software): Version 4.6.0-online
  - Qt: Version 6.5.2
  - Qt Creator: Version 11.0.2
  - CMake: Version 3.24.2
  - Ninja: Version 1.10.2
  - MinGW: Version 11.2.0; System: 64-bit

## Prerequisites:
Note: The listed software are required for compiling purposes only.
Before compiling the project, make sure you have the following software installed and set up on your system:
1. **Qt Creator - Open-Source:**
     - [Download Qt Online Installer](https://www.qt.io/download-open-source)
     - Open installation wizard and advance to installation folder
     - Select custom installation
     - Select the most recent full-release version of Qt, Qt Creator, CMake and Ninja, as well as the MinGW version corresponding user system.
     - Progress through installation

## Compiling The Project
 1. **Clone The Repository:**
     - Open a terminal and navigate to your preferred directory.
     - Clone the repository:
     ```
     git clone https://github.com/flari949/COSC345-Eventures.git
     ```

 2. **Compile The Project: (Requires Qt Installation)**
    - **Compiling With Qt Creator:**
       - Open Qt Creator
       - Select: File/Open File or Project/ (Ctrl + O)
       - Navigate to and select the Eventures.pro file within the repository
       ```
       Path/to/repository/COSC345-Project/Eventures/Eventures.pro
       ```
       - Select: Build/Build Project "Eventures" (Ctrl + B)
    - **Compiling With Command Line:**
       - Navigate to the project .qmake.stash file location:
       ```
       cd /path/to/project/Eventures
       ```
       - Run QMake:
       ```
       qmake
       ```
       - Run Make:
       ```
       make
       ```
      <hr>
    - **Copy Qt Runtime Dependencies (Optional):**
       - Navigate to the executable directory:
       ```
       cd /path/to/project/Eventures/release 
       ```
       - Generate runtime dependencies with Qt Windows deploy executable:
       ```
       /path/to/Qt/6.5.2/msvc2019_64/bin/windeploy.exe Eventures.exe
       ```

## Running The Project
 - **Running The Executable With Qt Creator:**
     - Ensure project is open in Qt creator (Ctrl + O and navigate to Eventures.pro)
     - Select: Build/Run (Ctrl + R)
 - **Running The Executable With Command Line:**
     - <ins>Without generating runtime dependencies:</ins>
          - Navigate to the project runtime dependency folder:
          ```
          cd /path/to/project/Eventures/include/runtime_dependencies
          ```
          - Run the executable with respect to filepath:
          ```
          ../../release/Eventures.exe
          ```
     - <ins>Build with runtime dependencies in active folder:</ins>
          - Navigate to the project release folder:
          ```
          cd /path/to/project/Eventures/release
          ```
          - Run the executable
          ```
          ./Eventures.exe
          ```

## Target Audience
This application is aimed at university students who don't have the time or the knowledge of local events required to attend. This application has the potential to benefit many more than just the target audience however this is the group the application will cater for the most. Notably, the application will also serve to be of great aid to event organisers who wish to spread knowledge and awareness of their events.

## The Group
Contributors to the Eventures application participating in the Otago University COSC345 paper are as below:
  - Riley Flanagan
  - Luke Piper
  - Kristie Koorts
  - Eszter Scarlett - Herbert


# Contributions
All contributions adhering to the specifications above from members of the public are warmly welcomed, however, must be accepted as pull requests before being added. In addition, credit to the contributor will be added to the README unless otherwise specified.
