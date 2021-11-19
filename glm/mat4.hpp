/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 mat4.hpp

 2018-04-15 19:45:04

*/
#ifndef GLM_MAT4_HPP_20180415194504
#define GLM_MAT4_HPP_20180415194504

#include "mat.hpp"
#include "simd/mat4.hpp"

namespace cgl{
namespace glm{

//
// void mat4_add( in mat4, in T, out mat4 )
//

template<typename T>
GLM_API void mat4_add(const T* m, T scalar, T* dest)
{
    dest[0]  = m[0]  + scalar;
    dest[1]  = m[1]  + scalar;
    dest[2]  = m[2]  + scalar;
    dest[3]  = m[3]  + scalar;
    dest[4]  = m[4]  + scalar;
    dest[5]  = m[5]  + scalar;
    dest[6]  = m[6]  + scalar;
    dest[7]  = m[7]  + scalar;
    dest[8]  = m[8]  + scalar;
    dest[9]  = m[9]  + scalar;
    dest[10] = m[10] + scalar;
    dest[11] = m[11] + scalar;
    dest[12] = m[12] + scalar;
    dest[13] = m[13] + scalar;
    dest[14] = m[14] + scalar;
    dest[15] = m[15] + scalar;
}

//
// void mat4_add( in mat4, in mat4, out mat4 )
//

template<typename T>
GLM_API void mat4_add(const T* m1, const T* m2, T* dest)
{
    dest[0]  = m1[0]  + m2[0];
    dest[1]  = m1[1]  + m2[1];
    dest[2]  = m1[2]  + m2[2];
    dest[3]  = m1[3]  + m2[3];
    dest[4]  = m1[4]  + m2[4];
    dest[5]  = m1[5]  + m2[5];
    dest[6]  = m1[6]  + m2[6];
    dest[7]  = m1[7]  + m2[7];
    dest[8]  = m1[8]  + m2[8];
    dest[9]  = m1[9]  + m2[9];
    dest[10] = m1[10] + m2[10];
    dest[11] = m1[11] + m2[11];
    dest[12] = m1[12] + m2[12];
    dest[13] = m1[13] + m2[13];
    dest[14] = m1[14] + m2[14];
    dest[15] = m1[15] + m2[15];
}

//
// void mat4_sub( in mat4, in mat4, out mat4 )
//

template<typename T>
GLM_API void mat4_sub(const T* m1, const T* m2, T* dest)
{
    dest[0]  = m1[0]  - m2[0];
    dest[1]  = m1[1]  - m2[1];
    dest[2]  = m1[2]  - m2[2];
    dest[3]  = m1[3]  - m2[3];
    dest[4]  = m1[4]  - m2[4];
    dest[5]  = m1[5]  - m2[5];
    dest[6]  = m1[6]  - m2[6];
    dest[7]  = m1[7]  - m2[7];
    dest[8]  = m1[8]  - m2[8];
    dest[9]  = m1[9]  - m2[9];
    dest[10] = m1[10] - m2[10];
    dest[11] = m1[11] - m2[11];
    dest[12] = m1[12] - m2[12];
    dest[13] = m1[13] - m2[13];
    dest[14] = m1[14] - m2[14];
    dest[15] = m1[15] - m2[15];
}

//
// void mat4_mul( in mat4, in T, out mat4 )
//

template<typename T>
GLM_API void mat4_mul(const T* m, T scalar, T* dest)
{
    dest[0]  = m[0]  * scalar;
    dest[1]  = m[1]  * scalar;
    dest[2]  = m[2]  * scalar;
    dest[3]  = m[3]  * scalar;
    dest[4]  = m[4]  * scalar;
    dest[5]  = m[5]  * scalar;
    dest[6]  = m[6]  * scalar;
    dest[7]  = m[7]  * scalar;
    dest[8]  = m[8]  * scalar;
    dest[9]  = m[9]  * scalar;
    dest[10] = m[10] * scalar;
    dest[11] = m[11] * scalar;
    dest[12] = m[12] * scalar;
    dest[13] = m[13] * scalar;
    dest[14] = m[14] * scalar;
    dest[15] = m[15] * scalar;
}

//
// void mat4_mul( in mat4, in mat4, out mat4 )
//

template<typename T>
GLM_API void mat4_mul(const T* m1, const T* m2, T* dest)
{
    T product[16];

    product[0]  = m1[0] * m2[0]  + m1[4] * m2[1]  + m1[8]  * m2[2]  + m1[12] * m2[3];
    product[1]  = m1[1] * m2[0]  + m1[5] * m2[1]  + m1[9]  * m2[2]  + m1[13] * m2[3];
    product[2]  = m1[2] * m2[0]  + m1[6] * m2[1]  + m1[10] * m2[2]  + m1[14] * m2[3];
    product[3]  = m1[3] * m2[0]  + m1[7] * m2[1]  + m1[11] * m2[2]  + m1[15] * m2[3];

    product[4]  = m1[0] * m2[4]  + m1[4] * m2[5]  + m1[8]  * m2[6]  + m1[12] * m2[7];
    product[5]  = m1[1] * m2[4]  + m1[5] * m2[5]  + m1[9]  * m2[6]  + m1[13] * m2[7];
    product[6]  = m1[2] * m2[4]  + m1[6] * m2[5]  + m1[10] * m2[6]  + m1[14] * m2[7];
    product[7]  = m1[3] * m2[4]  + m1[7] * m2[5]  + m1[11] * m2[6]  + m1[15] * m2[7];

    product[8]  = m1[0] * m2[8]  + m1[4] * m2[9]  + m1[8]  * m2[10] + m1[12] * m2[11];
    product[9]  = m1[1] * m2[8]  + m1[5] * m2[9]  + m1[9]  * m2[10] + m1[13] * m2[11];
    product[10] = m1[2] * m2[8]  + m1[6] * m2[9]  + m1[10] * m2[10] + m1[14] * m2[11];
    product[11] = m1[3] * m2[8]  + m1[7] * m2[9]  + m1[11] * m2[10] + m1[15] * m2[11];

    product[12] = m1[0] * m2[12] + m1[4] * m2[13] + m1[8]  * m2[14] + m1[12] * m2[15];
    product[13] = m1[1] * m2[12] + m1[5] * m2[13] + m1[9]  * m2[14] + m1[13] * m2[15];
    product[14] = m1[2] * m2[12] + m1[6] * m2[13] + m1[10] * m2[14] + m1[14] * m2[15];
    product[15] = m1[3] * m2[12] + m1[7] * m2[13] + m1[11] * m2[14] + m1[15] * m2[15];

    memcpy(dest, product, sizeof(product));
}

//
// void mat4_transpose( inout mat4 )
//

template<typename T>
GLM_API void mat4_transpose(T* m)
{
    std::swap(m[1], m[4]);
    std::swap(m[2], m[8]);
    std::swap(m[3], m[12]);
    std::swap(m[6], m[9]);
    std::swap(m[7], m[13]);
    std::swap(m[11], m[14]);
}

//
// void mat4_transpose( in mat4, out mat4 )
//

template<typename T>
GLM_API void mat4_transpose(const T* m, T* dest)
{
    T product[16] = {
        m[0], m[4], m[8], m[12],
        m[1], m[5], m[9], m[13],
        m[2], m[6], m[10], m[14],
        m[3], m[7], m[11], m[15]
    };

    memcpy(dest, product, sizeof(product));
}

//
// void mat4_transpose_copy( in mat4, out mat4 )
//

template<typename T>
GLM_API void mat4_transpose_copy(const T* m, T* dest)
{
    assert(m != dest);
    dest[0]  = m[0]; dest[1]  = m[4]; dest[2]  = m[8];  dest[3]  = m[12];
    dest[4]  = m[1]; dest[5]  = m[5]; dest[6]  = m[9];  dest[7]  = m[13];
    dest[8]  = m[2]; dest[9]  = m[6]; dest[10] = m[10]; dest[11] = m[14];
    dest[12] = m[3]; dest[13] = m[7]; dest[14] = m[11]; dest[15] = m[15];
}

//
// bool mat4_determinant( in mat4, out T )
//

template<typename T>
GLM_API bool mat4_determinant(const T* m, T& d)
{
    T a0 = m[0]  * m[5]  - m[1]  * m[4];
    T a1 = m[0]  * m[6]  - m[2]  * m[4];
    T a2 = m[0]  * m[7]  - m[3]  * m[4];
    T a3 = m[1]  * m[6]  - m[2]  * m[5];
    T a4 = m[1]  * m[7]  - m[3]  * m[5];
    T a5 = m[2]  * m[7]  - m[3]  * m[6];
    T b0 = m[8]  * m[13] - m[9]  * m[12];
    T b1 = m[8]  * m[14] - m[10] * m[12];
    T b2 = m[8]  * m[15] - m[11] * m[12];
    T b3 = m[9]  * m[14] - m[10] * m[13];
    T b4 = m[9]  * m[15] - m[11] * m[13];
    T b5 = m[10] * m[15] - m[11] * m[14];

    // Calculate the determinant.
    d = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;

    if (abs(d) < constants<T>::epsilon) {
        return false;
    }

    d = constants<T>::one / d;

    return true;
}

//
// bool mat4_inverse( in mat4, out mat4 )
//

template<typename T>
GLM_API bool mat4_inverse(const T* m, T* dest)
{
    T product[16];
    T d;

    T a0 = m[0]  * m[5]  - m[1]  * m[4];
    T a1 = m[0]  * m[6]  - m[2]  * m[4];
    T a2 = m[0]  * m[7]  - m[3]  * m[4];
    T a3 = m[1]  * m[6]  - m[2]  * m[5];
    T a4 = m[1]  * m[7]  - m[3]  * m[5];
    T a5 = m[2]  * m[7]  - m[3]  * m[6];
    T b0 = m[8]  * m[13] - m[9]  * m[12];
    T b1 = m[8]  * m[14] - m[10] * m[12];
    T b2 = m[8]  * m[15] - m[11] * m[12];
    T b3 = m[9]  * m[14] - m[10] * m[13];
    T b4 = m[9]  * m[15] - m[11] * m[13];
    T b5 = m[10] * m[15] - m[11] * m[14];

    // Calculate the determinant.
    d = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;

    if (abs(d) < constants<T>::epsilon) {
        return false;
    }

    d = constants<T>::one / d;

    if (mat4_determinant(m, d) == false) {
        return false;
    }

    product[0]  =  m[5]  * b5 - m[6]  * b4 + m[7]  * b3;
    product[1]  = -m[1]  * b5 + m[2]  * b4 - m[3]  * b3;
    product[2]  =  m[13] * a5 - m[14] * a4 + m[15] * a3;
    product[3]  = -m[9]  * a5 + m[10] * a4 - m[11] * a3;

    product[4]  = -m[4]  * b5 + m[6]  * b2 - m[7]  * b1;
    product[5]  =  m[0]  * b5 - m[2]  * b2 + m[3]  * b1;
    product[6]  = -m[12] * a5 + m[14] * a2 - m[15] * a1;
    product[7]  =  m[8]  * a5 - m[10] * a2 + m[11] * a1;

    product[8]  =  m[4]  * b4 - m[5]  * b2 + m[7]  * b0;
    product[9]  = -m[0]  * b4 + m[1]  * b2 - m[3]  * b0;
    product[10] =  m[12] * a4 - m[13] * a2 + m[15] * a0;
    product[11] = -m[8]  * a4 + m[9]  * a2 - m[11] * a0;

    product[12] = -m[4]  * b3 + m[5]  * b1 - m[6]  * b0;
    product[13] =  m[0]  * b3 - m[1]  * b1 + m[2]  * b0;
    product[14] = -m[12] * a3 + m[13] * a1 - m[14] * a0;
    product[15] =  m[8]  * a3 - m[9]  * a1 + m[10] * a0;

    mat4_mul(product, d, dest);

    return true;
}

//
// void mat4_transform( in mat4, in vec4, out vec4 )
//

template<typename T>
GLM_API void mat4_transform(const T* m, const T* v, T* dest)
{
    T product[4];

    product[0] = v[0] * m[0] + v[1] * m[4] + v[2] * m[8]  + v[3] * m[12];
    product[1] = v[0] * m[1] + v[1] * m[5] + v[2] * m[9]  + v[3] * m[13];
    product[2] = v[0] * m[2] + v[1] * m[6] + v[2] * m[10] + v[3] * m[14];
    product[3] = v[0] * m[3] + v[1] * m[7] + v[2] * m[11] + v[3] * m[15];

    memcpy(dest, product, sizeof(product));
}

//
// class mat<4, 4, T>
//

template<typename T>
class mat<4, 4, T> : public constants<T>
{
public:
    GLM_CLASS_TYPEDEF(T);

