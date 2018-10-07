#include "Player.hpp"

Player::Player(WINDOW *win) {
    _ico = "📟";
//_ico = "▲";
    _win = win;
    _speed = 1;
    _hp = 3;
    updateWindowSize();
    _xPos = _winWidth / 2;
    _yPos = _winHeight - 2;

    for (int i = 0; i < PLAYER_BULLETS_NUM; i++) {
        _bullets[i] = new Bullet(0, 0, -1, _win);
    }
}

void Player::updateWindowSize() {
    getmaxyx(_win, _winHeight, _winWidth);
}


void Player::moveUp() {
    if (_yPos > 0)
        _yPos--;
}

void Player::moveDown() {
    if (_yPos < _winHeight - 1)
        _yPos++;
}

void Player::moveLeft() {
    if (_xPos > 0)
        _xPos--;
}

void Player::moveRight() {
    if (_xPos < _winWidth - 2)
        _xPos++;
}

void Player::draw() {
    mvwprintw(this->_win, this->_yPos, this->_xPos, this->_ico.c_str());
    for(int i = 0; i < PLAYER_BULLETS_NUM; i++){
        if (_bullets[i]->getVisIble()) {
            _bullets[i]->move();
            if (_bullets[i]->getY() < 0)
                _bullets[i]->setVisible(0);
            wattron(_win, COLOR_PAIR(TEXT_YELLOW));
            _bullets[i]->draw();
            wattron(_win, COLOR_PAIR(TEXT_WHITE));
        }
    }
}

void Player::shoot() {
    for (int i = 0; i < PLAYER_BULLETS_NUM; i++) {
        if (!_bullets[i]->getVisIble()){
            _bullets[i]->setVisible(1);
            _bullets[i]->setX(_xPos);
            _bullets[i]->setY(_yPos);
            return;
        }
    }
}

void Player::reduceHP() {
    if (_hp > 0)
        _hp--;
}

void Player::addScore(int val) {
    _score += val;
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

Bullet** Player::getBullets() {
    return  _bullets;
}

Player::~Player() {
    for (int i = 0; i < PLAYER_BULLETS_NUM; i++)
        delete _bullets[i];
}

void	Player::setTime() {
	_timeSet = time(0);
}

time_t	Player::getTime() {
	return (this->_timeSet);
}

void	Player::fixPauseTime( time_t pauseTime ) {
	this->_timeSet += pauseTime;
}

