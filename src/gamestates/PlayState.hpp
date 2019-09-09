/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/9/19
**/

#ifndef PONG_PLAYSTATE_HPP
#define PONG_PLAYSTATE_HPP

#include "GameState.hpp"

class PlayState : public GameState {
    void init() override;

    void clean() override;

    void handleInput() override;

    void update() override;

    void draw(SDL_Renderer *renderer) override;

public:
    void resize(int width, int height) override;
};


#endif //PONG_PLAYSTATE_HPP
