#ifndef SIMPLEENEMY_CPP
#define SIMPLEENEMY_CPP

#include "Enemy.hpp"
#include <ncurses.h>

class SimpleEnemy: public Enemy
{
private:
    std::string _icons[3];
    SimpleEnemy();
public:
    SimpleEnemy(WINDOW *win);
    ~SimpleEnemy();
    SimpleEnemy(SimpleEnemy const &src);
    SimpleEnemy &operator=(SimpleEnemy &src);

    void setDefaults();
    void draw();
};

#endif