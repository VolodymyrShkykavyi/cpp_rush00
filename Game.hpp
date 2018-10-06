#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <string>
//#include <sys/time.h>
#include <ctime>
#include <ncurses.h>

#include "Player.hpp"

#define MIN_WIDTH 20
#define MIN_HEIGHT 10
#define INFO_HEIGHT 3

class Game
{
private:
    WINDOW *w_main;
    WINDOW *w_info;
    bool _pause;
    int _termWidth;
    int _termHeight;


    Player  *_player;


    void    initNcurses();
    void    drawInfo();
    void    drawMain();
    void    checkControls();

public:
    Game();
    ~Game();
    Game(Game const &src);
    Game & operator=(Game const &other);

    void    run();
};

#endif