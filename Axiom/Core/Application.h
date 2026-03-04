#pragma once

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
    std::unique_ptr<Window> m_Window;
};