#include "Application.h"

#include <stdexcept>

Application::Application()
    : m_Window(Window::Create())
{
    if (!m_Window)
    {
        throw std::runtime_error("Failed to create window");
    }
}

void Application::Run()
{
    OnInit();

    while (!m_Window->ShouldClose())
    {
        m_Window->OnUpdate();
    }

    OnShutdown();
}