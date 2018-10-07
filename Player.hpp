#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <ncurses.h>
#include <string>
#include "Bullet.hpp"
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

public:
    Player(WINDOW  *win);

    ~Player();
    int		getX();
    int		getY();
    int		getScore();
    int		getHp();
	void	setTime();
	void	fixPauseTime( time_t );
	time_t	getTime();

    int		getSpeed();
    void	moveUp();
    void	moveDown();
    void	moveLeft();
    void	moveRight();
    void	shoot();
    void	draw();
    void	updateWindowSize();

};

#endif