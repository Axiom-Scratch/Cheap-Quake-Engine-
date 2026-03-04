add_executable(Sandbox
    Sandbox.cpp
)

target_link_libraries(Sandbox
    PRIVATE QuakeEngine
)

if (WIN32)
    set_target_properties(Sandbox PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/$<CONFIG>
    )
else()
    set_target_properties(Sandbox PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    )
endif()

if (MSVC)
    target_compile_options(Sandbox PRIVATE /W4 /WX)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(Sandbox PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

if (WIN32)
    add_custom_command(TARGET Sandbox POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:QuakeEngine>
            $<TARGET_FILE_DIR:Sandbox>
    )
elseif (UNIX AND NOT APPLE)
    set_target_properties(Sandbox PROPERTIES
        BUILD_RPATH "$ORIGIN"
    )
endif()