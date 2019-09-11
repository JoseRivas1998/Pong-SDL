//
// Created by joserivas1998 on 9/9/19.
//

#include "Vector2.hpp"

Vector2::Vector2(float x, float y) {
    this->set(x, y);
}

void Vector2::set(const Vector2 &v) {
    this->set(v.x, v.y);
}

void Vector2::set(float x, float y) {
    this->x = x;
    this->y = y;
}
