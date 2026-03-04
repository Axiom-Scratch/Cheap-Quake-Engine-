#pragma once

#include <iostream>

#if defined(_WIN32) || defined(_WIN64)
#define AXIOM_PLATFORM_WINDOWS
#elif defined(__linux__)
#define AXIOM_PLATFORM_LINUX
#elif defined(__APPLE__)
#define AXIOM_PLATFORM_MAC
#else
#error Unsupported platform
#endif

#ifdef AXIOM_PLATFORM_WINDOWS
#ifdef AXIOM_BUILD_DLL
#define AXIOM_API __declspec(dllexport)
#else
#define AXIOM_API __declspec(dllimport)
#endif
#else
#define AXIOM_API
#endif

#if defined(_DEBUG) || defined(DEBUG)
#define AXIOM_DEBUG
#endif

#if defined(AXIOM_PLATFORM_WINDOWS)
#define AXIOM_DEBUGBREAK() __debugbreak()
#elif defined(AXIOM_PLATFORM_LINUX) || defined(AXIOM_PLATFORM_MAC)
#include <csignal>
#define AXIOM_DEBUGBREAK() raise(SIGTRAP)
#else
#define AXIOM_DEBUGBREAK()
#endif

#ifdef AXIOM_DEBUG
#define AXIOM_ASSERT(x, msg) \
    do                       \
    {                        \
        if (!(x))            \
        {                    \
            std::cerr << msg << std::endl; \
            AXIOM_DEBUGBREAK();            \
        }                    \
    } while (false)
#else
#define AXIOM_ASSERT(x, msg) do { (void)(x); (void)(msg); } while (false)
#endif

#define BIT(x) (1u << (x))

#if defined(_MSC_VER)
#define AXIOM_FORCE_INLINE __forceinline
#else
#define AXIOM_FORCE_INLINE inline __attribute__((always_inline))
#endif