    typedef mat<4, 4, T> this_type;
    typedef vec<4, T> row_type;

    enum{
        COLS = 4,
        ROWS = 4,
        ELEMENTS = 16
    };

public:
    row_type m[ROWS];

public:
    mat()
    {
    }

    mat(value_type scalar)
    {
        const T zero = constants<T>::zero;
        m[0] = row_type(scalar, zero, zero, zero);
        m[1] = row_type(zero, scalar, zero, zero);
        m[2] = row_type(zero, zero, scalar, zero);
        m[3] = row_type(zero, zero, zero, scalar);
    }

    mat(const row_type& a, const row_type& b, const row_type& c, const row_type& d)
    {
        m[0] = a;
        m[1] = b;
        m[2] = c;
        m[3] = d;
    }

    mat(
        value_type m00, value_type m01, value_type m02, value_type m03,
        value_type m10, value_type m11, value_type m12, value_type m13,
        value_type m20, value_type m21, value_type m22, value_type m23,
        value_type m30, value_type m31, value_type m32, value_type m33)
    {
        m[0] = row_type(m00, m01, m02, m03);
        m[1] = row_type(m10, m11, m12, m13);
        m[2] = row_type(m20, m21, m22, m23);
        m[3] = row_type(m30, m31, m32, m33);
    }

