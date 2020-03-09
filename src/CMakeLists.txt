include_guard()

#target name
set(TARGET WindowsLogger)

#private include folder
set(PRIVATE_INCLUDE_FOLDER ${WindowsLogger_SOURCE_DIR}/include/WindowsLogger)

#public include folder
set(INTERFACE_INCLUDE_FOLDER ${WindowsLogger_SOURCE_DIR}/include)

#src files
set(SRC_FILES
    ConsoleLogger.cxx
)

#header files
set(HEADER_FILES
    ${PRIVATE_INCLUDE_FOLDER}/ConsoleLogger.hxx
    ${PRIVATE_INCLUDE_FOLDER}/ILogger.hxx
)

#define library target
add_library(${TARGET} ${SRC_FILES} ${HEADER_FILES})

#declare public include folder
target_include_directories(
    ${TARGET} 
        PRIVATE
            ${PRIVATE_INCLUDE_FOLDER}
        INTERFACE
            ${INTERFACE_INCLUDE_FOLDER}
)

#private definitions variable
set(WINDOWS_LOGGER_PRIVATE_DEFINITIONS WIN32_LEAN_AND_MEAN)

#add to private definitions variable if option is true
if(WINDOWS_LOGGER_SYSTEM_PAUSE)
    list(APPEND WINDOWS_LOGGER_PRIVATE_DEFINITIONS WINDOWS_LOGGER_ENABLE_SYSTEM_PAUSE)
endif()

#use minimal version of <windows.h>
target_compile_definitions(${TARGET}
    PRIVATE
        ${WINDOWS_LOGGER_PRIVATE_DEFINITIONS}
)

#enable warnings
target_compile_options(${TARGET}
    PRIVATE
        /W4
)