//
// Created by joserivas1998 on 9/9/19.
//

#ifndef PONG_VECTOR2_HPP
#define PONG_VECTOR2_HPP


class Vector2 {
public:
    float x;
    float y;

    Vector2() : Vector2(0, 0) {}

    Vector2(float x, float y);

    Vector2(const Vector2 &v) : Vector2(v.x, v.y) {}

    static Vector2 polar(float magnitude, float radians);

    static Vector2 polarDeg(float magnitude, float degrees);

    static Vector2 polarRand(float magnitude);

    void set(float x, float y);

    void set(const Vector2 &v);

    float mag();

    float mag2();

    float dist(float x, float y);

    float dist(const Vector2 &v);

    float dist2(float x, float y);

    float dist2(const Vector2 &v);

    float angle();

    float angleDeg();

};


#endif //PONG_VECTOR2_HPP
