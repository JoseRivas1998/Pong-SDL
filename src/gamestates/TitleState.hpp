/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/12/19
**/

#ifndef PONG_TITLESTATE_HPP
#define PONG_TITLESTATE_HPP


#include "GameState.hpp"
#include "../graphics/Font.hpp"

class TitleState : public GameState {
public:

    void init() override;

    void clean() override;

    void handleInput(float dt) override;

    void update(float dt) override;

    void draw(float dt, SDL_Renderer *renderer) override;

    void resize(int width, int height) override;
private:
    Font *font;
    Font *smaller;
};


#endif //PONG_TITLESTATE_HPP
