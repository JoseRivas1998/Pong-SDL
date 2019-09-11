/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/11/19
**/

#include "AiPaddle.hpp"
#include "../graphics/Color.hpp"
#include "../math/MathUtils.hpp"
#include "../app/LichPP.hpp"

constexpr float MIN_TIME = 0.15f;
constexpr float MAX_TIME = 0.45f;

constexpr float MAX_ERROR = 10.0f;

float randTime() {
    return MathUtils::rand(MIN_TIME, MAX_TIME);
}

float randError() {
    return MathUtils::rand(0, MAX_ERROR) * MathUtils::randSign();
}

AIPaddle::AIPaddle(float width, float height) : AbstractEntity() {
    this->setSize(width, height);
    auto worldHeight = (float) LichPP::graphics->getWindowHeight();
    this->target_y = worldHeight * 0.5f;
}


void AIPaddle::updateTarget(Ball ball) {
    auto worldHeight = (float) LichPP::graphics->getWindowHeight();
    if (fabsf(this->target_y - this->getY()) < getHeight()) {
        this->target_y = ball.getY() + randError();
        while(this->target_y + this->getHeight() > worldHeight) {
            this->target_y -= this->getHeight();
        }
        while(this->target_y < 0) {
            this->target_y += this->getHeight();
        }
        float time = randTime();
        float delta_y = this->target_y - this->getY();
        this->y_speed = fabsf(delta_y / time);
    }
}

void AIPaddle::update(float dt) {
    if(getY() > target_y) {
        setVelocityY(-this->y_speed);
    }
    if(getY() < target_y) {
        setVelocityY(this->y_speed);
    }
    applyVelocity(dt);
    auto worldHeight = (float) LichPP::graphics->getWindowHeight();
    if(this->getY() < 0) {
        this->setY(0);
    }
    if(this->getY() + this->getHeight() > worldHeight) {
        this->setY(worldHeight - getHeight());
    }
}

void AIPaddle::draw(float dt, SDL_Renderer *renderer) {
    Color::setDrawColor(renderer, Colors::WHITE);
    SDL_Rect rect = this->getBounds().toRect();
    SDL_RenderFillRect(renderer, &rect);
}
