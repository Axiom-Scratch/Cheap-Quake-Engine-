#pragma once

#include <memory>

#include "Core/Application.h"

extern std::unique_ptr<Application> CreateApplication();

int main()
{
    auto app = CreateApplication();
    if (!app)
    {
        return 1;
    }

    app->Run();
    return 0;
}