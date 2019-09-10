//
// Created by joserivas1998 on 9/9/19.
//

#ifndef PONG_VECTOR2_HPP
#define PONG_VECTOR2_HPP


class Vector2 {
public:
    float x;
    float y;
    Vector2() : Vector2(0, 0){}
    Vector2(float x, float y);
    Vector2(const Vector2 &v) : Vector2(v.x, v.y) {}
};


#endif //PONG_VECTOR2_HPP
