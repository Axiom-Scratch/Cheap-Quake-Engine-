#pragma once

#include "Compiler.h"
#include "Platform.h"

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
#elif defined(AXIOM_PLATFORM_LINUX)
#include <signal.h>
#define AXIOM_DEBUGBREAK() raise(SIGTRAP)
#else
#define AXIOM_DEBUGBREAK()
#endif

#ifdef AXIOM_DEBUG
#include <iostream>
#define AXIOM_ASSERT(x, msg) if (!(x)) { std::cerr << msg << std::endl; AXIOM_DEBUGBREAK(); }
#else
#define AXIOM_ASSERT(x, msg)
#endif

#if defined(AXIOM_COMPILER_MSVC)
#define AXIOM_FORCE_INLINE __forceinline
#else
#define AXIOM_FORCE_INLINE inline __attribute__((always_inline))
#endif

#define BIT(x) (1 << x)
