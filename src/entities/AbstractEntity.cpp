/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/10/19
**/

#include "AbstractEntity.hpp"

int AbstractEntity::entitiesCreated = 0;

AbstractEntity::AbstractEntity() {
    this->bounds.set(Rectangle(0, 0, 0, 0));
    this->velocity.set(0, 0);
    this->id = AbstractEntity::entitiesCreated++;
}

float AbstractEntity::getX() {
    return this->bounds.x;
}

void AbstractEntity::setX(float x) {
    this->bounds.x = x;
}

float AbstractEntity::getY() {
    return this->bounds.y;
}

void AbstractEntity::setY(float y) {
    this->bounds.y = y;
}

Vector2 AbstractEntity::getPosition() {
    return Vector2(this->bounds.x, this->bounds.y);
}

void AbstractEntity::setPosition(float x, float y) {
    this->setX(x);
    this->setY(y);
}

void AbstractEntity::setPosition(const Vector2 &point) {
    this->setPosition(point.x, point.y);
}

float AbstractEntity::getWidth() {
    return this->bounds.width;
}

void AbstractEntity::setWidth(float width) {
    this->bounds.width = width;
}

float AbstractEntity::getHeight() {
    return this->bounds.height;
}

void AbstractEntity::setHeight(float height) {
    this->bounds.height = height;
}

Vector2 AbstractEntity::getSize() {
    return Vector2(this->bounds.width, this->bounds.height);
}

void AbstractEntity::setSize(float width, float height) {
    this->setWidth(width);
    this->setHeight(height);
}

void AbstractEntity::setSize(const Vector2 &size) {
    this->setSize(size.x, size.y);
}

Rectangle AbstractEntity::getBounds() {
    return Rectangle(this->bounds);
}

float AbstractEntity::getVelocityX() {
    return this->velocity.x;
}

void AbstractEntity::setVelocityX(float x) {
    this->velocity.x = x;
}

float AbstractEntity::getVelocityY() {
    return this->velocity.y;
}

void AbstractEntity::setVelocityY(float y) {
    this->velocity.y = y;
}

Vector2 AbstractEntity::getVelocity() {
    return Vector2(this->velocity);
}

void AbstractEntity::setVelocity(float x, float y) {
    this->velocity.set(x, y);
}

void AbstractEntity::setVelocity(const Vector2 &vel) {
    this->velocity.set(vel);
}

float AbstractEntity::getSpeed() {
    return this->velocity.mag();
}

void AbstractEntity::setSpeed(float speed) {
    float radians = this->velocity.angle();
    this->velocity.set(Vector2::polar(speed, radians));
}

float AbstractEntity::getDirection() {
    return this->velocity.angle();
}

float AbstractEntity::getDirectionDeg() {
    return this->velocity.angleDeg();
}

void AbstractEntity::setDirection(float radians) {
    float speed = this->velocity.mag();
    this->velocity.set(Vector2::polar(speed, radians));
}

void AbstractEntity::setDirectionDeg(float degrees) {
    float speed = this->velocity.mag();
    this->velocity.set(Vector2::polarDeg(speed, degrees));
}

void AbstractEntity::applyVelocity(float dt) {
    this->bounds.addToPosition(this->velocity, dt);
}
