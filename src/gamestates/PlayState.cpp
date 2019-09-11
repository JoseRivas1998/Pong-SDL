/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/9/19
**/

#include <iostream>
#include "PlayState.hpp"

#include "States.hpp"
#include "../app/LichPP.hpp"

#include "../input/PongInput.hpp"

void PlayState::init() {
    rect.set(Rectangle(20, 100, 50, 30));
    ball.reset();
}

void PlayState::clean() {

}

void PlayState::handleInput(float dt) {
    if(PongInput::keyCheck(PongInput::UP)) {
        rect.y -= 500 * dt;
    }
    if(PongInput::keyCheck(PongInput::DOWN)) {
        rect.y += 500 * dt;
    }
}

void PlayState::update(float dt) {
    ball.update(dt);
    if(ball.getX() < -50) {
        ball.reset();
    }
    if(ball.getX() + ball.getWidth() > (float) LichPP::graphics->getWindowWidth() + 50) {
        ball.reset();
    }
}

void PlayState::draw(float dt, SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_Rect r = rect.toRect();
    SDL_RenderDrawRect(renderer, &r);
    ball.draw(dt, renderer);
}

void PlayState::resize(int width, int height) {

}
