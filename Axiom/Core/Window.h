#pragma once

#include "Base.h"

#include <cstdint>
#include <string>
#include <utility>

struct WindowProps
{
    std::string Title;
    std::uint32_t Width;
    std::uint32_t Height;

    WindowProps(
        std::string title = "Axiom Engine",
        std::uint32_t width = 1280,
        std::uint32_t height = 720)
        : Title(std::move(title)), Width(width), Height(height)
    {
    }
};

class Window
{
public:
    virtual ~Window() = default;

    virtual void OnUpdate() = 0;
    virtual bool ShouldClose() const = 0;
    virtual std::uint32_t GetWidth() const = 0;
    virtual std::uint32_t GetHeight() const = 0;

    static Window* Create(const WindowProps& props = WindowProps());
};
