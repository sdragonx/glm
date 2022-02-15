/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 intersect.hpp

 2022-01-27 01:40:02

*/
#ifndef GLM_INTERSECT_HPP_20220127014002
#define GLM_INTERSECT_HPP_20220127014002

#include "../vector.hpp"

namespace glm{

//
// bool intersectRayPlane( in rayPos, in rayDir, in planeOrg, in planeNormal, out distance )
//

template<typename T>
GLM_API bool intersectRayPlane(
    const vec<3, T>& rayPos,
    const vec<3, T>& rayDir,
    const vec<3, T>& planeOrg,
    const vec<3, T>& planeNormal,
    T& intersectionDistance
)
{
    T d = glm::dot(rayDir, planeNormal);

    // if dir and planeNormal are not perpendicular
    if (abs(d) > constants<T>::epsilon) {
        T dist = dot(planeOrg - rayPos, planeNormal) / d;
        // allow only intersections
        if (dist > constants<T>::zero) {
            intersectionDistance = dist;
            return true;
        }
    }

    return false;
}

//
// bool intersectRayTriangle( in rayPos, in rayDir, in v1, in v2, in v3, out coord2, out distance )
//

template<typename T>
GLM_API bool intersectRayTriangle(
    const vec<3, T>& rayPos,       // ray position
    const vec<3, T>& rayDir,       // ray direction
    const vec<3, T>& v1,           // triangle
    const vec<3, T>& v2,
    const vec<3, T>& v3,
    vec<2, T>& coord,              // out coord
    T& intersectionDistance        // out distance
)
{
    vec<3, T> v21 = v2 - v1;
    vec<3, T> v31 = v3 - v1;

    // p
    vec<3, T> p = cross(rayDir, v31);

    // determinant
    T det = dot(v21, p);

    // keep det > 0, modify dir accordingly
    vec<3, T> dir;
    if (det > 0) {
        dir = rayPos - v1;
    }
    else {
        dir = v1 - rayPos;
        det = -det;
    }

    //  determinant 接近 0 时，表示射线与平面几乎平行
    if (det < constants<T>::epsilon) {
        return false;
    }

    // 计算 u, 保证 u <= 1
    coord.x = dot(dir, p);
    if (coord.x < T(0) || coord.x > det) {
        return false;
    }

    // q
    vec<3, T> q = cross(dir, v21);

    // 计算 v, 保证 u + v <= 1
    coord.y = dot(rayDir, q);
    if (coord.y < T(0) || coord.x + coord.y > det) {
        return false;
    }

    // 计算距离
    intersectionDistance = dot(v31, q);

    // 计算纹理坐标差值
    float inv_det = 1.0f / det;
    intersectionDistance *= inv_det;
    if (intersectionDistance < constants<T>::epsilon) {
        return false;
    }

    coord *= inv_det;

    return true;
}

//
// bool intersectRayTriangle( in rayPos, in rayDir, in v1, in v2, in v3, out coord3, out distance )
//

template<typename T>
GLM_API bool intersectRayTriangle(
    const vec<3, T>& rayPos,       // ray position
    const vec<3, T>& rayDir,       // ray direction
    const vec<3, T>& v1,           // triangle
    const vec<3, T>& v2,
    const vec<3, T>& v3,
    vec<3, T>& coord,              // out coord
    T& intersectionDistance        // out distance
)
{
    vec<2, T> uv;
    if (intersectRayTriangle(rayPos, rayDir, v1, v2, v3, uv, intersectionDistance)) {
        coord.x = constants<T>::one - uv.x - uv.y;
        coord.y = uv.y;
        coord.z = uv.x;
        return true;
    }
    return false;
}

//
// bool intersectRaySphere( in rayPos, in rayDir, in sphereCenter, in sphereRadiusSquered, out distance )
//

template<typename T>
GLM_API bool intersectRaySphere(
    const vec<3, T>& rayPos, const vec<3, T>& rayDir,       // ray
    const vec<3, T>& sphereCenter, T sphereRadiusSquered,   // sphere
    T& intersectionDistance)                                // out distance
{
    vec<3, T> dir = sphereCenter - rayPos;

    T a = dot(dir, rayDir);
    T d = dot(dir, dir) - a * a;
    if (d > sphereRadiusSquered) {
        return false;
    }
    d = sqrt(sphereRadiusSquered - d);
    intersectionDistance = a > d + constants<T>::epsilon ? a - d : a + d;
    return intersectionDistance > constants<T>::epsilon;
}

//
// bool intersectRaySphere( in rayPos, in rayDir, in sphereCenter, in sphereRadius, out position, out normal )
//

template<typename T>
GLM_API bool intersectRaySphere(
    const vec<3, T>& rayPos, const vec<3, T>& rayDir,       // ray
    const vec<3, T>& sphereCenter, T sphereRadius,          // sphere
    vec<3, T>& intersectionPosition,                        // out position
    vec<3, T>& intersectionNormal                           // out normal
)
{
    T dist;
    if (intersectRaySphere(rayPos, rayDir, sphereCenter, sphereRadius * sphereRadius, dist)) {
        intersectionPosition = rayPos + rayDir * dist;
        intersectionNormal = (intersectionPosition - sphereCenter) / sphereRadius;
        return true;
    }
    return false;
}

//
// bool intersectRaySphere( in rayPos, in rayDir, in sphereCenter, in sphereRadius, out distance, out position, out normal )
//

template<typename T>
GLM_API bool intersectRaySphere(
    const vec<3, T>& rayPos, const vec<3, T>& rayDir,       // ray
    const vec<3, T>& sphereCenter, T sphereRadius,          // sphere
    T& intersectionDistance,                                // out distance
    vec<3, T>& intersectionPosition,                        // out position
    vec<3, T>& intersectionNormal                           // out normal
)
{
    if (intersectRaySphere(rayPos, rayDir, sphereCenter, sphereRadius * sphereRadius, intersectionDistance)) {
        intersectionPosition = rayPos + rayDir * intersectionDistance;
        intersectionNormal = (intersectionPosition - sphereCenter) / sphereRadius;
        return true;
    }
    return false;
}

}// end namespace glm

#endif// GLM_INTERSECT_HPP_20220127014002
