/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/9/19
**/

#include "Rectangle.hpp"

Rectangle::Rectangle(float x, float y, float width, float height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

bool Rectangle::contains(float x, float y) {
    bool b1 = this->x <= x;
    bool b2 = this->x + this->width >= x;
    bool b3 = this->y <= y;
    bool b4 = this->y + this->height >= y;
    return b1 && b2 && b3 && b4;
}

bool Rectangle::contains(const Vector2 &point) {
    return this->contains(point.x, point.y);
}

bool Rectangle::overlaps(const Rectangle &r) {
    bool b1 = this->x < r.x + r.width;
    bool b2 = this->x + this->width > r.x;
    bool b3 = this->y < r.y + r.height;
    bool b4 = this->y + this->height > r.y;
    return b1 && b2 && b3 && b4;
}

void Rectangle::set(const Rectangle &rect) {
    this->x = rect.x;
    this->y = rect.y;
    this->width = rect.width;
    this->height = rect.height;
}

float Rectangle::area() {
    return this->width * this->height;
}

float Rectangle::perimeter() {
    return 2 * (this->width + this->height);
}

void Rectangle::addToPosition(const Vector2 &vector, float scalar) {
    this->x += vector.x * scalar;
    this->y += vector.y * scalar;
}

void Rectangle::addToPosition(const Vector2 &vector) {
    this->addToPosition(vector, 1.0f);
}

SDL_Rect Rectangle::toRect() {
    SDL_Rect rect;
    rect.x = (int) this->x;
    rect.y = (int) this->y;
    rect.w = (int) this->width;
    rect.h = (int) this->height;
    return rect;
}
