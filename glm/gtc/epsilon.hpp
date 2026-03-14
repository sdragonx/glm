/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 epsilon.hpp

 2026-03-14 02:32:00

*/
#ifndef GLM_EPSILON_HPP_20260314023200
#define GLM_EPSILON_HPP_20260314023200

#include "../geometric.hpp"
#include "../vector.hpp"
#include "../quat.hpp"



namespace glm {

/// Returns the component-wise comparison of |x - y| < epsilon.
/// True if this expression is satisfied.
///
/// @see gtc_epsilon
template<length_t L, typename T>
vec<L, bool> epsilonEqual(vec<L, T> const& x, vec<L, T> const& y, T const& epsilon);

/// Returns the component-wise comparison of |x - y| < epsilon.
/// True if this expression is satisfied.
///
/// @see gtc_epsilon
template<typename genType>
bool epsilonEqual(genType const& x, genType const& y, genType const& epsilon);

/// Returns the component-wise comparison of |x - y| < epsilon.
/// True if this expression is not satisfied.
///
/// @see gtc_epsilon
template<length_t L, typename T>
vec<L, bool> epsilonNotEqual(vec<L, T> const& x, vec<L, T> const& y, T const& epsilon);

/// Returns the component-wise comparison of |x - y| >= epsilon.
/// True if this expression is not satisfied.
///
/// @see gtc_epsilon
template<typename genType>
bool epsilonNotEqual(genType const& x, genType const& y, genType const& epsilon);

//
// implementation
//

template<>
GLM_API bool epsilonEqual
(
    float const& x,
    float const& y,
    float const& epsilon
)
{
    return abs(x - y) < epsilon;
}

template<>
GLM_API bool epsilonEqual
(
    double const& x,
    double const& y,
    double const& epsilon
)
{
    return abs(x - y) < epsilon;
}

template<length_t L, typename T>
GLM_API vec<L, bool> epsilonEqual(vec<L, T> const& x, vec<L, T> const& y, T const& epsilon)
{
    return lessThan(abs(x - y), vec<L, T>(epsilon));
}

template<length_t L, typename T>
GLM_API vec<L, bool> epsilonEqual(vec<L, T> const& x, vec<L, T> const& y, vec<L, T> const& epsilon)
{
    return lessThan(abs(x - y), vec<L, T>(epsilon));
}

template<>
GLM_API bool epsilonNotEqual(float const& x, float const& y, float const& epsilon)
{
    return abs(x - y) >= epsilon;
}

template<>
GLM_API bool epsilonNotEqual(double const& x, double const& y, double const& epsilon)
{
    return abs(x - y) >= epsilon;
}

template<length_t L, typename T>
GLM_API vec<L, bool> epsilonNotEqual(vec<L, T> const& x, vec<L, T> const& y, T const& epsilon)
{
    return greaterThanEqual(abs(x - y), vec<L, T>(epsilon));
}

template<length_t L, typename T>
GLM_API vec<L, bool> epsilonNotEqual(vec<L, T> const& x, vec<L, T> const& y, vec<L, T> const& epsilon)
{
    return greaterThanEqual(abs(x - y), vec<L, T>(epsilon));
}

template<typename T>
GLM_API vec<4, bool> epsilonEqual(qua<T> const& x, qua<T> const& y, T const& epsilon)
{
    vec<4, T> v(x.x - y.x, x.y - y.y, x.z - y.z, x.w - y.w);
    return lessThan(abs(v), vec<4, T>(epsilon));
}

template<typename T>
GLM_API vec<4, bool> epsilonNotEqual(qua<T> const& x, qua<T> const& y, T const& epsilon)
{
    vec<4, T> v(x.x - y.x, x.y - y.y, x.z - y.z, x.w - y.w);
    return greaterThanEqual(abs(v), vec<4, T>(epsilon));
}

} // end namespace glm

#endif // GLM_EPSILON_HPP_20260314023200
