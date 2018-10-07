#include "Menu.hpp"

Menu::Menu(Game *game) {
	_game = game;
	_currAction = 0;
	_actions[0] = "START GAME";
	_actions[1] = "RESUME GAME";
	_actions[2] = "RESTART GAME";
	_actions[3] = "EXIT";
}

int Menu::checkControls() {
	int key = wgetch(stdscr);
	switch (key) {
		 case KEY_UP:
			 if (!_game->getGameStatus()){
				 if (_currAction > 0)
					 _currAction = 0;
			 } else {
				 if (_currAction > 1)
					 _currAction--;
			 }
			 return KEY_UP;
		case KEY_DOWN:
			if (!_game->getGameStatus()){
				if (_currAction == 0)
					_currAction = 3;
			} else {
				if (_currAction < 3)
					_currAction++;
			}
			return KEY_DOWN;
		case 27: //esc
			return 1;
		case KEY_ENTER:
		case 10:
			return 2;
	}

	return 0;
}

void Menu::runPause() {
	int key = 0;
	_currAction = 1;
	clear();

	while (1) {
		key = checkControls();
		if (key)
			clear();
		drawMenu();
		wrefresh(stdscr);
		if (key == 1) {
			return;
		}
		if (key == 2) {
			if (_currAction == 1)
				return;
			if (_currAction == 2) {
			    _game->restart();
                return;
			}
			if (_currAction == 3) {
				endwin();
				exit(0);
			}
		}
	}
}

void Menu::drawMenu() {

	int	yPos = _game->getTermHeight() / 3;
	int	xPos = _game->getTermWidth() / 2;

    wattron(stdscr, COLOR_PAIR(TEXT_WHITE));
    if (!_game->getGameStatus()) {
		if (_currAction == 0){
            mvwaddstr(stdscr, yPos, xPos - _actions[0].length() / 2 - 2, ">");
            wattron(stdscr, COLOR_PAIR(TEXT_GREEN));
		}
		mvwaddstr(stdscr, yPos++, xPos - _actions[0].length() / 2, _actions[0].c_str());
		wattron(stdscr, COLOR_PAIR(TEXT_WHITE));
	}
	if (_game->getPauseStatus()) {
		if (_currAction == 1){
			mvwaddstr(stdscr, yPos, xPos - _actions[1].length() / 2 - 2, ">");
			wattron(stdscr, COLOR_PAIR(TEXT_GREEN));
		}
		mvwaddstr(stdscr, yPos++, xPos - _actions[1].length() / 2, _actions[1].c_str());
        wattron(stdscr, COLOR_PAIR(TEXT_WHITE));
        if (_currAction == 2){
			mvwaddstr(stdscr, yPos, xPos - _actions[2].length() / 2 - 2, ">");
			wattron(stdscr, COLOR_PAIR(TEXT_GREEN));
		}
		mvwaddstr(stdscr, yPos++, xPos - _actions[2].length() / 2, _actions[2].c_str());
        wattron(stdscr, COLOR_PAIR(TEXT_WHITE));
    }
	if (_currAction == 3){
		mvwaddstr(stdscr, yPos + 1, xPos - _actions[3].length() / 2 - 2, ">");
		wattron(stdscr, COLOR_PAIR(TEXT_GREEN));
	}
	mvwaddstr(stdscr, yPos + 1, xPos - _actions[3].length() / 2, _actions[3].c_str());
    wattron(stdscr, COLOR_PAIR(TEXT_WHITE));
}

void Menu::runStartScreen() {
	_currAction = 0;
	int key = 0;

	clear();
	while (1) {
		if ((key = checkControls()))
			clear();
		drawMenu();
		wrefresh(stdscr);
		if (key == 1) {
			return;
		}
		if (key == 2) {
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

Menu::Menu() {}
Menu::~Menu() {}
Menu::Menu(Menu const &src) {
    *this = src;
}

Menu& Menu::operator=(Menu &src) {
    _game = src._game;

    return *this;
}