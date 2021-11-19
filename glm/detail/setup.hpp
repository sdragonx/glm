/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 setup.hpp

 2021-11-15 22:13:55

*/
#ifndef GLM_SETUP_HPP_20211115221355
#define GLM_SETUP_HPP_20211115221355

#include <algorithm>
#include <cmath>
#include <limits>

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
// types
//

#ifndef GLM_CLASS_TYPEDEF

#define GLM_CLASS_TYPEDEF(T)\
    typedef T value_type;\
    typedef value_type* pointer;\
    typedef const value_type* const_pointer;\
    typedef value_type& refrence;\
    typedef const value_type& const_refrence;\

#endif

#define GLM_API inline
#define GLM_INS_API static

namespace cgl{
namespace glm{

typedef size_t length_t;

template<length_t N, typename T> class vec;
template<length_t CX, length_t CY, typename T> class mat;

}// end namespace glm
}// end namespace cgl

#endif// GLM_SETUP_HPP_20211115221355
