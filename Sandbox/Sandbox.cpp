#include "Core/Application.h"
#include "Core/Events/EngineEvents.h"
#include "Core/Events/EventBus.h"
#include "Core/Input.h"
#include "Core/KeyCodes.h"

#include <iostream>

class SandboxApp final : public Application
{
protected:
    void OnInit() override
    {
        EventBus::Sink<WindowResizeEvent>().connect<&SandboxApp::OnWindowResize>(*this);
        EventBus::Sink<MouseScrolledEvent>().connect<&SandboxApp::OnMouseScrolled>(*this);
    }

    void OnUpdate() override
    {
        if (Input::IsKeyPressed(KeyCode::W))
        {
            std::cout << "W pressed\n";
        }

        if (Input::IsKeyDown(KeyCode::W))
        {
            std::cout << "W held\n";
        }

        if (Input::IsKeyReleased(KeyCode::W))
        {
            std::cout << "W released\n";
        }

        if (Input::IsMouseButtonPressed(MouseCode::Left))
        {
            std::cout << "Mouse left click\n";
        }

        if (Input::IsKeyPressed(KeyCode::Escape))
        {
            std::cout << "Escape pressed\n";
        }
    }

    void OnShutdown() override
    {
    }

private:
    void OnWindowResize(const WindowResizeEvent& event)
    {
        std::cout << "Window resized: " << event.Width << "x" << event.Height << "\n";
    }

    void OnMouseScrolled(const MouseScrolledEvent& event)
    {
        std::cout << "Mouse scrolled: " << event.XOffset << ", " << event.YOffset << "\n";
    }
};

namespace Axiom
{
Application* CreateApplication()
{
    return new SandboxApp();
}
}

#include "Entrypoint.cpp"
