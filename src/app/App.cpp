/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/9/19
**/

#include "App.hpp"

void App::startLoop(SDL_Renderer *renderer) {
    isRunning = true;
    this->gameLoop(renderer);
}

void App::gameLoop(SDL_Renderer *renderer) {
    while(isRunning) {
        handleEvents();
        step(renderer);
    }
}

void App::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            this->quit();
            break;
    }
}

void App::step(SDL_Renderer *renderer) {

    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);

}

void App::quit() {
    this->isRunning = false;
}
