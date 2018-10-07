#include "Menu.hpp"

Menu::Menu(Game *game) {
	// getmaxyx(w_main, _mainHeight, _mainWidth);
	// getmaxyx(w_info, _infoHeight, _infoWidth);
	// w_main = main;
	// w_info = info;
	_game = game;
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
		// case KEY_UP:
		// 	moveUp();
		// 	break;
		case KEY_DOWN:
			_currAction = 3;
			break;
		case 27: //esc
			if (_pause) {
				_pause = 0;
				return 1;
			}
			// return 2;
			break;
		case KEY_ENTER:
			return 2;
			break;
	}

	return 0;
}

void Menu::runPause() {
	_pause = 1;
	_currAction = 1;
	clear();

	while (1) {
		mvwaddstr(stdscr, 0, 12, _actions[1].c_str());
		wrefresh(stdscr);
		if (checkControls() == 1) {
			return;
		}
	}
}

void Menu::drawMenu() {
	if (!_game->getGameStatus())
		mvwaddstr(stdscr, 0, 12, _actions[0].c_str());
	if (_game->getPauseStatus()){
		mvwaddstr(stdscr, 1, 12, _actions[1].c_str());
		mvwaddstr(stdscr, 2, 12, _actions[2].c_str());
	}
	mvwaddstr(stdscr, 3, 12, _actions[3].c_str());

}

void Menu::runStartScreen() {
	_pause = 0;
	_currAction = 0;
	int key = 0;

	clear();
	while (1) {
		drawMenu();
		wrefresh(stdscr);
		key = checkControls();
		if (key == 1) {
			return;
		}
		if (key == 2) {
			//actions
			if (_currAction == 0) {
				return;
			}
			if (_currAction == 3) {
				endwin();
				exit(0);
			}
		}
	}
}