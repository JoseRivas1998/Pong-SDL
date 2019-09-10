/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/9/19
**/

#include <iostream>
#include "PlayState.hpp"

#include "States.hpp"
#include "../app/LichPP.hpp"

float timer = 0;
int seconds = 0;
void PlayState::init() {
    rect.set(Rectangle(20, 100, 50, 30));
}

void PlayState::clean() {

}

void PlayState::handleInput(float dt) {

}

void PlayState::update(float dt) {
    timer += dt;
    if(timer >= 1) {
        seconds++;
        timer = 0;
        std::cout << seconds << " Second" << (seconds > 1 ? "s": "") << std::endl;
    }

}

void PlayState::draw(float dt, SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_Rect r = rect.toRect();
    SDL_RenderDrawRect(renderer, &r);
}

void PlayState::resize(int width, int height) {

}
