/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 quaternion.hpp

 2024-02-10 22:02:05

*/
#ifndef GLM_QUATERNION_HPP_20240210220205
#define GLM_QUATERNION_HPP_20240210220205

#include "../gtc/quaternion.hpp"



namespace glm {

// Create an identity quaternion.
template<typename T>
GLM_API qua<T> quat_identity()
{
    return qua<T>(static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0));
}

// Compute a cross product between a quaternion and a vector.
template<typename T>
GLM_API vec<3, T> cross(const qua<T>& q, const vec<3, T>& v)
{
    return inverse(q) * v;
}

//! Compute a cross product between a vector and a quaternion.
template<typename T>
GLM_API vec<3, T> cross(const vec<3, T>& v, const qua<T>& q)
{
    return q * v;
}

//! Compute a point on a path according squad equation.
//! q1 and q2 are control points; s1 and s2 are intermediate control points.
template<typename T>
GLM_API qua<T> squad(const qua<T>& q1, const qua<T>& q2, const qua<T>& s1, const qua<T>& s2, const T& h)
{
    return mix(mix(q1, q2, h), mix(s1, s2, h), static_cast<T>(2) * (static_cast<T>(1) - h) * h);
}

//! Returns an intermediate control point for squad interpolation.
template<typename T>
GLM_API qua<T> intermediate(const qua<T>& prev, const qua<T>& curr, const qua<T>& next)
{
    qua<T> invQuat = inverse(curr);
    return exp((log(next * invQuat) + log(prev * invQuat)) / static_cast<T>(-4)) * curr;
}

//! Rotates a 3 components vector by a quaternion.
template<typename T>
GLM_API vec<3, T> rotate(const qua<T>& q, const vec<3, T>& v)
{
    return q * v;
}

// Rotates a 4 components vector by a quaternion.
template<typename T>
GLM_API vec<4, T> rotate(const qua<T>& q, const vec<4, T>& v)
{
    return q * v;
}

// Extract the real component of a quaternion.
template<typename T>
GLM_API T extractRealComponent(const qua<T>& q)
{
    T w = static_cast<T>(1) - q.x * q.x - q.y * q.y - q.z * q.z;
    if (w < T(0))
        return T(0);
    else
        return -sqrt(w);
}

// Converts a quaternion to a 3 * 3 matrix.
template<typename T>
GLM_API mat<3, 3, T> toMat3(const qua<T>& x)
{
    return mat3_cast(x);
}

// Converts a quaternion to a 4 * 4 matrix.
template<typename T>
GLM_API mat<4, 4, T> toMat4(const qua<T>& x)
{
    return mat4_cast(x);
}

// Converts a 3 * 3 matrix to a quaternion.
template<typename T>
GLM_API qua<T> toQuat(const mat<3, 3, T>& x)
{
    return quat_cast(x);
}

// Converts a 4 * 4 matrix to a quaternion.
template<typename T>
GLM_API qua<T> toQuat(const mat<4, 4, T>& x)
{
    return quat_cast(x);
}

// Quaternion interpolation using the rotation short path.
template<typename T>
GLM_API qua<T> shortMix(const qua<T>& x, const qua<T>& y, const T& a)
{
    if (a <= static_cast<T>(0))
        return x;
    if (a >= static_cast<T>(1))
        return y;

    T fCos = dot(x, y);
    qua<T> y2(y); // BUG!!! qua<T> y2;
    if (fCos < static_cast<T>(0)) {
        y2   = -y;
        fCos = -fCos;
    }

    // if(fCos > 1.0f) // problem
    T k0, k1;
    if (fCos > (static_cast<T>(1) - epsilon<T>())) {
        k0 = static_cast<T>(1) - a;
        k1 = static_cast<T>(0) + a; // BUG!!! 1.0f + a;
    }
    else {
        T fSin        = sqrt(T(1) - fCos * fCos);
        T fAngle      = atan(fSin, fCos);
        T fOneOverSin = static_cast<T>(1) / fSin;
        k0            = sin((static_cast<T>(1) - a) * fAngle) * fOneOverSin;
        k1            = sin((static_cast<T>(0) + a) * fAngle) * fOneOverSin;
    }

    return qua<T>(
        k0 * x.w + k1 * y2.w,
        k0 * x.x + k1 * y2.x,
        k0 * x.y + k1 * y2.y,
        k0 * x.z + k1 * y2.z);
}

// Quaternion normalized linear interpolation.
template<typename T>
GLM_API qua<T> fastMix(const qua<T>& x, const qua<T>& y, const T& a)
{
    return glm::normalize(x * (static_cast<T>(1) - a) + (y * a));
}

// Returns the squared length of x.
template<typename T>
GLM_API T length2(const qua<T>& q)
{
    return q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w;
}

/* Compute the rotation between two vectors.
 * orig vector, needs to be normalized
 * dest vector, needs to be normalized
 */
template<typename T>
GLM_API qua<T> rotation(const vec<3, T>& orig, const vec<3, T>& dest)
{
    T cosTheta = dot(orig, dest);
    vec<3, T> rotationAxis;

    if (cosTheta >= static_cast<T>(1) - epsilon<T>()) {
        // orig and dest point in the same direction
        return quat_identity<T>();
    }

    if (cosTheta < static_cast<T>(-1) + epsilon<T>()) {
        // special case when vectors in opposite directions :
        // there is no "ideal" rotation axis
        // So guess one; any will do as long as it's perpendicular to start
        // This implementation favors a rotation around the Up axis (Y),
        // since it's often what you want to do.
        rotationAxis = cross(vec<3, T>(0, 0, 1), orig);
        if (length2(rotationAxis) < epsilon<T>()) // bad luck, they were parallel, try again!
            rotationAxis = cross(vec<3, T>(1, 0, 0), orig);

        rotationAxis = normalize(rotationAxis);
        return angleAxis(pi<T>(), rotationAxis);
    }

    // Implementation from Stan Melax's Game Programming Gems 1 article
    rotationAxis = cross(orig, dest);

    T s    = sqrt((T(1) + cosTheta) * static_cast<T>(2));
    T invs = static_cast<T>(1) / s;

    return qua<T>(
        s * static_cast<T>(0.5f),
        rotationAxis.x * invs,
        rotationAxis.y * invs,
        rotationAxis.z * invs);
}

} // end namespace glm

#endif // GLM_QUATERNION_HPP_20240210220205
