#include "Menu.hpp"

Menu::Menu(WINDOW *main, WINDOW *info) {
	getmaxyx(w_main, _mainHeight, _mainWidth);
	getmaxyx(w_info, _infoHeight, _infoWidth);
	_pause = 0;
	_currAction = 0;
	_actions[0] = "START GAME";
	_actions[1] = "RESUME GAME";
	_actions[2] = "RESTART GAME";
	_actions[3] = "EXIT";
}

int	Menu::checkControls() {
	int key = wgetch(stdscr);
	switch (key) {
		case KEY_UP:
			moveUp();
			break;
		case KEY_DOWN:
			moveDown();
			break;
		case 27: //esc
			if (_pause) {
				_pause = 0;
				return 1;
			}
			break;
	}

	return 0;
}

void Menu::runPause() {
	_pause = 1;
	_currAction = 1;

	while (1) {
		mvwaddstr(w_main, 0, 12, "qweqwe");
		wrefresh(w_main);
		if (checkControls() == 1) {
			return;
		}
	}
}