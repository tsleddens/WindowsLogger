include_guard()

set(TARGET WindowsLogger)

set(PRIVATE_INCLUDE_FOLDER ${WindowsLogger_SOURCE_DIR}/include/WindowsLogger)
set(INTERFACE_INCLUDE_FOLDER ${WindowsLogger_SOURCE_DIR}/include)

set(SRC_FILES
    ConsoleLogger.cxx
)

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

#use minimal version of <windows.h>
target_compile_definitions(${TARGET}
    PRIVATE
        WIN32_LEAN_AND_MEAN
)

#enable warnings
target_compile_options(${TARGET}
    PRIVATE
        /W4
)