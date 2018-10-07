#ifndef MENU_HPP
#define MENU_HPP

#include <ncurses.h>
#include <string>
#include "Game.hpp"
class Game;

class Menu
{
private:
	std::string _actions[4];

	// WINDOW *w_main;
	// WINDOW *w_info;
	// int _mainWidth;
	// int _mainHeight;
	// int _infoWidth;
	// int _infoHeight;
	bool _pause;
	int	_currAction;
	Game *_game;

	Menu();

	void	drawMenu();
	int checkControls();
	void	moveUp();
public:
	Menu(Game *game);

	~Menu();

	void runPause();
	void runStartScreen();
};

#endif