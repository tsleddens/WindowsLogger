include_guard()

set(TARGET WindowsLogger)

set(INCLUDE_FOLDER ${WindowsLogger_SOURCE_DIR}/include)

set(SRC_FILES
    ConsoleLogger.cxx
)

set(HEADER_FILES
    ${INCLUDE_FOLDER}/WindowsLogger/ConsoleLogger.hxx
    ${INCLUDE_FOLDER}/WindowsLogger/ILogger.hxx
)

#define library target
add_library(${TARGET} ${SRC_FILES} ${HEADER_FILES})

#declare public include folder
target_include_directories(${TARGET} PUBLIC ${INCLUDE_FOLDER})

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