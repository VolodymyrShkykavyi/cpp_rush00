#include "Player.hpp"

Player::Player(WINDOW *win) {
    _ico = "0";
    _win = win;
    _speed = 1;
    updateWindowSize();
    _xPos = _winWidth / 2;
    _yPos = _winHeight - 2;
}

void Player::updateWindowSize() {
    getmaxyx(_win, _winHeight, _winWidth);
}


void Player::moveUp() {
    if (_yPos > 0)
        _yPos--;
}

void Player::moveDown() {
    if (_yPos < _winHeight)
        _yPos++;
}

void Player::moveLeft() {
    if (_xPos > 0)
        _xPos--;
}

void Player::moveRight() {
    if (_xPos < _winWidth)
        _xPos++;
}

void Player::draw() {
    mvwaddstr(this->_win, this->_yPos, this->_xPos, this->_ico.c_str());
}

void Player::shoot() {
    //TODO: logic
}

//getters


int Player::getHp() {
    return _hp;
}

int Player::getScore() {
    return _score;
}

int Player::getX() {
    return _xPos;
}

int Player::getY() {
    return _yPos;
}

int Player::getSpeed() {
    return _speed;
}
