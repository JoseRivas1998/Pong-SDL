/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/9/19
**/

#ifndef PONG_APP_HPP
#define PONG_APP_HPP

#include <SDL.h>

#include "../managers/GameStateManager.hpp"
#include "../graphics/Color.hpp"

class App {
public:
    void startLoop(SDL_Renderer *renderer, States initialState);
    void switchState(States state);
    void clean();
    void setClearColor(const Color &c);
    float getDeltaTime();
private:
    bool isRunning = false;
    void gameLoop(SDL_Renderer *renderer);
    void handleEvents();
    void handleWindowEvent(SDL_WindowEvent windowEvent);
    void step(SDL_Renderer *renderer);
    void resize(int width, int height);
    void quit();
    Color clearColor;
    GameStateManager *gsm = nullptr;
    void calculateDeltaTime();
    Uint64 lastTime = 0;
    float deltaTime = 0.0f;

};


#endif //PONG_APP_HPP
