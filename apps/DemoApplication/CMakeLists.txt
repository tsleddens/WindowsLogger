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

#enable warnings
target_compile_options(${TARGET}
    PRIVATE
        /W4
)