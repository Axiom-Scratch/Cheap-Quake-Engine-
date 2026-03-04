#include "Core/Application.h"
#include "Core/Events/EngineEvents.h"
#include "Core/Events/EventBus.h"
#include "Core/Input.h"
#include "Core/KeyCodes.h"
#include "Core/Layers/Layer.h"
#include "Core/Log.h"

#include <iostream>

class ExampleLayer final : public Layer
{
public:
    ExampleLayer()
        : Layer("ExampleLayer")
    {
    }

    void OnAttach() override
    {
        std::cout << "Layer attached\n";
    }

    void OnUpdate() override
    {
        if (Input::IsKeyPressed(KeyCode::W))
        {
            std::cout << "W pressed from Layer\n";
        }
    }

    void OnEvent(const KeyPressedEvent& event) override
    {
        if (event.Key == KeyCode::Escape)
        {
            std::cout << "Escape pressed from Layer\n";
        }
    }
};

class SandboxApp final : public Application
{
protected:
    void OnInit() override
    {
        PushLayer(new ExampleLayer());

        AXIOM_CORE_INFO("Engine started");
        AXIOM_INFO("Sandbox running");

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
