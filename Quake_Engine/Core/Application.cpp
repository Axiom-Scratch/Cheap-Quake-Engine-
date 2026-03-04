#include "Application.h"

void Application::Run()
{
    OnInit();

    while (m_Running)
    {
        OnUpdate();
    }

    OnShutdown();
}

void Application::OnShutdown()
{
}

void Application::Close() noexcept
{
    m_Running = false;
}