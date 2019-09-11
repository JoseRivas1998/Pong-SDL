//
// Created by joserivas1998 on 9/9/19.
//

#include "Color.hpp"

Color::Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    this->set(r, g, b, a);
}

void Color::set(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void Color::set(const Color &c) {
    this->set(c.r, c.g, c.b, c.a);
}

void Color::setDrawColor(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, this->r, this->g, this->b, this->a);
}

