/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/10/19
**/

#ifndef PONG_PONGINPUTPROCESSOR_HPP
#define PONG_PONGINPUTPROCESSOR_HPP

#include "InputListener.hpp"

class PongInputProcessor : public InputAdapter {
public:
    bool keyDown(SDL_Keycode keycode) override;

    bool keyUp(SDL_Keycode keycode) override;
};


#endif //PONG_PONGINPUTPROCESSOR_HPP
