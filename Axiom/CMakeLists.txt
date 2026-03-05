add_library(Axiom SHARED
    Core/Application.cpp
    Core/Input.cpp
    Core/Log.cpp
    Core/Layers/Layer.cpp
    Core/Layers/LayerStack.cpp
    Core/Platform/GLFW/GLFWWindow.cpp
)

target_include_directories(Axiom
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/external/entt/src
)

target_link_libraries(Axiom
    PUBLIC
        glfw
        spdlog::spdlog_header_only
)

target_compile_definitions(Axiom
    PRIVATE
        AXIOM_BUILD_DLL
)

if (MSVC)
    target_compile_options(Axiom PRIVATE /W4 /WX)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(Axiom PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
