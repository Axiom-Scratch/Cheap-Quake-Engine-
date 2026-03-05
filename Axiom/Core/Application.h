#pragma once

#include "Base.h"
#include "Events/EngineEvents.h"
#include "Layers/LayerStack.h"
#include "SmartPointer.h"
#include "Window.h"

#include <memory>

class Application
{
public:
    AXIOM_API Application();
    virtual ~Application() = default;

    AXIOM_API void Run();
    AXIOM_API void PushLayer(Layer* layer);
    AXIOM_API void PushOverlay(Layer* layer);

protected:
    virtual void OnInit() {}
    virtual void OnUpdate() {}
    virtual void OnShutdown() {}

private:
    template<typename Event>
    void OnEvent(const Event& event);

    bool OnWindowClose(const WindowCloseEvent& event);

    std::unique_ptr<Window> m_Window;
    LayerStack m_LayerStack;
    bool m_Running = true;
};

template<typename Event>
void Application::OnEvent(const Event& event)
{
    for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
    {
        (*--it)->OnEvent(event);
    }
}
