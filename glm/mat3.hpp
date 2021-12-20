/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 mat3.hpp

 2019-05-30 02:06:08

*/
#ifndef GLM_MAT3_HPP_20190530020608
#define GLM_MAT3_HPP_20190530020608

#include "mat.hpp"



namespace glm{

//
// void mat3_add( in mat3, in T, out mat3 )
//

template<typename T>
GLM_API void mat3_add(const T* m, T scalar, T* dest)
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
}

//
// void mat3_add( in mat3, in mat3, out mat3 )
//

template<typename T>
GLM_API void mat3_add(const T* m1, const T* m2, T* dest)
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
}

//
// void mat3_sub( in mat3, in mat3, out mat3 )
//

template<typename T>
GLM_API void mat3_sub(const T* m1, const T* m2, T* dest)
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
}

//
// void mat3_mul( in mat3, in T, out mat3 )
//

template<typename T>
GLM_API void mat3_mul(const T* m, T scalar, T* dest)
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
}

//
// void mat3_mul( in mat3, in mat3, out mat3 )
//

template<typename T>
GLM_API void mat3_mul(const T* m1, const T* m2, T* dest)
{
    T product[9];

    product[0]  = m1[0] * m2[0]  + m1[3] * m2[1] + m1[6] * m2[2];
    product[1]  = m1[1] * m2[0]  + m1[4] * m2[1] + m1[7] * m2[2];
    product[2]  = m1[2] * m2[0]  + m1[5] * m2[1] + m1[8] * m2[2];

    product[3]  = m1[0] * m2[3]  + m1[3] * m2[4] + m1[6] * m2[5];
    product[4]  = m1[1] * m2[3]  + m1[4] * m2[4] + m1[7] * m2[5];
    product[5]  = m1[2] * m2[3]  + m1[5] * m2[4] + m1[8] * m2[5];

    product[6]  = m1[0] * m2[6]  + m1[3] * m2[7] + m1[6] * m2[8];
    product[7]  = m1[1] * m2[6]  + m1[4] * m2[7] + m1[7] * m2[8];
    product[8]  = m1[2] * m2[6]  + m1[5] * m2[7] + m1[8] * m2[8];

    memcpy(dest, product, sizeof(product));
}


//
// void mat3_transpose( inout mat3 )
//

template<typename T>
GLM_API void mat3_transpose(T* m)
{
    std::swap(m[1], m[3]);
    std::swap(m[2], m[6]);
    std::swap(m[5], m[7]);
}

//
// void mat3_transpose( in mat3, out mat3 )
//

template<typename T>
GLM_API void mat3_transpose(const T* m, T* dest)
{
    T product[9] = {
        m[0], m[3], m[6],
        m[1], m[4], m[7],
        m[2], m[5], m[8]
    };

    memcpy(dest, product, sizeof(product));
}

//
// void mat3_transpose_copy( in mat3, out mat3 )
//

template<typename T>
GLM_API void mat3_transpose_copy(const T* m, T* dest)
{
    assert(m != dest);
    dest[0] = m[0];  dest[1] = m[3];  dest[2] = m[6];
    dest[3] = m[1];  dest[4] = m[4];  dest[5] = m[7];
    dest[6] = m[2];  dest[7] = m[5];  dest[8] = m[8];
}

//
// bool mat3_determinant( in mat3, out T )
//

template<typename T>
GLM_API bool mat3_determinant(const T* m, T& d)
{
    d = m[0][0] * m[1][1] * m[2][2] -
        m[0][0] * m[1][2] * m[2][1] - 
        m[0][1] * m[1][0] * m[2][2] + 
        m[0][1] * m[1][2] * m[0][2] +
        m[0][2] * m[1][0] * m[2][1] -
        m[0][2] * m[1][1] * m[2][0];

    if (abs(d) < constants<T>::epsilon) {
        return false;
    }

    d = constants<T>::one / d;

    return true;
}

//
// bool mat3_inverse( in mat3, out mat3 )
//

template<typename T>
GLM_API bool mat3_inverse(const T* m, T* dest)
{
    T product[9];
    T d;

    if (mat3_determinant(m, d) == false) {
        return false;
    }

    product[0] =  m[8] * m[4] - m[7] * m[5];
    product[1] = -m[8] * m[2] - m[7] * m[2];
    product[2] =  m[5] * m[2] - m[4] * m[2];
    product[3] = -m[8] * m[3] - m[6] * m[5];
    product[4] =  m[8] * m[0] - m[6] * m[2];
    product[5] = -m[5] * m[0] - m[3] * m[2];
    product[6] =  m[7] * m[3] - m[6] * m[4];
    product[7] = -m[7] * m[0] - m[6] * m[1];
    product[8] =  m[4] * m[0] - m[3] * m[1];

    mat3_mul(product, d, dest);

    return true;
}

