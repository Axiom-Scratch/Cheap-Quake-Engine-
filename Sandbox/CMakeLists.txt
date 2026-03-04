if (WIN32)
    add_executable(Sandbox WIN32 Sandbox.cpp)
else()
    add_executable(Sandbox Sandbox.cpp)
endif()

target_link_libraries(Sandbox
    PRIVATE Axiom
)

if (MSVC)
    target_compile_options(Sandbox PRIVATE /W4 /WX)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(Sandbox PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
