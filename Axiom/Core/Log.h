#pragma once

#include <memory>

#include <spdlog/spdlog.h>

class Log
{
public:
    static void Init();

    static std::shared_ptr<spdlog::logger>& GetCoreLogger();
    static std::shared_ptr<spdlog::logger>& GetClientLogger();

private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_ClientLogger;
};

#define AXIOM_CORE_TRACE(...) \
    do \
    { \
        auto& logger = ::Log::GetCoreLogger(); \
        if (logger) \
        { \
            logger->trace(__VA_ARGS__); \
        } \
    } while (false)

#define AXIOM_CORE_INFO(...) \
    do \
    { \
        auto& logger = ::Log::GetCoreLogger(); \
        if (logger) \
        { \
            logger->info(__VA_ARGS__); \
        } \
    } while (false)

#define AXIOM_CORE_WARN(...) \
    do \
    { \
        auto& logger = ::Log::GetCoreLogger(); \
        if (logger) \
        { \
            logger->warn(__VA_ARGS__); \
        } \
    } while (false)

#define AXIOM_CORE_ERROR(...) \
    do \
    { \
        auto& logger = ::Log::GetCoreLogger(); \
        if (logger) \
        { \
            logger->error(__VA_ARGS__); \
        } \
    } while (false)

#define AXIOM_CORE_CRITICAL(...) \
    do \
    { \
        auto& logger = ::Log::GetCoreLogger(); \
        if (logger) \
        { \
            logger->critical(__VA_ARGS__); \
        } \
    } while (false)

#define AXIOM_TRACE(...) \
    do \
    { \
        auto& logger = ::Log::GetClientLogger(); \
        if (logger) \
        { \
            logger->trace(__VA_ARGS__); \
        } \
    } while (false)

#define AXIOM_INFO(...) \
    do \
    { \
        auto& logger = ::Log::GetClientLogger(); \
        if (logger) \
        { \
            logger->info(__VA_ARGS__); \
        } \
    } while (false)

#define AXIOM_WARN(...) \
    do \
    { \
        auto& logger = ::Log::GetClientLogger(); \
        if (logger) \
        { \
            logger->warn(__VA_ARGS__); \
        } \
    } while (false)

#define AXIOM_ERROR(...) \
    do \
    { \
        auto& logger = ::Log::GetClientLogger(); \
        if (logger) \
        { \
            logger->error(__VA_ARGS__); \
        } \
    } while (false)

#define AXIOM_CRITICAL(...) \
    do \
    { \
        auto& logger = ::Log::GetClientLogger(); \
        if (logger) \
        { \
            logger->critical(__VA_ARGS__); \
        } \
    } while (false)
