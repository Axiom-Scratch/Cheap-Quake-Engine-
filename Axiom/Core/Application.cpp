#include "Application.h"

#include "Events/EventBus.h"
#include "Input.h"
#include "Log.h"

#include <stdexcept>

Application::Application()
    : m_Window(Window::Create())
    , m_LayerStack()
{
    if (!m_Window)
    {
        throw std::runtime_error("Failed to create window");
    }

    Log::Init();
    AXIOM_CORE_INFO("Axiom Engine Initialized");

    EventBus::Sink<WindowCloseEvent>().connect<&Application::OnEvent<WindowCloseEvent>>(*this);
    EventBus::Sink<WindowResizeEvent>().connect<&Application::OnEvent<WindowResizeEvent>>(*this);
    EventBus::Sink<KeyPressedEvent>().connect<&Application::OnEvent<KeyPressedEvent>>(*this);
    EventBus::Sink<KeyReleasedEvent>().connect<&Application::OnEvent<KeyReleasedEvent>>(*this);
    EventBus::Sink<MouseMovedEvent>().connect<&Application::OnEvent<MouseMovedEvent>>(*this);
    EventBus::Sink<MouseButtonPressedEvent>()
        .connect<&Application::OnEvent<MouseButtonPressedEvent>>(*this);
    EventBus::Sink<MouseButtonReleasedEvent>()
        .connect<&Application::OnEvent<MouseButtonReleasedEvent>>(*this);
    EventBus::Sink<MouseScrolledEvent>().connect<&Application::OnEvent<MouseScrolledEvent>>(*this);
    EventBus::Sink<WindowCloseEvent>().connect<&Application::OnWindowClose>(*this);
}

void Application::Run()
{
    OnInit();

    while (m_Running && !m_Window->ShouldClose())
    {
        m_Window->OnUpdate();
        EventBus::Update();
        for (Layer* layer : m_LayerStack)
        {
            layer->OnUpdate();
        }
        OnUpdate();
        Input::EndFrame();
    }

    OnShutdown();
}

void Application::PushLayer(Layer* layer)
{
    m_LayerStack.PushLayer(layer);
}

void Application::PushOverlay(Layer* layer)
{
    m_LayerStack.PushOverlay(layer);
}

bool Application::OnWindowClose(const WindowCloseEvent&)
{
    m_Running = false;
    return true;
}
