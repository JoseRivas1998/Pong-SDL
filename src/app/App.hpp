/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/9/19
**/

#ifndef PONG_APP_HPP
#define PONG_APP_HPP

#include <SDL.h>

#include "../managers/GameStateManager.hpp"

class App {
public:
    void startLoop(SDL_Renderer *renderer, States initialState);
    void switchState(States state);
private:
    bool isRunning = false;
    void gameLoop(SDL_Renderer *renderer);
    void handleEvents();
    void handleWindowEvent(SDL_WindowEvent windowEvent);
    void step(SDL_Renderer *renderer);
    void resize(int width, int height);
    void quit();
    GameStateManager *gsm = nullptr;

};


#endif //PONG_APP_HPP
