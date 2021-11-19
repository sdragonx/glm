/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 simd.hpp

 2021-11-18 18:29:20

*/
#ifndef GLM_SIMD_HPP_20211118182920
#define GLM_SIMD_HPP_20211118182920

#include "../detail/setup.hpp"

#define GLM_ENABLE_INSTRUCTIONS

#if defined(__SSE2__)

    #define GLM_HAVE_INSTRUCTIONS
    #include <xmmintrin.h>

#elif defined(GLM_PLATFORM_CBUILDER) || (defined(GLM_PLATFORM_MSVC) && defined(GLM_PLATFORM_X86))

    #define GLM_HAVE_INLINE_INSTRUCTIONS

#endif

#endif// GLM_SIMD_HPP_20211118182920
