#ifndef ENEMY_CPP
#define ENEMY_CPP

#include "MovableObject.hpp"

class Enemy: public MovableObject
{
protected:
    int _hp;
    int _visible;
    int _scoreCost;

public:
    int getHP();
    int getVisible();
    int getScoreCost();
    void setHP(int val);
    void setVisible(int val);
    void reduceHP();
};

#endif