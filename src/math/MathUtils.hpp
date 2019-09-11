//
// Created by joserivas1998 on 9/10/19.
//

#ifndef PONG_MATHUTILS_HPP
#define PONG_MATHUTILS_HPP


class MathUtils {
public:
    constexpr static float PI = 3.14159265358979323846f;
    constexpr static float PI2 = MathUtils::PI * 2.0f;

    constexpr static float SEMI_DEG = 180.0f;
    constexpr static float FULL_DEG = 360.0f;

    constexpr static float E = 2.71828182845904523536;

    constexpr static float RADIANS_TO_DEGREES = 180.0f / MathUtils::PI;
    constexpr static float RAD_DEG = MathUtils::RADIANS_TO_DEGREES;

    constexpr static float DEGREES_TO_RADIANS = MathUtils::PI / 180.0f;
    constexpr static float DEG_RAD = MathUtils::DEGREES_TO_RADIANS;

    static float sin(float radians);
    static float sinDeg(float degrees);

    static float cos(float radians);
    static float cosDeg(float degrees);

    static float tan(float radians);
    static float tanDeg(float degrees);

    static float atan2(float y, float x);
    static float atan2Deg(float y, float x);

    static float mag(float x, float y);
    static float mag2(float x, float y);

    static float dist(float x1, float y1, float x2, float y2);
    static float dist2(float x1, float y1, float x2, float y2);

    static float rand(float min, float max);

    static bool randBool(float chance);

    static bool randBool();

    static float randSign();

};

#endif //PONG_MATHUTILS_HPP
