//
// Created by joserivas1998 on 9/10/19.
//

#ifndef PONG_BALL_HPP
#define PONG_BALL_HPP


#include "AbstractEntity.hpp"

class Ball : public AbstractEntity {
public:

    explicit Ball(float size);

    void reset();

    void update(float dt) override;

    void draw(float dt, SDL_Renderer *renderer) override;

    void bounceY();

    void bounceX();

private:

    constexpr static float BALL_SPEED = 500.0f;
};


#endif //PONG_BALL_HPP
