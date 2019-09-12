//
// Created by joserivas1998 on 9/9/19.
//

#include "Color.hpp"

Color::Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    this->set(r, g, b, a);
}

Color::Color(Uint32 rgba8888) {
    this->r = (rgba8888 & 0xFF000000) >> 24;
    this->g = (rgba8888 & 0x00FF0000) >> 16;
    this->b = (rgba8888 & 0x0000FF00) >> 8;
    this->a = (rgba8888 & 0x000000FF) >> 0;
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

void Color::setDrawColor(SDL_Renderer *renderer, Uint32 rgba88) {
    Color c(rgba88);
    c.setDrawColor(renderer);
}

SDL_Color Color::toSDLColor() {
    return SDL_Color{this->r, this->g, this->b, this->a};
}

