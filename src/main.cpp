#include <iostream>

#include "app/LichPP.hpp"
#include "input/PongInputProcessor.hpp"

int main(int argc, char **argv) {

    ApplicationConfiguration config;
    config.title = "Pong";
    config.xPos = SDL_WINDOWPOS_CENTERED;
    config.yPos = SDL_WINDOWPOS_CENTERED;
    config.width = 800;
    config.height = 600;
    config.fullScreen = false;
    config.resizable = true;
    config.clearColor.set(0x00, 0x00, 0x00, 0xFF);

    if(!LichPP::init(config)) {
        LichPP::destroy();
        return -1;
    }

    LichPP::app->addInputListener(new PongInputProcessor());

    LichPP::app->startLoop(LichPP::graphics->renderer, States::Play);
    LichPP::app->clean();
	LichPP::destroy();
	return 0;
}
