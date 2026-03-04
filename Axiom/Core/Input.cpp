#include "Input.h"

#include "Events/EventBus.h"

#include <algorithm>

namespace
{
constexpr int kMaxKeys = 512;
constexpr int kMaxMouseButtons = 16;

bool IsValidKey(KeyCode key)
{
    const int index = static_cast<int>(key);
    return index >= 0 && index < kMaxKeys;
}

bool IsValidMouseButton(MouseCode button)
{
    const int index = static_cast<int>(button);
    return index >= 0 && index < kMaxMouseButtons;
}
}

struct InputRegistration
{
    InputRegistration()
    {
        EventBus::Sink<KeyPressedEvent>().connect<&Input::OnKeyPressed>();
        EventBus::Sink<KeyReleasedEvent>().connect<&Input::OnKeyReleased>();
        EventBus::Sink<MouseMovedEvent>().connect<&Input::OnMouseMoved>();
        EventBus::Sink<MouseButtonPressedEvent>().connect<&Input::OnMouseButtonPressed>();
        EventBus::Sink<MouseButtonReleasedEvent>().connect<&Input::OnMouseButtonReleased>();
    }
};

static InputRegistration s_InputRegistration;

bool Input::s_KeyPressed[512] = {};
bool Input::s_KeyDown[512] = {};
bool Input::s_KeyReleased[512] = {};
bool Input::s_MouseButtons[16] = {};
float Input::s_MouseX = 0.0f;
float Input::s_MouseY = 0.0f;

bool Input::IsKeyPressed(KeyCode key)
{
    if (!IsValidKey(key))
    {
        return false;
    }
    return s_KeyPressed[static_cast<int>(key)];
}

bool Input::IsKeyReleased(KeyCode key)
{
    if (!IsValidKey(key))
    {
        return false;
    }
    return s_KeyReleased[static_cast<int>(key)];
}

bool Input::IsKeyDown(KeyCode key)
{
    if (!IsValidKey(key))
    {
        return false;
    }
    return s_KeyDown[static_cast<int>(key)];
}

bool Input::IsMouseButtonPressed(MouseCode button)
{
    if (!IsValidMouseButton(button))
    {
        return false;
    }
    return s_MouseButtons[static_cast<int>(button)];
}

float Input::GetMouseX()
{
    return s_MouseX;
}

float Input::GetMouseY()
{
    return s_MouseY;
}

void Input::EndFrame()
{
    std::fill(s_KeyPressed, s_KeyPressed + kMaxKeys, false);
    std::fill(s_KeyReleased, s_KeyReleased + kMaxKeys, false);
}

void Input::OnKeyPressed(const KeyPressedEvent& event)
{
    if (!IsValidKey(event.Key))
    {
        return;
    }

    const int index = static_cast<int>(event.Key);
    s_KeyPressed[index] = true;
    s_KeyDown[index] = true;
}

void Input::OnKeyReleased(const KeyReleasedEvent& event)
{
    if (!IsValidKey(event.Key))
    {
        return;
    }

    const int index = static_cast<int>(event.Key);
    s_KeyDown[index] = false;
    s_KeyReleased[index] = true;
}

void Input::OnMouseMoved(const MouseMovedEvent& event)
{
    s_MouseX = static_cast<float>(event.X);
    s_MouseY = static_cast<float>(event.Y);
}

void Input::OnMouseButtonPressed(const MouseButtonPressedEvent& event)
{
    if (!IsValidMouseButton(event.Button))
    {
        return;
    }

    s_MouseButtons[static_cast<int>(event.Button)] = true;
}

void Input::OnMouseButtonReleased(const MouseButtonReleasedEvent& event)
{
    if (!IsValidMouseButton(event.Button))
    {
        return;
    }

    s_MouseButtons[static_cast<int>(event.Button)] = false;
}
