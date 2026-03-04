#pragma once

#if defined(_MSC_VER)
#define AXIOM_COMPILER_MSVC
#elif defined(__clang__)
#define AXIOM_COMPILER_CLANG
#elif defined(__GNUC__)
#define AXIOM_COMPILER_GCC
#else
#error Unsupported compiler
#endif

#if defined(__x86_64__) || defined(_M_X64)
#define AXIOM_ARCH_X64
#elif defined(__i386) || defined(_M_IX86)
#define AXIOM_ARCH_X86
#elif defined(__arm__) || defined(__aarch64__)
#define AXIOM_ARCH_ARM
#endif
