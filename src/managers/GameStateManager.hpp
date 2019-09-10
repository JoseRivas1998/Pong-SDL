/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/9/19
**/

#ifndef PONG_GAMESTATEMANAGER_HPP
#define PONG_GAMESTATEMANAGER_HPP

#include <SDL.h>
#include "../gamestates/States.hpp"
#include "../gamestates/GameState.hpp"

class GameStateManager {
public:
    void setState(States state);
    void step(float dt, SDL_Renderer *renderer);
    void resize(int width, int height);
    void clean();
private:
    GameState *currentState = nullptr;
};


#endif //PONG_GAMESTATEMANAGER_HPP
