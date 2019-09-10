/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/9/19
**/

#include <iostream>
#include "PlayState.hpp"

#include "States.hpp"
#include "../app/LichPP.hpp"

void PlayState::init() {
    rect.set(Rectangle(20, 100, 50, 30));
}

void PlayState::clean() {

}

void PlayState::handleInput() {

}

void PlayState::update() {

}

void PlayState::draw(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_Rect r = rect.toRect();
    SDL_RenderDrawRect(renderer, &r);
}

void PlayState::resize(int width, int height) {

}
