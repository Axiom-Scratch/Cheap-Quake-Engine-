#include "Application.h"

#include "Events/EventBus.h"
#include "Input.h"

#include <stdexcept>

Application::Application()
    : m_Window(Window::Create())
{
    if (!m_Window)
    {
        throw std::runtime_error("Failed to create window");
    }

    EventBus::Sink<WindowCloseEvent>().connect<&Application::OnWindowClose>(*this);
}

void Application::Run()
{
    OnInit();

    while (m_Running && !m_Window->ShouldClose())
    {
        m_Window->OnUpdate();
        EventBus::Update();
        OnUpdate();
        Input::EndFrame();
    }

    OnShutdown();
}

bool Application::OnWindowClose(const WindowCloseEvent&)
{
    m_Running = false;
    return true;
}
