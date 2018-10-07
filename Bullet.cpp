#include "Bullet.hpp"

Bullet::Bullet(int y, int x, int direction, WINDOW  *win) {
    _xPos = x;
    _yPos = y;
    _direction = direction;
    w_main = win;
    _ico = "•";
    _visible = 0;
    _speed = 1;
}

int Bullet::getVisIble() {
    return _visible;
}

void Bullet::setVisible(int val) {
    _visible = val;
}

void Bullet::draw() {
    if (_visible)
        mvwprintw(w_main, _yPos,_xPos, _ico.c_str());
}

void Bullet::move() {
    if (_visible)
        _yPos += _direction * (_speed / 200 );
}

