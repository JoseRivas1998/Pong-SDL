/**
* Name: Jose de Jesus Rodriguez Rivas
* Date: 9/9/19
**/

#ifndef PONG_GRAPHICS_HPP
#define PONG_GRAPHICS_HPP

#include <SDL.h>

class Graphics {
public:
    ~Graphics();
    int getWindowWidth();
    int getWindowHeight();
    SDL_Renderer *renderer;
    SDL_Window *window;
};


#endif //PONG_GRAPHICS_HPP
