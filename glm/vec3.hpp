/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 vec3.hpp

 2021-10-19 15:41:38

*/
#ifndef GLM_VEC3_HPP_20211019154138
#define GLM_VEC3_HPP_20211019154138

#include "vector.hpp"



namespace glm{

#define GLM_VEC3_OPERATION(op)\
    template<typename X>\
    this_type operator op(const X& value)const\
    {\
        return this_type(x op value, y op value, z op value);\
    }\
    template<typename X>\
    this_type operator op(const vec<2, X>& v)const\
    {\
        return this_type(x op v.x, y op v.y, z);\
    }\
    template<typename X>\
    this_type operator op(const vec<3, X>& v)const\
    {\
        return this_type(x op v.x, y op v.y, z op v.z);\
    }\
    template<typename X>\
    this_type operator op(const vec<4, X>& v)const\
    {\
        return this_type(x op v.x, y op v.y, z op v.z);\
    }\
    template<typename X>\
    this_type& operator op##=(const X& value)\
    {\
        x op##= value; y op##= value; z op##= value;\
        return *this;\
    }\
    template<typename X>\
    this_type& operator op##=(const vec<2, X>& v)\
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
        x op##= v.x; y op##= v.y; z op##= v.z;\
        return *this;\
    }

#define GLM_VEC3_OPERATOR_COMMON(op)\
    template<typename T>\
    vec<3, T> operator op (T n, const vec<3, T>& v)\
    {\
        return vec<3, T>(n op v.x, n op v.y, n op v.z);\
    }


template<typename T>
class vec<3, T>
{
public:
    GLM_CLASS_TYPEDEF(T);

    typedef vec<3, T> this_type;

    enum { ELEMENTS = 3 };

    union {
        value_type m[ELEMENTS];
        struct{
            union { value_type x, r, red, u, s; };
            union { value_type y, g, green, v, t; };
            union { value_type z, b, blue; };
        };
    };

public:
    vec<3, T>() : x(), y(), z() { /*void*/ }
    vec<3, T>(const_reference scalar) : x(scalar), y(scalar), z(scalar) { /*void*/ }
    vec<3, T>(const_reference vx, const_reference vy, const_reference vz) :
        x(vx), y(vy), z(vz) { /*void*/ }

    template<typename X>
    vec<3, T>(const vec<2, X>& v, const_reference vz = value_type()) :
        x(v.x), y(v.y), z(vz) { /*void*/ }

    template<typename X>
    vec<3, T>(const vec<3, X>& v) :
        x(v.x), y(v.y), z(v.z) { /*void*/ }

    template<typename X>
    vec<3, T>(const vec<4, X>& v) :
        x(v.x), y(v.y), z(v.z) { /*void*/ }

    length_t length()const { return ELEMENTS; }

    reference operator[](size_t i) { return m[i]; }
    const_reference operator[](size_t i)const { return m[i]; }

    pointer data() { return m; }
    const_pointer data()const { return m; }

    // operator
    GLM_VEC3_OPERATION(+);
    GLM_VEC3_OPERATION(-);
    GLM_VEC3_OPERATION(*);
    GLM_VEC3_OPERATION(/);

    this_type operator-()const
    {
        return this_type(-x, -y, -z);
    }
};

GLM_VEC3_OPERATOR_COMMON(+);
GLM_VEC3_OPERATOR_COMMON(-);
GLM_VEC3_OPERATOR_COMMON(*);
GLM_VEC3_OPERATOR_COMMON(/);

#undef CGL_VEC3_OPERATION
#undef GLM_VEC3_OPERATOR_COMMON

}// end namespace glm

#endif// GLM_VEC3_HPP_20211019154138
