/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 setup.hpp

 2021-11-15 22:13:55

*/
#ifndef GLM_SETUP_HPP_20211115221355
#define GLM_SETUP_HPP_20211115221355

#if defined(min) || defined(max)
    #if defined(_INC_WINDOWS)
        #pragma message define NOMINMAX before include <windows.h>
    #endif
#endif

#if defined(min)
    #undef min
#endif

#if defined(max)
    #undef max
#endif

#include <algorithm>
#include <cmath>
#include <float.h>
#include <limits>

#if defined(_MSC_VER)
    #if (_MSC_VER < 1300)
        typedef signed char int8_t;
        typedef unsigned char uint8_t;
        typedef signed short int16_t;
        typedef unsigned short uint16_t;
        typedef signed int int32_t;
        typedef unsigned int uint32_t;
        typedef signed long long int64_t;
        typedef unsigned long long uint64_t;

        typedef uint16_t uint_least16_t;
        typedef uint32_t uint_least32_t;
    }
    #elif (_MSC_VER < 1600)
        typedef signed __int8 int8_t;
        typedef unsigned __int8 uint8_t;
        typedef signed __int16 int16_t;
        typedef unsigned __int16 uint16_t;
        typedef signed __int32 int32_t;
        typedef unsigned __int32 uint32_t;
        typedef signed long long int64_t;
        typedef unsigned long long uint64_t;

        typedef uint16_t uint_least16_t;
        typedef uint32_t uint_least32_t;
    #else
        #include <stdint.h>
    #endif
#else
    #include <stdint.h>
#endif

#define GLM_VERSION_MAJOR           0
#define GLM_VERSION_MINOR           4
#define GLM_VERSION_PATCH           0
#define GLM_VERSION_REVISION        0
#define GLM_VERSION                 (GLM_VERSION_MAJOR * 1000 + GLM_VERSION_MINOR * 100 + GLM_VERSION_PATCH * 10 + GLM_VERSION_REVISION)
#define GLM_VERSION_MESSAGE         "GLM: version 0.4.0.0 (c++98)"

#define GLM_SETUP_INCLUDED          GLM_VERSION

///////////////////////////////////////////////////////////////////////////////////
// Active states

#define GLM_DISABLE     0
#define GLM_ENABLE      1

//
// platform
//

#if defined(_M_X64) || defined(_M_IA64) || defined(__x86_64__) || defined(__x86_64) ||\
    defined(_M_AMD64) || defined(__amd64__) || defined(__amd64)
    #define GLM_PLATFORM_X64
#else
    #define GLM_PLATFORM_X86
#endif

//
// compiler
//

#if defined(_MSC_VER)
    #define GLM_PLATFORM_MSVC
#elif defined(__BORLANDC__)
    #define GLM_PLATFORM_CBUILDER
#elif defined(__GNUC__)
    #define GLM_PLATFORM_GNUC
#else
    #define GLM_PLATFORM_UNKNOWN
#endif

//
// cpp11 check
//

#ifndef __has_feature
    #define __has_feature(x) 0 // Compatibility with non-clang compilers.
#endif

// Any compiler claiming C++11 supports, Visual C++ 2015 and Clang version supporting constexpr
#if ((__cplusplus >= 201103L) || (_MSC_VER >= 1900) || (__has_feature(cxx_constexpr))) // C++ 11 implementation
    #define GLM_NATIVE_CPP11_SUPPORT
    #define GLM_NATIVE_CPP11_TYPES_SUPPORT
#endif

#if !defined(GLM_NATIVE_CPP11_TYPES_SUPPORT)
    #if (__cplusplus > 199711L) || defined(__CODEGEARC__) || defined(__GXX_EXPERIMENTAL_CXX0X__) || \
        defined(__cpp_unicode_characters) || __has_feature(cxx_unicode_literals)
        #define GLM_NATIVE_CPP11_TYPES_SUPPORT
    #endif
#endif

#if ((!defined(_MSC_VER) || _MSC_VER < 1600) && !defined(GLM_NATIVE_CPP11_TYPES_SUPPORT)) || (defined(__CODEGEARC__) && !(defined(__clang__)))
    #define GLM_IMPLEMENTS_NULLPTR_SUPPORT
#else
    #define GLM_NATIVE_NULLPTR_SUPPORT
#endif

#if (_MSC_VER >= 1600)
    #ifndef GLM_NATIVE_CPP11_TYPES_SUPPORT
        #define GLM_NATIVE_CPP11_TYPES_SUPPORT
    #endif
#endif

//
// types
//

#ifndef GLM_CLASS_TYPEDEF

#define GLM_CLASS_TYPEDEF(T)\
    typedef T value_type;\
    typedef value_type* pointer;\
    typedef const value_type* const_pointer;\
    typedef value_type& reference;\
    typedef const value_type& const_reference

#endif

#define GLM_API inline
#define GLM_INS_API static

#ifdef GLM_FORCE_EXPLICIT_CTOR
    #define GLM_EXPLICIT explicit
#else
    #define GLM_EXPLICIT
#endif

namespace glm {

// int type
typedef int8_t int8;
typedef uint8_t uint8;
typedef int16_t int16;
typedef uint16_t uint16;
typedef int32_t int32;
typedef uint32_t uint32;
typedef int64_t int64;
typedef uint64_t uint64;

// size type
typedef size_t length_t;

// object type
template<length_t N, typename T> class vec;
template<length_t CX, length_t CY, typename T> class mat;

}// end namespace glm

#endif// GLM_SETUP_HPP_20211115221355
