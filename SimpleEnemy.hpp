#ifndef SIMPLEENEMY_CPP
#define SIMPLEENEMY_CPP

#include "Enemy.hpp"
#include <ncurses.h>

class SimpleEnemy: public Enemy
{
private:
    std::string _icons[3];

public:
    SimpleEnemy(WINDOW *win);

    void setDefaults();
};

#endif