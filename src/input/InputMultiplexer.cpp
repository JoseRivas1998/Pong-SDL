/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/10/19
**/

#include <iostream>
#include "InputMultiplexer.hpp"

void InputMultiplexer::addInputListener(InputListener *inputListener) {
    this->inputListeners.push_back(inputListener);
}

void InputMultiplexer::handleKeyboardEvent(const SDL_KeyboardEvent &keyboardEvent) {
    bool processed = false;
    if (inputListeners.empty()) {
        std::cout << "WARNING - No input listener attached" << std::endl;
    }
    for (int i = 0; i < (int) inputListeners.size() && !processed; ++i) {
        if (keyboardEvent.type == SDL_KEYDOWN) {
            if (!keyboardEvent.repeat) {
                processed = inputListeners[i]->keyDown(keyboardEvent.keysym.sym);
            }
        } else if (keyboardEvent.type == SDL_KEYUP) {
            processed = inputListeners[i]->keyUp(keyboardEvent.keysym.sym);
        }
    }
}

InputMultiplexer::~InputMultiplexer() {
    if(!this->inputListeners.empty()) {
        for (auto & inputListener : this->inputListeners) {
            delete inputListener;
        }
        this->inputListeners.clear();
    } else {
        std::cout << "Nothing to delete" << std::endl;
    }
}
