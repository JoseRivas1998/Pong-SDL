/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/9/19
**/

#include <iostream>
#include "App.hpp"

void App::startLoop(SDL_Renderer *renderer, States initialState) {
    isRunning = true;
    this->gsm = new GameStateManager;
    this->gsm->setState(initialState);
    this->gameLoop(renderer);
}

void App::gameLoop(SDL_Renderer *renderer) {
    while(isRunning) {
        handleEvents();
        step(renderer);
    }
}

void App::handleWindowEvent(SDL_WindowEvent windowEvent) {
    if(windowEvent.event == SDL_WINDOWEVENT_RESIZED) {
        this->resize(windowEvent.data1, windowEvent.data2);
    }
}

void App::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            this->quit();
            break;
        case SDL_WINDOWEVENT:
            handleWindowEvent(event.window);
            break;
    }
}

void App::step(SDL_Renderer *renderer) {
    SDL_RenderClear(renderer);
    this->gsm->step(renderer);
    SDL_RenderPresent(renderer);
}

void App::quit() {
    this->gsm->clean();
    delete this->gsm;
    this->isRunning = false;
}

void App::resize(int width, int height) {
    this->gsm->resize(width, height);
}

void App::switchState(States state) {
    this->gsm->setState(state);
}