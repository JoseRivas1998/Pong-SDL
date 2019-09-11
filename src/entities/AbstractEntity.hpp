/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/10/19
**/

#ifndef PONG_ABSTRACTENTITY_HPP
#define PONG_ABSTRACTENTITY_HPP

#include <SDL.h>
#include "../math/Rectangle.hpp"

class AbstractEntity {
public:
    AbstractEntity();
    virtual ~AbstractEntity() = default;
    virtual void update(float dt) = 0;
    virtual void draw(float dt, SDL_Renderer *renderer) = 0;
    float getX();
    void setX(float x);
    float getY();
    void setY(float y);
    Vector2 getPosition();
    void setPosition(float x, float y);
    void setPosition(const Vector2 &point);
    float getWidth();
    void setWidth(float width);
    float getHeight();
    void setHeight(float height);
    Vector2 getSize();
    void setSize(float width, float height);
    void setSize(const Vector2 &size);
    Rectangle getBounds();
    float getVelocityX();
    void setVelocityX(float x);
    float getVelocityY();
    void setVelocityY(float y);
    Vector2 getVelocity();
    void setVelocity(float x, float y);
    void setVelocity(const Vector2 &vel);
    float getSpeed();
    void setSpeed(float speed);
    float getDirection();
    float getDirectionDeg();
    void setDirection(float radians);
    void setDirectionDeg(float degrees);
protected:
    void applyVelocity(float dt);
private:
    Rectangle bounds;
    Vector2 velocity;
    static int entitiesCreated;
    int id;
};


#endif //PONG_ABSTRACTENTITY_HPP
