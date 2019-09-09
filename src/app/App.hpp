/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/9/19
**/

#ifndef PONG_APP_HPP
#define PONG_APP_HPP

#include <SDL.h>

class App {
public:
    void startLoop(SDL_Renderer *renderer);
private:
    bool isRunning = false;
    void gameLoop(SDL_Renderer *renderer);
    void handleEvents();
    void step(SDL_Renderer *renderer);
    void quit();

};


#endif //PONG_APP_HPP
