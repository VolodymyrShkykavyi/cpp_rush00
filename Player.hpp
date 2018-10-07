#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <ncurses.h>
#include <string>
#include "Bullet.hpp"
#define TEXT_GREEN 2
#define TEXT_WHITE 1
#define TEXT_YELLOW 3
#define TEXT_RED 4
#define TEXT_BLUE 5

#define PLAYER_BULLETS_NUM 100

class Player
{
private:
    std::string _ico;
    int		_xPos;
    int		_yPos;
    int		_winHeight;
    int		_winWidth;
    int		_score;
    int		_hp;
	int		_speed;
	time_t	_timeSet;

    WINDOW  *_win;
    Bullet  *_bullets[PLAYER_BULLETS_NUM];

    Player();

public:
    Player(WINDOW  *win);

    Player(Player const &src);
    Player &operator=(Player &src);
    ~Player();
    int getX();
    int getY();
    int getScore();
    int getHp();
    int getSpeed();
    Bullet  **getBullets();
    void	setTime();
    void	fixPauseTime( time_t );
    time_t	getTime();

    void addScore(int val);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void shoot();
    void draw();
    void updateWindowSize();
    void reduceHP();

};

#endif