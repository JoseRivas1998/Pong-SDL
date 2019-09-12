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
    rightScore = 0;
    leftScore = 0;
    font = new Font("../assets/prstartk.ttf", 36);
    font->setColor(Colors::WHITE);
}

void PlayState::clean() {
    delete this->font;
}

void PlayState::handleInput(float dt) {
    player.handleInput();
    if(PongInput::keyCheckPressed(PongInput::BACK)) {
        LichPP::app->switchState(States::Title);
    }
}

void PlayState::update(float dt) {
    ball.update(dt);
    player.update(dt);
    aiPaddle.updateTarget(ball);
    aiPaddle.update(dt);
    if(ball.getX() < -50) {
        rightScore++;
        ball.reset();
    }
    if(ball.getX() + ball.getWidth() > (float) LichPP::graphics->getWindowWidth() + 50) {
        leftScore++;
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
    float x;
    float y;
    float width;
    float height;

    auto worldWidth = (float) LichPP::graphics->getWindowWidth();
    auto worldHeight=  (float) LichPP::graphics->getWindowHeight();

    auto left = std::to_string(leftScore);
    auto right = std::to_string(rightScore);

    width = (float) this->font->getWidth(renderer, left);
    height = (float) this->font->getHeight(renderer, left);

    x = (worldWidth * 0.25f) - (width * 0.5f);
    y = (worldHeight * 0.25f) - (height * 0.5f);

    this->font->draw(renderer, left, x, y);

    width = (float) this->font->getWidth(renderer, right);
    height = (float) this->font->getHeight(renderer, right);

    x = (worldWidth * 0.75f) - (width * 0.5f);
    y = (worldHeight * 0.25f) - (height * 0.5f);

    this->font->draw(renderer, right, x, y);

}

void PlayState::resize(int width, int height) {

}
