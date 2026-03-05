#pragma once

#include "Core/Base.h"
#include "Core/KeyCodes.h"

#include <cstdint>

struct AXIOM_API WindowCloseEvent
{
};

struct AXIOM_API WindowResizeEvent
{
    uint32_t Width;
    uint32_t Height;
};

struct AXIOM_API KeyPressedEvent
{
    KeyCode Key;
    bool Repeat;
};

struct AXIOM_API KeyReleasedEvent
{
    KeyCode Key;
};

struct AXIOM_API MouseMovedEvent
{
    double X;
    double Y;
};

struct AXIOM_API MouseButtonPressedEvent
{
    MouseCode Button;
};

struct AXIOM_API MouseButtonReleasedEvent
{
    MouseCode Button;
};

struct AXIOM_API MouseScrolledEvent
{
    double XOffset;
    double YOffset;
};
