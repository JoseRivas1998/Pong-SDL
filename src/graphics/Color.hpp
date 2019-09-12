//
// Created by joserivas1998 on 9/9/19.
//

#ifndef PONG_COLOR_HPP
#define PONG_COLOR_HPP


#include <SDL.h>

class Color {
public:
    Uint8 r = 0;
    Uint8 g = 0;
    Uint8 b = 0;
    Uint8 a = 0;
    Color() = default;
    Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    explicit Color(Uint32 rgba8888);
    void set(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void set(const Color &c);
    void setDrawColor(SDL_Renderer *renderer);
    SDL_Color toSDLColor();
    static void setDrawColor(SDL_Renderer *renderer, Uint32 rgba88);
};

class Colors {
public:
    constexpr static Uint32 WHITE = 0xFFFFFFFF;
    constexpr static Uint32 RED = 0xFF0000FF;
    constexpr static Uint32 GREEN = 0x00FF00FF;
    constexpr static Uint32 BLUE = 0x0000FFFF;
    constexpr static Uint32 BLACK = 0x000000FF;
};


#endif //PONG_COLOR_HPP
