#include "MovableObject.hpp"

//just for coplien form
MovableObject::MovableObject() {}
MovableObject::~MovableObject() {}
MovableObject::MovableObject(MovableObject const &obj) {
    _xPos = obj._xPos;
    _yPos = obj._yPos;
    _direction = obj._direction;
}
MovableObject& MovableObject::operator=(MovableObject const &object) {
    _xPos = object._xPos;
    _yPos = object._yPos;
    _direction = object._direction;

    return *this;
}

void MovableObject::move() {
    _yPos += _direction * (_speed / 200);
}

void MovableObject::draw() {
    mvwprintw(w_main, _yPos,_xPos, _ico.c_str());
}

int MovableObject::getDirection() {
    return _direction;
}

int MovableObject::getSpeed() {
    return _speed;
}

int MovableObject::getX() {
    return _xPos;
}

int MovableObject::getY() {
    return _yPos;
}

void MovableObject::setDirection(int dir) {
    _direction = dir;
}

void MovableObject::setSpeed(int speed) {
    _speed = speed;
}

void MovableObject::setX(int x) {
    _xPos = x;
}

void MovableObject::setY(int y) {
    _yPos = y;
}

void MovableObject::setIco(std::string ico) {
    _ico = ico;
}