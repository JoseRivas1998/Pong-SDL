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
#include "../input/InputMultiplexer.hpp"

class App {
public:
    void startLoop(SDL_Renderer *renderer, States initialState);
    void switchState(States state);
    void clean();
    void setClearColor(const Color &c);
    float getDeltaTime();
    void addInputListener(InputListener *listener);
    void quit();
private:
    bool isRunning = false;
    void gameLoop(SDL_Renderer *renderer);
    void handleEvents();
    void handleWindowEvent(SDL_WindowEvent windowEvent);
    void handleKeyboardEvent(SDL_KeyboardEvent keyboardEvent);
    void step(SDL_Renderer *renderer);
    void resize(int width, int height);
    Color clearColor;
    GameStateManager *gsm = nullptr;
    void calculateDeltaTime();
    Uint64 lastTime = 0;
    float deltaTime = 0.0f;
    InputMultiplexer inputMultiplexer;

};


#endif //PONG_APP_HPP
