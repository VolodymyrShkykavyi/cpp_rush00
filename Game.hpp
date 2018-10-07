#ifndef GAME_HPP
# define GAME_HPP

#define MIN_WIDTH 20
#define MIN_HEIGHT 10
#define INFO_HEIGHT 3
#define TEXT_GREEN 2
#define TEXT_WHITE 1
#define SIMPLE_ENEMY_MAX 50

#include <iostream>
#include <string>
//#include <sys/time.h>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>

#include "Player.hpp"
#include "Menu.hpp"
#include "SimpleEnemy.hpp"


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
    SimpleEnemy *_enemies_simple[SIMPLE_ENEMY_MAX];
    Menu    *_menu;

    void    initNcurses();
    void    drawInfo();
    void    drawMain();
    void    drawFinalScreen();
    void    checkControls();
    void    checkBulletCollision();
    void    checkEnemyCollision();
    void    addEnemies();
    void    moveEnemies();

public:
    Game();
    ~Game();
    Game(Game const &src);
    Game & operator=(Game const &other);

    void    run();
    void    restart();
    bool    getGameStatus();
    bool    getPauseStatus();
	int		getTermHeight();
	int		getTermWidth();
};

#endif