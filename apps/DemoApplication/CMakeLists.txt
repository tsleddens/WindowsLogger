include_guard()

set(TARGET DemoApplication)

set(SRC_FILES
    main.cxx
)

#define library target
add_executable(${TARGET} WIN32 ${SRC_FILES})

target_link_libraries(${TARGET}
    PRIVATE 
        WindowsLogger
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