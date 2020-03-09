cmake_minimum_required(VERSION 3.16)

project(WindowsLogger VERSION 1.0.0 LANGUAGES CXX)

option(WINDOWS_LOGGER_BUILD_DEMO "Build WindowsLogger Demo Application" NO)
option(WINDOWS_LOGGER_SYSTEM_PAUSE "Call system(\"pause\") on shutdown" YES)

#enable the use of folders in an IDE
get_property(IS_USE_FOLDERS_SET GLOBAL PROPERTY USE_FOLDERS)
if(NOT IS_USE_FOLDERS_SET)
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif()

add_subdirectory(src)

if(WINDOWS_LOGGER_BUILD_DEMO)
    add_subdirectory(apps)
    set_directory_properties(PROPERTIES
        VS_STARTUP_PROJECT DemoApplication
    )
endif()