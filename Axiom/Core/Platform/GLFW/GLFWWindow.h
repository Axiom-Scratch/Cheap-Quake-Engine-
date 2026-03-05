#pragma once

#include "Core/Base.h"
#include "Core/Window.h"

#include <GLFW/glfw3.h>

class GLFWWindow final : public Window
{
public:
    explicit GLFWWindow(const WindowProps& props);
    ~GLFWWindow() override;

    void OnUpdate() override;
    bool ShouldClose() const override;
    std::uint32_t GetWidth() const override;
    std::uint32_t GetHeight() const override;

private:
    GLFWwindow* m_Window = nullptr;
    WindowProps m_Props;
};
