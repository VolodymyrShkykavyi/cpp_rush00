#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <ncurses.h>
#include <string>

class Player
{
private:
    std::string _ico;
    int _xPos;
    int _yPos;
    int _winHeight;
    int _winWidth;
    int _score;
    int _hp;
    int _speed;
    WINDOW  *_win;

public:
    Player(WINDOW  *win);

    int getX();
    int getY();
    int getScore();
    int getHp();
    int getSpeed();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void shoot();
    void draw();
    void updateWindowSize();

};

#endif