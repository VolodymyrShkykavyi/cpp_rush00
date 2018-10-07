#ifndef ENEMY_CPP
#define ENEMY_CPP

#include "MovableObject.hpp"
#define TEXT_GREEN 2
#define TEXT_WHITE 1
#define TEXT_YELLOW 3
#define TEXT_RED 4
#define TEXT_BLUE 5
class Enemy: public MovableObject
{
protected:
    int _hp;
    int _visible;
    int _scoreCost;

public:
    Enemy();
    ~Enemy();
    int getHP();
    int getVisible();
    int getScoreCost();
    void setHP(int val);
    void setVisible(int val);
    void reduceHP();

    void    setDefaults();
};

#endif