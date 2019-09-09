/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/9/19
**/

#ifndef PONG_GAMESTATE_HPP
#define PONG_GAMESTATE_HPP

#include <SDL.h>

class GameState {
public:
    virtual ~GameState() = default;
    virtual void init() = 0;
    virtual void clean() = 0;
    virtual void handleInput() = 0;
    virtual void update() = 0;
    virtual void draw(SDL_Renderer *renderer) = 0;
    virtual void resize(int width, int height) = 0;
};


#endif //PONG_GAMESTATE_HPP
