/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 simd_vec4.hpp

 2021-11-18 18:26:40

*/
#ifndef GLM_SIMD_VEC4_HPP_20211118182640
#define GLM_SIMD_VEC4_HPP_20211118182640

#include "simd.hpp"
#include "../vec.hpp"

namespace cgl{
namespace glm{

template<typename T>
vec<4, T> vec4_add(const vec<4, T>& v1, const vec<4, T>& v2)
{
    return vec<4, T>(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w);
}

template<typename T>
vec<4, T> vec4_mul(const vec<4, T>& v1, const vec<4, T>& v2)
{
    return vec<4, T>(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w);
}

#if defined(GLM_ENABLE_INSTRUCTIONS)
#if defined(GLM_HAVE_INSTRUCTIONS)

#elif defined(GLM_HAVE_INLINE_INSTRUCTIONS)

/*
// slowly
GLM_INS_API void vec4_add(const float* v1, const float* v2, float* dest)
{
    __asm
    {
        mov eax, v1
        mov ebx, v2
        mov ecx, dest;

        movups xmm0, [eax]
        movups xmm1, [ebx]
        addps  xmm0, xmm1
        movups [ecx], xmm0
    }
}

GLM_INS_API void vec4_mul(const float* v1, const float* v2, float* dest)
{
    __asm
    {
        mov eax, v1
        mov ebx, v2
        mov ecx, dest;

        movups xmm0, [eax]
        movups xmm1, [ebx]
        mulps  xmm0, xmm1
        movups [ecx], xmm0
    }
}

GLM_INS_API void vec4_mul(const float* v1, float n, float* dest)
{
    float v2[4] = { n, n, n, n };
    vec4_mul(v1, v2, dest);
}
*/

#endif// GLM_HAVE_INSTRUCTIONS
#endif// GLM_ENABLE_INSTRUCTIONS

}// end namespace glm
}// end namespace cgl

#endif// GLM_SIMD_VEC4_HPP_20211118182640
