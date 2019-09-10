/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/10/19
**/

#ifndef PONG_INPUTLISTENER_HPP
#define PONG_INPUTLISTENER_HPP

#include <SDL.h>

class InputListener {
public:
    virtual ~InputListener() = default;
    virtual bool keyDown(SDL_Keycode keycode) = 0;

    virtual bool keyUp(SDL_Keycode keycode) = 0;
};

class InputAdapter : public InputListener {
public:
    bool keyDown(SDL_Keycode keycode) override { return false; }

    bool keyUp(SDL_Keycode keycode) override { return false; }
};

#endif //PONG_INPUTLISTENER_HPP
