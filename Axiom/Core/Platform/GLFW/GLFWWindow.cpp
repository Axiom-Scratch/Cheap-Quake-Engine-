#include "GLFWWindow.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Core/Events/EngineEvents.h"
#include "Core/Events/EventBus.h"

#include <cstdlib>
#include <mutex>
#include <iostream>

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
    std::call_once(g_GLFWInitFlag, []()
        {
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

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::abort();
    }


    const char* vendor = (const char*)glGetString(GL_VENDOR);
    const char* renderer = (const char*)glGetString(GL_RENDERER);
    const char* version = (const char*)glGetString(GL_VERSION);

    printf("OpenGL Loaded\n");
    printf("Vendor: %s\n", vendor ? vendor : "Unknown");
    printf("Renderer: %s\n", renderer ? renderer : "Unknown");
    printf("Version: %s\n", version ? version : "Unknown");


    glfwSwapInterval(1);

    glfwSetWindowCloseCallback(m_Window, [](GLFWwindow*)
        {
            EventBus::Trigger(WindowCloseEvent{});
        });

    glfwSetWindowSizeCallback(m_Window, [](GLFWwindow*, int width, int height)
        {
            EventBus::Trigger(WindowResizeEvent{
                static_cast<uint32_t>(width),
                static_cast<uint32_t>(height) });
        });

    glfwSetKeyCallback(m_Window, [](GLFWwindow*, int key, int, int action, int)
        {
            if (action == GLFW_PRESS)
            {
                EventBus::Trigger(KeyPressedEvent{ static_cast<KeyCode>(key), false });
            }
            else if (action == GLFW_REPEAT)
            {
                EventBus::Trigger(KeyPressedEvent{ static_cast<KeyCode>(key), true });
            }
            else if (action == GLFW_RELEASE)
            {
                EventBus::Trigger(KeyReleasedEvent{ static_cast<KeyCode>(key) });
            }
        });

    glfwSetCursorPosCallback(m_Window, [](GLFWwindow*, double x, double y)
        {
            EventBus::Trigger(MouseMovedEvent{ x, y });
        });

    glfwSetMouseButtonCallback(m_Window, [](GLFWwindow*, int button, int action, int)
        {
            if (action == GLFW_PRESS)
            {
                EventBus::Trigger(MouseButtonPressedEvent{ static_cast<MouseCode>(button) });
            }
            else if (action == GLFW_RELEASE)
            {
                EventBus::Trigger(MouseButtonReleasedEvent{ static_cast<MouseCode>(button) });
            }
        });

    glfwSetScrollCallback(m_Window, [](GLFWwindow*, double xoffset, double yoffset)
        {
            EventBus::Trigger(MouseScrolledEvent{ xoffset, yoffset });
        });
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