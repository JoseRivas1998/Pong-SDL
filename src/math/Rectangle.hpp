/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/9/19
**/

#ifndef PONG_RECTANGLE_HPP
#define PONG_RECTANGLE_HPP

#include "SDL.h"
#include "Vector2.hpp"

class Rectangle {
public:
    float x;
    float y;
    float width;
    float height;
    Rectangle() : Rectangle(0, 0, 0, 0) {}
    Rectangle(float x, float y, float width, float height);
    Rectangle(const Rectangle &rect) : Rectangle(rect.x, rect.y, rect.width, rect.height) {}
    bool contains(float x, float y);
    bool contains(const Vector2 &point);
    bool overlaps(const Rectangle &r);
    void set(const Rectangle &rect);
    float area();
    float perimeter();
    SDL_Rect toRect();
};


#endif //PONG_RECTANGLE_HPP
