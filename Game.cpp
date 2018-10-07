#include "Game.hpp"

void Game::initNcurses() {
	if (!initscr()) {
		std::cout << "Can't initialize ncurses" << std::endl;
		endwin();
		exit(1);
	}

	noecho();
	keypad(stdscr, TRUE);
	cbreak();
	curs_set(0); //no cursor
	nodelay(stdscr, true);
	clear();
	start_color();
	getmaxyx(stdscr, _termHeight, _termWidth);

	if (_termWidth < MIN_WIDTH || _termHeight < MIN_HEIGHT) {
		std::cout << "Small terminal size. Min height:"
				  << MIN_HEIGHT << " lines, min width: "
				  << MIN_WIDTH << " columns" << std::endl;
		endwin();
		exit(0);
	}
	this->w_main = newwin(_termHeight - INFO_HEIGHT, _termWidth, INFO_HEIGHT, 0);
	this->w_info = newwin(INFO_HEIGHT, _termWidth, 0, 0);

	init_pair(TEXT_GREEN, COLOR_GREEN, COLOR_BLACK);
	init_pair(TEXT_WHITE, COLOR_WHITE, COLOR_BLACK);

	//init info window

	//init main window
}

void Game::drawInfo() {
	for (int i = 0; i < _termWidth; i++) {
	    if (i == 0) {
            mvwprintw(w_info, 2, i, "\\");
            mvwprintw(w_info, 0, i, "/");
        } else if (i == _termWidth - 1) {
            mvwprintw(w_info, 2, i, "/");
            mvwprintw(w_info, 0, i, "\\");
        } else {
            mvwprintw(w_info, 0, i, "‾");
            mvwprintw(w_info, 2, i, "_");
	    }
	    mvwprintw(w_info, 1, 0, "༓");
        mvwprintw(w_info, 1, _termWidth - 1, "༓");
	}
	//lives
	//scores
	//time
	//pause status ?
}

void Game::drawMain() {
	_player->draw();
}

Game::Game() {

	initNcurses();
	this->_player = new Player(this->w_main);
	this->_menu = new Menu(this);
	_pause = 0;
	_game = 0;
}

void Game::run() {

	//first show start menu
	_menu->runStartScreen();
    _game = 1;
	while (1) {
		checkControls();
		//more checks

        //die ? final screen, any key pressed -> Game::run()
		wclear(this->w_main);
		drawMain();
		drawInfo();
		wrefresh(this->w_main);
		wrefresh(this->w_info);
	}
}

void Game::restart() {
    delete _player;
    _player = new Player(w_main);
    _game = 1;

}

Game::~Game() {
	endwin();
}

Game &Game::operator=(Game const &obj) {
	_pause = obj._pause;

	//TODO: change
	return *this;
}

void Game::checkControls() {
	if (!_game)
		return;

	int key = wgetch(stdscr);
	switch (key) {
		case KEY_UP:
			_player->moveUp();
			break;
		case KEY_DOWN:
			_player->moveDown();
			break;
		case KEY_LEFT:
			_player->moveLeft();
			break;
		case KEY_RIGHT:
			_player->moveRight();
			break;
		case 27: //esc
			if (_game) {
				_pause = 1;
				_menu->runPause();
			}
			break;
        case ' ':
            _player->shoot();
            break;
	}
}

bool Game::getGameStatus() {
    return _game;
}

bool Game::getPauseStatus() {
    return _pause;
}

int Game::getTermHeight() {
	return _termHeight;
}

int Game::getTermWidth() {
	return _termWidth;
}