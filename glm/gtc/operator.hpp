/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 opeartor.hpp

 2022-01-11 15:54:46

*/
#ifndef GLM_OPEARTOR_HPP_20220111155446
#define GLM_OPEARTOR_HPP_20220111155446

#include "../detail/functional.hpp"
#include "../detail/logical.hpp"

namespace glm{

template<size_t N, typename T>
GLM_API bool operator == (const vec<N, T>& x, const vec<N, T>& y)
{
    return compare(equal<T>, x, y);
}

template<size_t N, typename T>
GLM_API bool operator != (const vec<N, T>& x, const vec<N, T>& y)
{
    return !compare(equal<T>, x, y);
}

}// end namespace glm

#endif// GLM_OPEARTOR_HPP_20220111155446
