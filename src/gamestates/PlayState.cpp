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
    ball.reset();
    player.setX(((float) LichPP::graphics->getWindowWidth() * 0.15f) - (player.getWidth() * 0.5f));
    player.setY(((float) LichPP::graphics->getWindowHeight() * 0.5f) - (player.getHeight() * 0.5f));
    aiPaddle.setX(((float) LichPP::graphics->getWindowWidth() * 0.85f) - (aiPaddle.getWidth() * 0.5f));
    aiPaddle.setY(((float) LichPP::graphics->getWindowHeight() * 0.5f) - (aiPaddle.getHeight() * 0.5f));

}

void PlayState::clean() {

}

void PlayState::handleInput(float dt) {
    player.handleInput();
}

void PlayState::update(float dt) {
    ball.update(dt);
    player.update(dt);
    aiPaddle.updateTarget(ball);
    aiPaddle.update(dt);
    if(ball.getX() < -50) {
        ball.reset();
    }
    if(ball.getX() + ball.getWidth() > (float) LichPP::graphics->getWindowWidth() + 50) {
        ball.reset();
    }
    if(player.collidingWith(ball)) {
        ball.setX(player.getX() + player.getWidth());
        ball.bounceX();
    }
    if(aiPaddle.collidingWith(ball)) {
        ball.setX(aiPaddle.getX() - ball.getWidth());
        ball.bounceX();
    }
}

void PlayState::draw(float dt, SDL_Renderer *renderer) {
    ball.draw(dt, renderer);
    player.draw(dt, renderer);
    aiPaddle.draw(dt, renderer);
}

void PlayState::resize(int width, int height) {

}
