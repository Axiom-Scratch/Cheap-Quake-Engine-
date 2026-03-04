add_library(Axiom STATIC
    Core/Application.cpp
    Core/Platform/GLFW/GLFWWindow.cpp
)

target_include_directories(Axiom
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(Axiom
    PRIVATE glfw
)

if (MSVC)
    target_compile_options(Axiom PRIVATE /W4 /WX)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(Axiom PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()