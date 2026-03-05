#pragma once

#include "Base.h"
#include <memory>

#define SPDLOG_HEADER_ONLY
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#define SPDLOG_USE_STD_FORMAT

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

class Log
{
public:
    AXIOM_API static void Init();

    AXIOM_API static std::shared_ptr<spdlog::logger>& GetCoreLogger();
    AXIOM_API static std::shared_ptr<spdlog::logger>& GetClientLogger();

private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_ClientLogger;
};

#define AXIOM_CORE_TRACE(...) ::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AXIOM_CORE_INFO(...)  ::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AXIOM_CORE_WARN(...)  ::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AXIOM_CORE_ERROR(...) ::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AXIOM_CORE_CRITICAL(...) ::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define AXIOM_TRACE(...) ::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AXIOM_INFO(...)  ::Log::GetClientLogger()->info(__VA_ARGS__)
#define AXIOM_WARN(...)  ::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AXIOM_ERROR(...) ::Log::GetClientLogger()->error(__VA_ARGS__)
#define AXIOM_CRITICAL(...) ::Log::GetClientLogger()->critical(__VA_ARGS__)
