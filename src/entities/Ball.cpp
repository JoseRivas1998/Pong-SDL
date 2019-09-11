//
// Created by joserivas1998 on 9/10/19.
//

#include <iostream>
#include "Ball.hpp"
#include "../app/LichPP.hpp"

Ball::Ball(float size) {
    this->setSize(size, size);
}

void Ball::reset() {
    auto worldWidth = (float) LichPP::graphics->getWindowWidth();
    auto worldHeight = (float) LichPP::graphics->getWindowHeight();

    this->setX((worldWidth * 0.5f) - (this->getWidth() * 0.5f));
    this->setY((worldHeight * 0.5f) - (this->getHeight() * 0.5f));

    this->setVelocity(Vector2::polarRand(Ball::BALL_SPEED));

}

void Ball::update(float dt) {
    this->applyVelocity(dt);
    auto worldWidth = (float) LichPP::graphics->getWindowWidth();
    auto worldHeight = (float) LichPP::graphics->getWindowHeight();
    if(this->getY() < 0) {
        this->setY(0);
        this->setVelocityY(-this->getVelocityY());
    }
    if(this->getY() + this->getHeight() > worldHeight) {
        this->setY(worldHeight - this->getHeight());
        this->setVelocityY(-this->getVelocityY());
    }
}

void Ball::draw(float dt, SDL_Renderer *renderer) {
    Color white(0xFF, 0xFF, 0xFF, 0xFF);
    white.setDrawColor(renderer);
    SDL_Rect rect = this->getBounds().toRect();
    SDL_RenderFillRect(renderer, &rect);
}
