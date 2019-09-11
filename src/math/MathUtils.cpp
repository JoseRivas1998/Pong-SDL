//
// Created by joserivas1998 on 9/10/19.
//

#include "MathUtils.hpp"

#include <cmath>

float MathUtils::sin(float radians) {
    return std::sin(radians);
}

float MathUtils::sinDeg(float degrees) {
    return MathUtils::sin(degrees * MathUtils::DEGREES_TO_RADIANS);
}

float MathUtils::cos(float radians) {
    return std::cos(radians);
}

float MathUtils::cosDeg(float degrees) {
    return MathUtils::cos(degrees * MathUtils::DEGREES_TO_RADIANS);
}

float MathUtils::tan(float radians) {
    return std::tan(radians);
}

float MathUtils::tanDeg(float degrees) {
    return MathUtils::tan(degrees * MathUtils::DEGREES_TO_RADIANS);
}

float MathUtils::atan2(float y, float x) {
    return std::atan2(y, x);
}

float MathUtils::atan2Deg(float y, float x) {
    return MathUtils::atan2(y, x) * MathUtils::RADIANS_TO_DEGREES;
}

float MathUtils::mag(float x, float y) {
    return std::sqrt(MathUtils::mag2(x, y));
}

float MathUtils::mag2(float x, float y) {
    return x * x + y * y;
}

float MathUtils::dist(float x1, float y1, float x2, float y2) {
    return MathUtils::mag(x2 - x1, y2 - y1);
}

float MathUtils::dist2(float x1, float y1, float x2, float y2) {
    return MathUtils::mag2(x2 - x1, y2 - y1);
}