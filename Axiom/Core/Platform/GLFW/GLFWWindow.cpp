#include "GLFWWindow.h"

#include <cstdlib>
#include <mutex>

namespace
{
std::once_flag g_GLFWInitFlag;
bool g_GLFWInitialized = false;
struct GLFWLifetime
{
    ~GLFWLifetime()
    {
        if (g_GLFWInitialized)
        {
            glfwTerminate();
        }
    }
};
GLFWLifetime g_GLFWLifetime;
}

GLFWWindow::GLFWWindow(const WindowProps& props)
    : m_Props(props)
{
    std::call_once(g_GLFWInitFlag, []() {
        g_GLFWInitialized = glfwInit() == GLFW_TRUE;
    });

    if (!g_GLFWInitialized)
    {
        std::abort();
    }

    m_Window = glfwCreateWindow(
        static_cast<int>(m_Props.Width),
        static_cast<int>(m_Props.Height),
        m_Props.Title.c_str(),
        nullptr,
        nullptr);

    if (!m_Window)
    {
        std::abort();
    }

    glfwMakeContextCurrent(m_Window);
    glfwSwapInterval(1);
}

GLFWWindow::~GLFWWindow()
{
    if (m_Window)
    {
        glfwDestroyWindow(m_Window);
        m_Window = nullptr;
    }
}

void GLFWWindow::OnUpdate()
{
    glfwPollEvents();
    glfwSwapBuffers(m_Window);
}

bool GLFWWindow::ShouldClose() const
{
    return glfwWindowShouldClose(m_Window) != 0;
}

std::uint32_t GLFWWindow::GetWidth() const
{
    return m_Props.Width;
}

std::uint32_t GLFWWindow::GetHeight() const
{
    return m_Props.Height;
}

Window* Window::Create(const WindowProps& props)
{
    return new GLFWWindow(props);
}