//
// void mat3_transform( in mat3, in vec3, out vec3 )
//

template<typename T>
GLM_API void mat3_transform(const T* m, const T* v, T* dest)
{
    T product[3];

    product[0] = m[0] * v[0] + m[3] * v[1] + m[6] * v[2];
    product[1] = m[1] * v[0] + m[4] * v[1] + m[7] * v[2];
    product[2] = m[2] * v[0] + m[5] * v[1] + m[8] * v[2];

    memcpy(dest, product, sizeof(product));
}

//
// class mat<3, 3, T>
//

template<typename T>
class mat<3, 3, T>
{
public:
    GLM_CLASS_TYPEDEF(T);

    typedef mat<3, 3, T> this_type;
    typedef vec<3, T> row_type;

    enum{
        COLS = 3,
        ROWS = 3,
        ELEMENTS = 9
    };

public:
    row_type m[3];

public:
    mat()
    {
    }

    mat(value_type scalar)
    {
        const T zero = constants<T>::zero;
        m[0] = row_type(scalar, zero, zero);
        m[1] = row_type(zero, scalar, zero);
        m[2] = row_type(zero, zero, scalar);
    }

    mat(const row_type& a, const row_type& b, const row_type& c)
    {
        m[0] = a;
        m[1] = b;
        m[2] = c;
    }

    mat(
        value_type m00, value_type m01, value_type m02,
        value_type m10, value_type m11, value_type m12,
        value_type m20, value_type m21, value_type m22)
    {
        m[0] = row_type(m00, m01, m02);
        m[1] = row_type(m10, m11, m12);
        m[2] = row_type(m20, m21, m22);
    }

    mat(const mat<3, 3, T>& other)
    {
        memcpy(data(), other.data(), sizeof(value_type) * ELEMENTS);
    }

    mat(const mat<4, 4, T>& other)
    {
        m[0] = row_type(other[0]);
        m[1] = row_type(other[1]);
        m[2] = row_type(other[2]);
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
GLM_API mat<3, 3, T> operator +(const mat<3, 3, T>& m, T n)
{
    mat<3, 3, T> product;
    mat3_add(m.data(), n, product.data());
    return product;
}

template<typename T>
GLM_API mat<3, 3, T> operator +(const mat<3, 3, T>& m1, const mat<3, 3, T>& m2)
{
    mat<3, 3, T> product;
    mat3_add(m1.data(), m2.data(), product.data());
    return product;
}

template<typename T>
GLM_API mat<3, 3, T> operator -(const mat<3, 3, T>& m, T n)
{
    mat<3, 3, T> product;
    mat3_mul(m.data(), -n, product.data());
    return product;
}

template<typename T>
GLM_API mat<3, 3, T> operator -(const mat<3, 3, T>& m1, const mat<3, 3, T>& m2)
{
    mat<3, 3, T> product;
    mat3_sub(m1.data(), m2.data(), product.data());
    return product;
}

template<typename T>
GLM_API mat<3, 3, T> operator *(const mat<3, 3, T>& m, T n)
{
    mat<3, 3, T> product;
    mat3_mul(m.data(), n, product.data());
    return product;
}

template<typename T>
GLM_API mat<3, 3, T> operator *(const mat<3, 3, T>& m1, const mat<3, 3, T>& m2)
{
    mat<3, 3, T> product;
    mat3_mul(m1.data(), m2.data(), product.data());
    return product;
}

template<typename T>
GLM_API mat<3, 3, T> operator /(const mat<3, 3, T>& m, T n)
{
    mat<3, 3, T> product;
    mat3_mul(m.data(), constants<T>::one / n, product.data());
    return product;
}

// transform
template<typename T>
GLM_API vec<3, T> operator *(const mat<3, 3, T>& m, const vec<3, T>& v)
{
    vec<3, T> product;
    mat3_transform(m.data(), v.data(), product.data());
    return product;
}

//
// mat3 transpose( in mat3 )
//

template<typename T>
GLM_API mat<3, 3, T> transpose(const mat<3, 3, T>& m)
{
    mat<3, 3, T> product;
    mat3_transpose_copy(m.data(), product.data());
    return product;
}

//
// mat3 inverse( in mat3 )
//

template<typename T>
GLM_API mat<3, 3, T> inverse(const mat<3, 3, T>& m)
{
    mat<3, 3, T> product;
    mat3_inverse(m.data(), product.data());
    return product;
}

}// end namespace glm

#endif// GLM_MAT3_HPP_20190530020608
