/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 vec4.hpp

 2021-10-19 15:41:50

*/
#ifndef VEC4_HPP_20211019154150
#define VEC4_HPP_20211019154150

#include "vec.hpp"
#include "simd/vec4.hpp"

namespace cgl{
namespace glm{

#define GLM_VEC4_OPERATION(op)\
    template<typename X>\
    this_type operator op(const X& value)const\
    {\
        return this_type(x op value, y op value, z op value, w op value);\
    }\
    template<typename X>\
    this_type operator op(const vec<2, T>& v)const\
    {\
        return this_type(x op v.x, y op v.y, z, w);\
    }\
    template<typename X>\
    this_type operator op(const vec<3, X>& v)const\
    {\
        return this_type(x op v.x, y op v.y, z op v.z, w);\
    }\
    template<typename X>\
    this_type operator op(const vec<4, X>& v)const\
    {\
        return this_type(x op v.x, y op v.y, z op v.z, w op v.w);\
    }\
    template<typename X>\
    this_type& operator op##=(const X& value)\
    {\
        x op##= value; y op##= value; z op##= value; w op##= value;\
        return *this;\
    }\
    template<typename X>\
    this_type& operator op##=(const vec<2, T>& v)\
    {\
        x op##= v.x; y op##= v.y;\
        return *this;\
    }\
    template<typename X>\
    this_type& operator op##=(const vec<3, X>& v)\
    {\
        x op##= v.x; y op##= v.y; z op##= v.z;\
        return *this;\
    }\
    template<typename X>\
    this_type& operator op##=(const vec<4, X>& v)\
    {\
        x op##= v.x; y op##= v.y; z op##= v.z; w op##= v.w;\
        return *this;\
    }

#define GLM_VEC4_OPERATOR_COMMON(op)\
    template<typename T>\
    vec<4, T> operator op (T n, const vec<4, T>& v)\
    {\
        return vec<4, T>(n op v.x, n op v.y, n op v.z, n op v.w);\
    }


template<typename T>
class vec<4, T>
{
public:
    GLM_CLASS_TYPEDEF(T);

    typedef vec<4, T> this_type;

    enum { ELEMENTS = 4 };

    union {
        value_type m[ELEMENTS];
        struct{
            union { value_type x, r, red, s; };
            union { value_type y, g, green, t; };
            union { value_type z, b, blue, p, width; };
            union { value_type w, a, alpha, q, height; };
        };
    };

public:
    vec<4, T>() : x(), y(), z(), w() { /*void*/ }

    vec<4, T>(const_refrence scalar) : x(scalar), y(scalar), z(scalar), w(scalar) { /*void*/ }
    vec<4, T>(const_refrence vx, const_refrence vy, const_refrence vz, const_refrence vw) :
        x(vx), y(vy), z(vz), w(vw) { /*void*/ }

    vec<4, T>(const this_type& v) :
        x(v.x), y(v.y), z(v.z), w(v.w) { /*void*/ }

    template<typename X>
    vec<4, T>(const vec<2, X>& v, const_refrence vz = value_type(), const_refrence vw = value_type()) :
        x(v.x), y(v.y), z(vz), w(vw) { /*void*/ }

    template<typename X>
    vec<4, T>(const vec<2, X>& v1, const vec<2, X>& v2) :
        x(v1.x), y(v1.y), z(v2.x), w(v2.y) { /*void*/ }

    template<typename X>
    vec<4, T>(const vec<3, X>& v, const_refrence vw = value_type()) :
        x(v.x), y(v.y), z(v.z), w(vw) { /*void*/ }

    template<typename X>
    vec<4, T>(const vec<4, X>& v) :
        x(v.x), y(v.y), z(v.z), w(v.w) { /*void*/ }

    length_t length()const { return ELEMENTS; }

    refrence operator[](size_t i) { return m[i]; }
    const_refrence operator[](size_t i)const { return m[i]; }

    pointer data() { return m; }
    const_pointer data()const { return m; }

    GLM_VEC4_OPERATION(+);
    GLM_VEC4_OPERATION(-);
    GLM_VEC4_OPERATION(*);
    GLM_VEC4_OPERATION(/);

    this_type operator-()const
    {
        return this_type(-x, -y, -z, -w);
    }
};

GLM_VEC4_OPERATOR_COMMON(+);
GLM_VEC4_OPERATOR_COMMON(-);
GLM_VEC4_OPERATOR_COMMON(*);
GLM_VEC4_OPERATOR_COMMON(/);

#undef GLM_VEC4_OPERATION
#undef GLM_VEC4_OPERATOR_COMMON

}// end namespace glm
}// end namespace cgl

#endif// VEC4_HPP_20211019154150