    mat(const mat<3, 3, T>& other)
    {
        const T zero = constants<T>::zero;
        const T one = constants<T>::zero;

        m[0] = row_type(other[0], zero);
        m[1] = row_type(other[1], zero);
        m[2] = row_type(other[2], zero);
        m[3] = row_type(zero, zero, zero, one);
    }

    mat(const mat<4, 4, T>& other)
    {
        memcpy(data(), other.data(), sizeof(T) * ELEMENTS);
    }

    length_t length()const
    {
        return ELEMENTS;
    }

    pointer data()
    {
        return &m[0][0];
    }

    const_pointer data()const
    {
        return &m[0][0];
    }

    row_type& operator[](size_t i)
    {
        return m[i];
    }

    const row_type& operator[](size_t i)const
    {
        return m[i];
    }

    refrence operator()(size_t x, size_t y)
    {
        return m[y][x];
    }

    const_refrence operator()(size_t x, size_t y)const
    {
        return m[y][x];
    }
};

//
// operator
//

template<typename T>
GLM_API mat<4, 4, T> operator +(const mat<4, 4, T>& m, T n)
{
    mat<4, 4, T> product;
    mat4_add(m.data(), n, product.data());
    return product;
}

template<typename T>
GLM_API mat<4, 4, T> operator +(const mat<4, 4, T>& m1, const mat<4, 4, T>& m2)
{
    mat<4, 4, T> product;
    mat4_add(m1.data(), m2.data(), product.data());
    return product;
}

template<typename T>
GLM_API mat<4, 4, T> operator -(const mat<4, 4, T>& m, T n)
{
    mat<4, 4, T> product;
    mat4_mul(m.data(), -n, product.data());
    return product;
}

template<typename T>
GLM_API mat<4, 4, T> operator -(const mat<4, 4, T>& m1, const mat<4, 4, T>& m2)
{
    mat<4, 4, T> product;
    mat4_sub(m1.data(), m2.data(), product.data());
    return product;
}

template<typename T>
GLM_API mat<4, 4, T> operator *(const mat<4, 4, T>& m, T n)
{
    mat<4, 4, T> product;
    mat4_mul(m.data(), n, product.data());
    return product;
}

template<typename T>
GLM_API mat<4, 4, T> operator *(const mat<4, 4, T>& m1, const mat<4, 4, T>& m2)
{
    mat<4, 4, T> product;
    mat4_mul(m1.data(), m2.data(), product.data());
    return product;
}

template<typename T>
GLM_API mat<4, 4, T> operator /(const mat<4, 4, T>& m, T n)
{
    mat<4, 4, T> product;
    mat4_mul(m.data(), constants<T>::one / n, product.data());
    return product;
}

// transform
template<typename T>
GLM_API vec<4, T> operator *(const mat<4, 4, T>& m, const vec<4, T>& v)
{
    vec<4, T> product;
    mat4_transform(m.data(), v.data(), product.data());
    return product;
}

//
// mat4 transpose( in mat4 )
//

template<typename T>
GLM_API mat<4, 4, T> transpose(const mat<4, 4, T>& m)
{
    mat<4, 4, T> product;
    mat4_transpose_copy(m.data(), product.data());
    return product;
}

//
// T determinant( in mat4 )
//

template<typename T>
GLM_API T determinant(const mat<4, 4, T>& m)
{
    T d;
    if (mat4_determinant(m.data(), d)) {
        return d;
    }
    else {
        return T();
    }
}

//
// mat4 inverse( in mat4 )
//

template<typename T>
GLM_API mat<4, 4, T> inverse(const mat<4, 4, T>& m)
{
    mat<4, 4, T> product;
    mat4_inverse(m.data(), product.data());
    return product;
}



//
// extension
//

// 获得摄像机位置
template<typename T>
GLM_API glm::vec<4, T> viewPosition(const glm::mat<4, 4, T>& m)
{
    glm::vec<4, T> product;
    product.x = -(m[0][0] * m[3][0] + m[0][1] * m[3][1] + m[0][2] * m[3][2]);
    product.y = -(m[1][0] * m[3][0] + m[1][1] * m[3][1] + m[0][2] * m[3][2]);
    product.z = -(m[2][0] * m[3][0] + m[2][1] * m[3][1] + m[2][2] * m[3][2]);
    return product;
}

}// end namespace glm
}// end namespace cgl

#endif// GLM_MAT4_HPP_20180415194504
