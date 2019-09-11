/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/11/19
**/

#ifndef PONG_AIPADDLE_HPP
#define PONG_AIPADDLE_HPP


#include "AbstractEntity.hpp"
#include "Ball.hpp"

class AIPaddle : public AbstractEntity{
public:
    AIPaddle(float width, float height);

    void updateTarget(Ball ball);

    void update(float dt) override;

    void draw(float dt, SDL_Renderer *renderer) override;
private:
    float y_speed = 0;
    float target_y;
};


#endif //PONG_AIPADDLE_HPP
