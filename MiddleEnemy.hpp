#ifndef MIDDLEENEMY_CPP
#define MIDDLEENEMY_CPP

#define ENEMY_BULLETS_MAX 100

#include "Enemy.hpp"
#include "Bullet.hpp"
#include <ncurses.h>

class MiddleEnemy: public Enemy
{
private:
    Bullet **_bullets;
public:
    MiddleEnemy(WINDOW *win, Bullet **bullets);
	MiddleEnemy();
	~MiddleEnemy();

	MiddleEnemy(MiddleEnemy const &src);
    MiddleEnemy & operator=(MiddleEnemy const &rhs);
    void setDefaults();
    void shoot();
};

#endif