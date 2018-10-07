#ifndef HARDENEMY_CPP
#define HARDENEMY_CPP

#define ENEMY_BULLETS_MAX 100

#include "Enemy.hpp"
#include "Bullet.hpp"
#include <ncurses.h>
#include "Player.hpp"


class HardEnemy: public Enemy
{
private:
    Bullet **_bullets;
    Player  *_player;
    int _lvl;
    HardEnemy();
public:
    HardEnemy(WINDOW *win, Bullet **bullets, Player *pl);
    ~HardEnemy();
    HardEnemy(HardEnemy const &src);
    HardEnemy &operator=(HardEnemy const &src);

    void setDefaults();
    void shoot();
    void move();
    void draw();
    void upgradeLvl();

};

#endif