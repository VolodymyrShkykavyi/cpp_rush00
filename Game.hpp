#ifndef GAME_HPP
#define GAME_HPP

#define MIN_WIDTH 20
#define MIN_HEIGHT 10
#define INFO_HEIGHT 3
#define TEXT_GREEN 2
#define TEXT_WHITE 1

#include <iostream>
#include <string>
//#include <sys/time.h>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>

#include "Player.hpp"
#include "Menu.hpp"

class Menu;
class Game
{
private:
    WINDOW *w_main;
    WINDOW *w_info;
    bool _pause;
    bool _game;
    int _termWidth;
    int _termHeight;

    Player  *_player;
    Menu    *_menu;

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

    bool    getGameStatus();
    bool    getPauseStatus();
	int		getTermHeight();
	int		getTermWidth();
};

#endif