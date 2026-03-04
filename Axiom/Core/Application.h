#pragma once

#include "Base.h"
#include "Events/EngineEvents.h"
#include "SmartPointer.h"
#include "Window.h"

#include <memory>

class Application
{
public:
    Application();
    virtual ~Application() = default;

    void Run();

protected:
    virtual void OnInit() {}
    virtual void OnUpdate() {}
    virtual void OnShutdown() {}

private:
    bool OnWindowClose(const WindowCloseEvent& event);

    std::unique_ptr<Window> m_Window;
    bool m_Running = true;
};
