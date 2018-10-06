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

	//init info window

	//init main window
}

void Game::drawInfo() {
	box(this->w_info, '|', '-');
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
	this->_menu = new Menu(this->w_main, this->w_info);
	_pause = 0;
	_game = 0;
}

void Game::run() {

	//first show start menu
	_menu->runStartScreen();

	while (1) {
		checkControls();
		//more checks

		wclear(this->w_main);
		drawMain();
		drawInfo();
		wrefresh(this->w_main);
		wrefresh(this->w_info);
	}
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
	}
}