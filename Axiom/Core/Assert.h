#pragma once

#include "Base.h"

#ifdef AXIOM_DEBUG
#include <iostream>
#define AXIOM_ASSERT(condition, message) \
    do                                   \
    {                                    \
        if (!(condition))                \
        {                                \
            std::cerr << "Assertion Failed: " << message << std::endl; \
            AXIOM_DEBUGBREAK();          \
        }                                \
    } while (false)

#define AXIOM_CORE_ASSERT(condition, message) AXIOM_ASSERT(condition, message)
#else
#define AXIOM_ASSERT(condition, message) do { (void)(condition); (void)(message); } while (false)
#define AXIOM_CORE_ASSERT(condition, message) do { (void)(condition); (void)(message); } while (false)
#endif
