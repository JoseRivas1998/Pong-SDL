//
// Created by joserivas1998 on 9/9/19.
//

#include "Vector2.hpp"

#include "MathUtils.hpp"

Vector2::Vector2(float x, float y) {
    this->x = x;
    this->y = y;
}

Vector2 Vector2::polar(float magnitude, float radians) {
    float x = MathUtils::cos(radians) * magnitude;
    float y = MathUtils::sin(radians) * magnitude;
    return Vector2(x, y);
}

Vector2 Vector2::polarDeg(float magnitude, float degrees) {
    float x = MathUtils::cosDeg(degrees) * magnitude;
    float y = MathUtils::sinDeg(degrees) * magnitude;
    return Vector2(x, y);
}

Vector2 Vector2::polarRand(float magnitude) {
    return Vector2::polar(magnitude, MathUtils::rand(0, MathUtils::PI2));
}

void Vector2::set(const Vector2 &v) {
    this->set(v.x, v.y);
}

void Vector2::set(float x, float y) {
    this->x = x;
    this->y = y;
}

float Vector2::mag() {
    return MathUtils::mag(this->x, this->y);
}

float Vector2::mag2() {
    return MathUtils::mag2(this->x, this->y);
}

float Vector2::dist(float x, float y) {
    return MathUtils::dist(this->x, this->y, x, y);
}

float Vector2::dist(const Vector2 &v) {
    return this->dist(v.x, v.y);
}

float Vector2::dist2(float x, float y) {
    return MathUtils::dist2(this->x, this->y, x, y);
}

float Vector2::dist2(const Vector2 &v) {
    return this->dist2(v.x, v.y);
}

float Vector2::angle() {
    float radians = MathUtils::atan2(this->y, this->x);
    if(radians < 0) radians += MathUtils::PI2;
    return radians;
}

float Vector2::angleDeg() {
    float degrees = MathUtils::atan2Deg(this->y, this->x);
    if(degrees < 0) degrees += MathUtils::FULL_DEG;
    return degrees;
}
