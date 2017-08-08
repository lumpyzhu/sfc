#pragma once

#include <stdlib.h>
#include <stdint.h>

#pragma region NMS_OS_X
#ifdef _WIN32
#define NMS_OS_WINDOWS      // check if os == windows
#endif

#ifdef __linux__
#define NMS_OS_LINUX        // check if os == linux
#endif

#ifdef __APPLE__
#define NMS_OS_MACOS        // check if os == macos

#endif

#if defined(__unix__) || defined(__linux__) || defined(__APPLE__)
#define NMS_OS_POSIX        // check if os == posix
#endif
#pragma endregion

#pragma region NMS_CC_X
#ifdef _MSC_VER
#   define NMS_CC_MSVC         // check if compiler == msvc
#   define __PRETTY_FUNCTION__ __FUNCSIG__
#   pragma warning(disable:6326)    // potential comparison of a constant with another constant
#else
#   define __forceinline inline __attribute__((always_inline))
#endif

#ifdef __GNUC__
#   define NMS_CC_GNUC         // check if compiler == gcc
#endif

#ifdef __clang__
#   define NMS_CC_CLANG        // check if compiler == clang
#endif
#pragma endregion

#pragma region NMS_API, NMS_ABI
#ifndef NMS_API
#   ifdef  NMS_CC_MSVC
#   ifdef  NMS_BUILD
#       define NMS_API __declspec(dllexport)
#   else
#       define NMS_API __declspec(dllimport)
#   endif
#else
#   define NMS_API
#endif
#endif

#ifndef NMS_ABI
#   define NMS_ABI extern "C" NMS_API
#endif
#pragma endregion
