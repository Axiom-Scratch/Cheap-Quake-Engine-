#pragma once

#include "Core/KeyCodes.h"

#include <cstdint>

struct WindowCloseEvent
{
};

struct WindowResizeEvent
{
    uint32_t Width;
    uint32_t Height;
};

struct KeyPressedEvent
{
    KeyCode Key;
    bool Repeat;
};

struct KeyReleasedEvent
{
    KeyCode Key;
};

struct MouseMovedEvent
{
    double X;
    double Y;
};

struct MouseButtonPressedEvent
{
    MouseCode Button;
};

struct MouseButtonReleasedEvent
{
    MouseCode Button;
};

struct MouseScrolledEvent
{
    double XOffset;
    double YOffset;
};
