#include "MiddleEnemy.hpp"

MiddleEnemy::MiddleEnemy(WINDOW *win, Bullet **bullets) {
    w_main = win;
    _bullets = bullets;
}

void MiddleEnemy::setDefaults() {
    int     termHeight;
    int     termWidth;

    getmaxyx(stdscr, termHeight, termWidth);
    _hp = 2;
    _scoreCost = 3;
    _visible = 0;
    _speed = 1;
    _direction = 1;
    _xPos = rand() % termWidth;
    _yPos = 0;
    _ico = "🐉";
}

void MiddleEnemy::shoot() {
    for (int i = 0; i < ENEMY_BULLETS_MAX; i++) {
        if (!_bullets[i]->getVisIble()){
            _bullets[i]->setVisible(1);
            _bullets[i]->setX(_xPos);
            _bullets[i]->setY(_yPos);
            return;
        }
    }
}