//
// Created by joserivas1998 on 9/10/19.
//

#ifndef PONG_PLAYER_HPP
#define PONG_PLAYER_HPP


#include "AbstractEntity.hpp"

class Player : public AbstractEntity {
public:

    Player(float width, float height);

    void handleInput();

    void update(float dt) override;

    void draw(float dt, SDL_Renderer *renderer) override;

private:
    constexpr static float PLAYER_SPEED = 400.0f;
};


#endif //PONG_PLAYER_HPP
