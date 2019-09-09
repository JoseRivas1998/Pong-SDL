/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/9/19
**/
#include "Graphics.hpp"

Graphics::~Graphics() {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
}

int Graphics::getWindowWidth() {
    int width = 0;
    SDL_GetWindowSize(this->window, &width, nullptr);
    return width;
}

int Graphics::getWindowHeight() {
    int height = 0;
    SDL_GetWindowSize(this->window, nullptr, &height);
    return height;
}
