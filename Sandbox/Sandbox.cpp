#include "Core/Application.h"

#include <iostream>
#include <memory>

class SandboxApp final : public Application
{
protected:
    void OnInit() override
    {
        std::cout << "Sandbox Init\n";
    }

    void OnUpdate() override
    {
        std::cout << "Sandbox Update\n";
        Close();
    }

    void OnShutdown() override
    {
        std::cout << "Sandbox Shutdown\n";
    }
};

std::unique_ptr<Application> CreateApplication()
{
    return std::make_unique<SandboxApp>();
}

#include "Entrypoint.cpp"
