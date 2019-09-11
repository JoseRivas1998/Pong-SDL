/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/9/19
**/

#ifndef PONG_PLAYSTATE_HPP
#define PONG_PLAYSTATE_HPP

#include "GameState.hpp"
#include "../math/Rectangle.hpp"
#include "../entities/Ball.hpp"
#include "../entities/Player.hpp"
#include "../entities/AiPaddle.hpp"

constexpr float BALL_SIZE = 25.0f;
constexpr float PADDLE_HEIGHT = BALL_SIZE * 2.5f;

class PlayState : public GameState {

public:

    PlayState() : ball(BALL_SIZE), player(BALL_SIZE, PADDLE_HEIGHT), aiPaddle(BALL_SIZE, PADDLE_HEIGHT) {};

    void init() override;

    void clean() override;

    void handleInput(float dt) override;

    void update(float dt) override;

    void draw(float dt, SDL_Renderer *renderer) override;

    void resize(int width, int height) override;

private:
    constexpr static float BALL_SIZE = 25.0f;
    Ball ball;
    Player player;
    AIPaddle aiPaddle;
};


#endif //PONG_PLAYSTATE_HPP
