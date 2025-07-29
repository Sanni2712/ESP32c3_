# ESP32c3_
Simple GPIO control and drive strength using the Pad registers of the esp32c3 in C & C++ using the official ESP-IDF framework and FreeRTOS library for ESP32c3

## Requirements 
Install and setup [ESP-IDF](https://dl.espressif.com/dl/esp-idf/?idf=release-v5.2)<br><br>

### creating a project - 
run the ESP-IDF command prompt<br>
`idf.py create-project project_name`<br>
`idf.py set-target esp32c3`<br><br>

project_name/ <br>
├── CMakeLists.txt<br>
├── main/<br>
│  &nbsp;&nbsp; ├── project_name.c<br>
| &nbsp;&nbsp;  └── CMakeLists.txt<br>

### building 
navigate to the project folder 'cd project_name'<br>
then `idf.py build` to build/compile the project<br>
A new build folder is created. <br><br>
project_name/ <br>
├── CMakeLists.txt<br>
├── main/<br>
│  &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;├── project_name.c<br>
│  &nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;└── CMakeLists.txt<br>
└── build<br>

## Flash the Firmware
connect the esp32<br>
`idf.py flash`<br>
you may be prompted to select the port 



## converting to c++ 
The command idf.py create-project <project-name> creates a C-style template project, not a proper C++ setup by default. But you can easily convert it to a C++ project. Here's how:
<br>Rename project_name.c → main.cpp<br/>
project_name/ <br><br>
├── CMakeLists.txt<br>
├── main/<br>
│ &nbsp;&nbsp;&nbsp;&nbsp;  ├── main.cpp<br>
│  &nbsp;&nbsp;&nbsp;&nbsp; └── CMakeLists.txt<br><br>
extern "C" is needed for app_main() because ESP-IDF expects a C symbol<br>

No changes are needed in CMakeLists.txt<br>
ESP-IDF automatically detects .cpp and uses g++<br>
