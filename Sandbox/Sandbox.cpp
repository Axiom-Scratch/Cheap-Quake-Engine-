#include "Core/Application.h"

class SandboxApp final : public Application
{
protected:
    void OnInit() override
    {
    }

    void OnUpdate() override
    {
    }

    void OnShutdown() override
    {
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