#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

void Log::Init()
{
    spdlog::set_pattern("[%T] [%^%l%$] %n: %v");

    s_CoreLogger = spdlog::stdout_color_mt("AXIOM");
    s_ClientLogger = spdlog::stdout_color_mt("APP");

    spdlog::set_level(spdlog::level::trace);
}

std::shared_ptr<spdlog::logger>& Log::GetCoreLogger()
{
    return s_CoreLogger;
}

std::shared_ptr<spdlog::logger>& Log::GetClientLogger()
{
    return s_ClientLogger;
}
