/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/12/19
**/

#include "TitleState.hpp"
#include "../app/LichPP.hpp"
#include "../input/PongInput.hpp"


void TitleState::init() {
    this->font = LichPP::assets->getFont("title");
    this->smaller = LichPP::assets->getFont("main");
}

void TitleState::clean() {

}

void TitleState::handleInput(float dt) {

    if(PongInput::keyCheckPressed(PongInput::START)) {
        LichPP::app->switchState(States::Play);
    }

    if(PongInput::keyCheckPressed(PongInput::BACK)) {
        LichPP::app->quit();
    }

}

void TitleState::update(float dt) {

}

void TitleState::draw(float dt, SDL_Renderer *renderer) {
    float width;
    float height;
    float x;
    float y;

    auto worldWidth = (float) LichPP::graphics->getWindowWidth();
    auto worldHeight = (float) LichPP::graphics->getWindowHeight();

    width = (float) this->font->getWidth(renderer, "Pong");
    height = (float) this->font->getHeight(renderer, "Pong");

    x = (worldWidth * 0.5f) - (width * 0.5f);
    y = (worldHeight * 0.25f) - (height * 0.5f);

    this->font->draw(renderer, "Pong", x, y);

    std::string enter = "Press enter to begin!";

    width = (float) this->smaller->getWidth(renderer, enter);
    height = (float) this->smaller->getHeight(renderer, enter);

    x = (worldWidth * 0.5f) - (width * 0.5f);
    y = (worldHeight * 0.75f) - (height * 0.5f);

    this->smaller->draw(renderer, enter, x, y);

}

void TitleState::resize(int width, int height) {

}
