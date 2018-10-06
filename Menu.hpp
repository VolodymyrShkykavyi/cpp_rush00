#ifndef MENU_HPP
#define MENU_HPP

#include <ncurses.h>

class Menu
{
private:
	std::string _actions[4];

	WINDOW *w_main;
	WINDOW *w_info;
	int _mainWidth;
	int _mainHeight;
	int _infoWidth;
	int _infoHeight;
	bool _pause;
	int	_currAction;

	Menu();

	int checkControls();
	void	moveUp();
public:
	Menu(WINDOW *main, WINDOW *info);

	~Menu();

	void runPause();
	void runStartScreen();
};

#endif