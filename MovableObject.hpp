#ifndef MOVABLEOBJECT_HPP
#define MOVABLEOBJECT_HPP

#include <string>
#include <ncurses.h>

class MovableObject
{
private:
    MovableObject &operator=(MovableObject const &object);
    MovableObject(MovableObject const &obj);
protected:
    float _xPos;
    float _yPos;
    int _direction;
    float _speed;
    std::string _ico;
    WINDOW  *w_main;

public:
    MovableObject();
    ~MovableObject();

    void move();
    void draw();

    int getX();
    int getY();
    int getDirection();
    int getSpeed();
    void setX(int x);
    void setY(int y);
    void setDirection(int dir);
    void setSpeed(int speed);
};

#endif