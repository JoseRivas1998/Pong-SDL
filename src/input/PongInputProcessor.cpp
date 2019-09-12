/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/10/19
**/

#include <iostream>
#include "PongInputProcessor.hpp"
#include "PongInput.hpp"

bool processKey(SDL_Keycode keycode, bool value) {
    bool processed = true;
    switch (keycode) {
        case SDLK_UP:
        case SDLK_w:
            PongInput::setKey(PongInput::UP, value);
            break;
        case SDLK_DOWN:
        case SDLK_s:
            PongInput::setKey(PongInput::DOWN, value);
            break;
        case SDLK_RETURN:
            PongInput::setKey(PongInput::START, value);
            break;
        case SDLK_ESCAPE:
            PongInput::setKey(PongInput::BACK, value);
            break;
        default:
            processed = false;
    }
    return processed;
}

bool PongInputProcessor::keyDown(SDL_Keycode keycode) {
    return processKey(keycode, true);
}

bool PongInputProcessor::keyUp(SDL_Keycode keycode) {
    return processKey(keycode, false);
}
