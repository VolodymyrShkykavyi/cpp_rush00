#include "SimpleEnemy.hpp"

SimpleEnemy::SimpleEnemy() {}
SimpleEnemy::~SimpleEnemy() {}

SimpleEnemy::SimpleEnemy(SimpleEnemy const &src) {
    *this = src;
}

SimpleEnemy& SimpleEnemy::operator=(SimpleEnemy &src) {
    _hp = src._hp;
    _xPos = src._xPos;

    return *this;
}

void SimpleEnemy::setDefaults() {
    int     termHeight;
    int     termWidth;

    getmaxyx(stdscr, termHeight, termWidth);
    _hp = 1;
    _scoreCost = 1;
    _visible = 0;
    _speed = 10;
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

void SimpleEnemy::draw() {
    wattron(w_main, COLOR_PAIR(TEXT_RED));
    mvwprintw(w_main, _yPos,_xPos, _ico.c_str());
    wattron(w_main, COLOR_PAIR(TEXT_WHITE));

}