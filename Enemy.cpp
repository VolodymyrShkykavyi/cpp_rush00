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