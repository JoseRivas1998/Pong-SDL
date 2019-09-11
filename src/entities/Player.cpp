//
// Created by joserivas1998 on 9/10/19.
//

#include "Player.hpp"
#include "../input/PongInput.hpp"
#include "../graphics/Color.hpp"
#include "../app/LichPP.hpp"

Player::Player(float width, float height) : AbstractEntity() {
    this->setSize(width, height);
}

void Player::handleInput() {
    this->setVelocityY(0);
    if(PongInput::keyCheck(PongInput::UP)) {
        this->setVelocityY(-PLAYER_SPEED);
    }
    if(PongInput::keyCheck(PongInput::DOWN)) {
        this->setVelocityY(PLAYER_SPEED);
    }
}

void Player::update(float dt) {
    this->applyVelocity(dt);
    if(this->getY() < 0) {
        this->setY(0);
    }
    auto worldHeight = (float) LichPP::graphics->getWindowHeight();
    if(this->getY() + this->getHeight() > worldHeight) {
        this->setY(worldHeight - this->getHeight());
    }
}

void Player::draw(float dt, SDL_Renderer *renderer) {
    Color::setDrawColor(renderer, Colors::WHITE);
    SDL_Rect rect = this->getBounds().toRect();
    SDL_RenderFillRect(renderer, &rect);
}
