#pragma once

#include "Core/Events/EngineEvents.h"

#include <string>

class Layer
{
public:
    AXIOM_API explicit Layer(std::string name = "Layer");
    virtual ~Layer() = default;

    virtual void OnAttach() {}
    virtual void OnDetach() {}
    virtual void OnUpdate() {}

    virtual void OnEvent(const WindowCloseEvent&) {}
    virtual void OnEvent(const WindowResizeEvent&) {}
    virtual void OnEvent(const KeyPressedEvent&) {}
    virtual void OnEvent(const KeyReleasedEvent&) {}
    virtual void OnEvent(const MouseMovedEvent&) {}
    virtual void OnEvent(const MouseButtonPressedEvent&) {}
    virtual void OnEvent(const MouseButtonReleasedEvent&) {}
    virtual void OnEvent(const MouseScrolledEvent&) {}

    const std::string& GetName() const { return m_DebugName; }

protected:
    std::string m_DebugName;
};
