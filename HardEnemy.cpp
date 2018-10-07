#include "HardEnemy.hpp"

HardEnemy::HardEnemy(WINDOW *win, Bullet **bullets, Player *pl) {
    w_main = win;
    _bullets = bullets;
    _player = pl;
    setDefaults();

}

void HardEnemy::setDefaults() {
    int termHeight;
    int termWidth;

    getmaxyx(stdscr, termHeight, termWidth);
    _lvl = 1;
    _hp = 10;
    _scoreCost = 30;
    _visible = 0;
    _speed = 5;
    _direction = 1;
    _xPos = rand() % termWidth;
    _yPos = 0;
    _ico = "\\V^V/";
}

void HardEnemy::shoot() {
    int n = -1;
    for (int i = 0; i < ENEMY_BULLETS_MAX; i++) {
        if (!_bullets[i]->getVisIble()) {
            _bullets[i]->setVisible(1);
            _bullets[i]->setX(_xPos + n);
            _bullets[i]->setY(_yPos + 1);
            n += 2;
        }
        if (n > 1)
            return;
    }
}

void HardEnemy::move() {

    if (_player->getX() >= _xPos - 1 && _player->getX() <= _xPos + 1) {
        _direction = 0;
    } else if (_player->getX() >= _xPos) {
        _direction = 1;
    } else if (_player->getX() < _xPos) {
        _direction = -1;
    }
    _xPos += _direction * (_speed / 100);
}

void HardEnemy::draw() {
    wattron(w_main, COLOR_PAIR(TEXT_YELLOW));
    wattron(w_main, WA_BOLD);
    mvwprintw(w_main, _yPos, _xPos - 1, _ico.c_str());
    wattron(w_main, COLOR_PAIR(TEXT_WHITE));
    wattroff(w_main, WA_BOLD);
}

void HardEnemy::upgradeLvl() {
    _lvl++;
    _hp = _lvl * 10;
    _speed += 0.5;
    _scoreCost += _lvl * 7;
}
