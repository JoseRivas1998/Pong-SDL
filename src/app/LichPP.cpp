/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/9/19
**/

#include "LichPP.hpp"

#include <iostream>

Graphics *LichPP::graphics = nullptr;

App *LichPP::app = nullptr;

void println(const char *str) {
    std::cout << str << std::endl;
}

void printError() {
    println(SDL_GetError());
}

bool LichPP::init(ApplicationConfiguration appConfig) {
    LichPP::graphics = new Graphics();
    Uint32 flags = 0;
    if (appConfig.fullScreen) {
        flags |= SDL_WINDOW_FULLSCREEN;
    }
    if (appConfig.resizable) {
        flags |= SDL_WINDOW_RESIZABLE;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        println("Subsystems initialized");
    } else {
        printError();
        return false;
    }

    LichPP::graphics->window = SDL_CreateWindow(appConfig.title, appConfig.xPos, appConfig.yPos, appConfig.width,
                                                appConfig.height, flags);
    if (LichPP::graphics->window) {
        println("Window created");
    } else {
        printError();
        return false;
    }

    LichPP::graphics->renderer = SDL_CreateRenderer(LichPP::graphics->window, -1, 0);
    if (LichPP::graphics->renderer) {
        println("Renderer created!");
    } else {
        printError();
        return false;
    }

    LichPP::app = new App();
    LichPP::app->setClearColor(appConfig.clearColor);

    return true;
}

void LichPP::destroy() {
    delete LichPP::graphics;
    SDL_Quit();
    println("Game cleaned!");
}
