#ifndef GAME_HPP
# define GAME_HPP

#define MIN_WIDTH 20
#define MIN_HEIGHT 10
#define INFO_HEIGHT 3
#define TEXT_GREEN 2
#define TEXT_WHITE 1
#define TEXT_YELLOW 3
#define TEXT_RED 4
#define TEXT_BLUE 5
#define SIMPLE_ENEMY_MAX 50
#define MIDDLE_ENEMY_MAX 10
#define BACKGROUND_MAX 50

#include <iostream>
#include <string>
//#include <sys/time.h>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#include <unistd.h>

#include "Player.hpp"
#include "Menu.hpp"
#include "SimpleEnemy.hpp"
#include "MiddleEnemy.hpp"
#include "Enemy.hpp"

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
    MiddleEnemy *_enemies_middle[MIDDLE_ENEMY_MAX];
    Bullet *_enemies_bullets[ENEMY_BULLETS_MAX];
    Enemy   *_background[BACKGROUND_MAX];
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