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

}// end namespace glm

template<size_t N, typename T>
GLM_API bool operator == (const glm::vec<N, T>& x, const glm::vec<N, T>& y)
{
    return glm::compare(glm::equal<T>, x, y);
}

template<size_t N, typename T>
GLM_API bool operator != (const glm::vec<N, T>& x, const glm::vec<N, T>& y)
{
    return !glm::compare(glm::equal<T>, x, y);
}

#endif// GLM_OPEARTOR_HPP_20220111155446
