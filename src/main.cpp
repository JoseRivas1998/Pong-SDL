#include <iostream>

#include "app/LichPP.hpp"

int main(int argc, char **argv) {

    ApplicationConfiguration config;
    config.title = "Pong";
    config.xPos = SDL_WINDOWPOS_CENTERED;
    config.yPos = SDL_WINDOWPOS_CENTERED;
    config.width = 800;
    config.height = 600;
    config.fullScreen = false;
    config.resizable = true;

    if(!LichPP::init(config)) {
        LichPP::destroy();
        return -1;
    }

    LichPP::app->startLoop(LichPP::graphics->renderer, States::Play);

	LichPP::destroy();
	return 0;
}
