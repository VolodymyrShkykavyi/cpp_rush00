#include "SimpleEnemy.hpp"

void SimpleEnemy::setDefaults() {
    int     termHeight;
    int     termWidth;

    getmaxyx(stdscr, termHeight, termWidth);
    _hp = 1;
    _scoreCost = 1;
    _visible = 0;
    _speed = 1;
    _direction = 1;
    _xPos = rand() % termWidth;
    _yPos = 0;
    _ico = _icons[rand() % 3];

}

SimpleEnemy::SimpleEnemy(WINDOW *win) {
    _icons[0] = "W";
    _icons[1] = "◈";
    _icons[2] = "▣";
    w_main = win;
    setDefaults();
}