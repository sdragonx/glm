/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 simd_mat4.hpp

 2021-11-18 17:28:23

*/
#ifndef GLM_SIMD_MAT4_HPP_20211118172823
#define GLM_SIMD_MAT4_HPP_20211118172823

#include "simd.hpp"

namespace cgl{
namespace glm{

//
// INSTRUCTIONS
//

#if defined(GLM_ENABLE_INSTRUCTIONS)
#if defined(GLM_HAVE_INSTRUCTIONS)

GLM_INS_API void mat4_mul(const float* m1, const float* m2, float* dest)
{
    __m128 a1 = _mm_loadu_ps(m1 + 0);
    __m128 a2 = _mm_loadu_ps(m1 + 4);
    __m128 a3 = _mm_loadu_ps(m1 + 8);
    __m128 a4 = _mm_loadu_ps(m1 + 12);

    __m128 b1, b2, b3, b4;

    for(int i = 0; i < 4; ++i) {
        b1 = _mm_set_ps1(m2[0]);
        b2 = _mm_set_ps1(m2[1]);
        b3 = _mm_set_ps1(m2[2]);
        b4 = _mm_set_ps1(m2[3]);

        ((__m128*)dest)[i] = _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(a1, b1), _mm_mul_ps(a2, b2)), 
            _mm_add_ps(_mm_mul_ps(a3, b3), _mm_mul_ps(a4, b4)));

        m2 += 4;
    }
}

GLM_INS_API void mat4_transform(const float* m1, const float* m2, float* dest)
{
    __m128 a1 = _mm_loadu_ps(m1 + 0);
    __m128 a2 = _mm_loadu_ps(m1 + 4);
    __m128 a3 = _mm_loadu_ps(m1 + 8);
    __m128 a4 = _mm_loadu_ps(m1 + 12);

    __m128 b1 = _mm_set_ps1(m2[0]);
    __m128 b2 = _mm_set_ps1(m2[1]);
    __m128 b3 = _mm_set_ps1(m2[2]);
    __m128 b4 = _mm_set_ps1(m2[3]);

    *((__m128*)dest) = _mm_add_ps(
        _mm_add_ps(_mm_mul_ps(a1, b1), _mm_mul_ps(a2, b2)), 
        _mm_add_ps(_mm_mul_ps(a3, b3), _mm_mul_ps(a4, b4)));
}

#elif defined(GLM_HAVE_INLINE_INSTRUCTIONS)

GLM_INS_API void mat4_mul(const float* m1, const float* m2, float* dest)
{
    __asm{
        mov eax, m1
        mov ebx, m2
        mov ecx, 4
        mov edx, dest
        movups xmm0, [eax]
        movups xmm1, [eax + 16]
        movups xmm2, [eax + 32]
        movups xmm3, [eax + 48]

        ROW_LOOP:               // 处理 m2 一行

        movss xmm4, [ebx + 0]   // 读取 x
        shufps xmm4, xmm4, 0    // 展开 xmm = n, n, n, n
        mulps xmm4, xmm0        // 乘以源矩阵行

        movss xmm5, [ebx + 4]   // 读取 y
        shufps xmm5, xmm5, 0
        mulps xmm5, xmm1

        movss xmm6, [ebx + 8]   // 读取 z
        shufps xmm6, xmm6, 0
        mulps xmm6, xmm2

        movss xmm7, [ebx + 12]  // 读取 w
        shufps xmm7, xmm7, 0
        mulps xmm7, xmm3
        
        addps xmm4, xmm5        // 所有结果相加
        addps xmm4, xmm6
        addps xmm4, xmm7

        movups [edx], xmm4

        add ebx, 16             // 循环
        add edx, 16
        loop ROW_LOOP
    }
}

GLM_INS_API void mat4_transform(const float* m, const float* v, float* dest)
{
    __asm {
        mov eax, m
        mov ebx, v
        mov edx, dest
        movups xmm0, [eax]
        movups xmm1, [eax + 16]
        movups xmm2, [eax + 32]
        movups xmm3, [eax + 48]

        movss xmm4, [ebx + 0]   // 读取 x
        shufps xmm4, xmm4, 0    // 展开 xmm = n, n, n, n
        mulps xmm4, xmm0        // 乘以源矩阵行

        movss xmm5, [ebx + 4]   // 读取 y
        shufps xmm5, xmm5, 0
        mulps xmm5, xmm1

        movss xmm6, [ebx + 8]   // 读取 z
        shufps xmm6, xmm6, 0
        mulps xmm6, xmm2

        movss xmm7, [ebx + 12]  // 读取 w
        shufps xmm7, xmm7, 0
        mulps xmm7, xmm3
        
        addps xmm4, xmm5        // 所有结果相加
        addps xmm4, xmm6
        addps xmm4, xmm7

        movups [edx], xmm4
    }
}

#endif// GLM_HAVE_INSTRUCTIONS
#endif// GLM_ENABLE_INSTRUCTIONS

}// end namespace glm
}// end namespace cgl

#endif// GLM_SIMD_MAT4_HPP_20211118172823
