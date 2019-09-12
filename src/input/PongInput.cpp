/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/10/19
**/

#include "PongInput.hpp"

std::array<bool, NUM_KEYS> PongInput::keys = {false, false, false, false};
std::array<bool, NUM_KEYS> PongInput::pkeys = {false, false, false, false};

void PongInput::update() {
    for(int i = 0; i < NUM_KEYS; ++i) {
        PongInput::pkeys[i] = PongInput::keys[i];
    }
}

void PongInput::setKey(int k, bool value) {
    PongInput::keys[k] = value;
}

bool PongInput::keyCheck(int k) {
    return PongInput::keys[k];
}

bool PongInput::keyCheckPressed(int k) {
    return PongInput::keys[k] && !PongInput::pkeys[k];
}
