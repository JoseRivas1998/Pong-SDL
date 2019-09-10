/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/9/19
**/

#include "GameStateManager.hpp"

#include "../gamestates/PlayState.hpp"

void GameStateManager::setState(States state) {
    if(this->currentState != nullptr) {
        this->currentState->clean();
        delete this->currentState;
    }
    switch (state) {
        case Play:
            this->currentState = new PlayState();
            break;
    }
    this->currentState->init();
}

void GameStateManager::step(float dt, SDL_Renderer *renderer) {
    this->currentState->handleInput(dt);
    this->currentState->update(dt);
    this->currentState->draw(dt, renderer);
}

void GameStateManager::resize(int width, int height) {
    this->currentState->resize(width, height);
}

void GameStateManager::clean() {
    this->currentState->clean();
    delete this->currentState;
}
