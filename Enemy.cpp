#include "Enemy.hpp"

void Enemy::setVisible(int val) {
    _visible = val;
}

void Enemy::setHP(int val) {
    _hp = val;
}

int Enemy::getHP() {
    return _hp;
}

int Enemy::getVisible() {
    return _visible;
}

void Enemy::reduceHP() {
    _hp--;
    if (_hp <= 0)
        _visible = 0;
}

int Enemy::getScoreCost() {
    return _scoreCost;
}

void Enemy::setDefaults() {
    int     termHeight;
    int     termWidth;

    getmaxyx(stdscr, termHeight, termWidth);
    _hp = 1;
    _visible = 0;
    _scoreCost = 0;
    _direction = 1;
    _speed = 1;
    _xPos = rand() % termWidth;
    _yPos = 0;
}

Enemy::Enemy() {
    setDefaults();
}

Enemy::~Enemy() {}