#pragma once

#include "Core/Application.h"

namespace Axiom
{
Application* CreateApplication();
}

int main()
{
    auto app = Axiom::CreateApplication();
    app->Run();
    return 0;
}
