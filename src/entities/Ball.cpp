//
// Created by joserivas1998 on 9/10/19.
//

#include <iostream>
#include "Ball.hpp"
#include "../app/LichPP.hpp"

Ball::Ball(float size) : AbstractEntity() {
    this->setSize(size, size);
}

void Ball::reset() {
    LichPP::assets->playSoundEffect("peep");
    auto worldWidth = (float) LichPP::graphics->getWindowWidth();
    auto worldHeight = (float) LichPP::graphics->getWindowHeight();

    this->setX((worldWidth * 0.5f) - (this->getWidth() * 0.5f));
    this->setY((worldHeight * 0.5f) - (this->getHeight() * 0.5f));

    do {
        this->setVelocity(Vector2::polarRand(Ball::BALL_SPEED));
    } while((this->getDirectionDeg() > 80 && this->getDirectionDeg() < 100) || (this->getDirectionDeg() > 260 && this->getDirectionDeg() < 280));
}

void Ball::update(float dt) {
    this->applyVelocity(dt);
    auto worldWidth = (float) LichPP::graphics->getWindowWidth();
    auto worldHeight = (float) LichPP::graphics->getWindowHeight();
    if(this->getY() < 0) {
        this->setY(0);
        this->bounceY();
    }
    if(this->getY() + this->getHeight() > worldHeight) {
        this->setY(worldHeight - this->getHeight());
        this->bounceY();
    }
}

void Ball::bounceY() {
    LichPP::assets->playSoundEffect("plop");
    setVelocityY(-getVelocityY());
}

void Ball::bounceX() {
    LichPP::assets->playSoundEffect("beep");
    setVelocityX(-getVelocityX());
}

void Ball::draw(float dt, SDL_Renderer *renderer) {
    Color::setDrawColor(renderer, Colors::WHITE);
    SDL_Rect rect = this->getBounds().toRect();
    SDL_RenderFillRect(renderer, &rect);
}
