/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/9/19
**/

#include "LichPP.hpp"

#include <iostream>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

Graphics *LichPP::graphics = nullptr;

App *LichPP::app = nullptr;

AssetManager *LichPP::assets = nullptr;

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

    if (TTF_Init() == 0) {
        println("TTF Subsystems initialized.");
    } else {
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

    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == 0 ) {
        println("Audio Subsystems initialized.");
    } else {
        println("SDL_mixer error");
        println(Mix_GetError());
        return false;
    }

    LichPP::assets = new AssetManager();
    LichPP::assets->addFont("main", "../assets/prstartk.ttf", 36, Color(Colors::WHITE));
    LichPP::assets->addFont("title", "../assets/prstartk.ttf", 48, Color(Colors::WHITE));

    LichPP::assets->addSoundEffect("beep", "../assets/sound/ping_pong_8bit_beeep.wav");
    LichPP::assets->addSoundEffect("peep", "../assets/sound/ping_pong_8bit_peeeeeep.wav");
    LichPP::assets->addSoundEffect("plop", "../assets/sound/ping_pong_8bit_plop.wav");


    return true;
}

void LichPP::destroy() {
    delete LichPP::graphics;
    delete LichPP::app;
    delete LichPP::assets;
    SDL_Quit();
    Mix_Quit();
    println("Game cleaned!");
}
