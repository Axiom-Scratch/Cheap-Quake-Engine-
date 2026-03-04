#pragma once

#if defined(_WIN32) || defined(_WIN64)
#define AXIOM_PLATFORM_WINDOWS
#elif defined(__linux__)
#define AXIOM_PLATFORM_LINUX
#elif defined(__APPLE__)
#define AXIOM_PLATFORM_MAC
#elif defined(__ANDROID__)
#define AXIOM_PLATFORM_ANDROID
#else
#error Unsupported platform
#endif
