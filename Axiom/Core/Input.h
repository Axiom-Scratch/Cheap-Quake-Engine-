#pragma once

#include "Base.h"
#include "Events/EngineEvents.h"

class Input
{
public:
    AXIOM_API static bool IsKeyPressed(KeyCode key);
    AXIOM_API static bool IsKeyReleased(KeyCode key);
    AXIOM_API static bool IsKeyDown(KeyCode key);

    AXIOM_API static bool IsMouseButtonPressed(MouseCode button);

    AXIOM_API static float GetMouseX();
    AXIOM_API static float GetMouseY();
    AXIOM_API static void EndFrame();

private:
    friend struct InputRegistration;

    static void OnKeyPressed(const KeyPressedEvent& event);
    static void OnKeyReleased(const KeyReleasedEvent& event);
    static void OnMouseMoved(const MouseMovedEvent& event);
    static void OnMouseButtonPressed(const MouseButtonPressedEvent& event);
    static void OnMouseButtonReleased(const MouseButtonReleasedEvent& event);

    static bool s_KeyPressed[512];
    static bool s_KeyDown[512];
    static bool s_KeyReleased[512];
    static bool s_MouseButtons[16];
    static float s_MouseX;
    static float s_MouseY;
};
