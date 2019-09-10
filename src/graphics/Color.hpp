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
    void set(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void set(const Color &c);
};


#endif //PONG_COLOR_HPP
