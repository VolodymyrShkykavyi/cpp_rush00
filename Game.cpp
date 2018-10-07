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
    init_pair(TEXT_YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(TEXT_RED, COLOR_RED, COLOR_BLACK);
    init_pair(TEXT_BLUE, COLOR_BLUE, COLOR_BLACK);
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
	unsigned seconds = difftime(time(0), _player->getTime());
	mvwprintw(w_info, 1, 2, "Time in game: %d:%0.2d", seconds / 60, seconds % 60);
	mvwprintw(w_info, 1, _termWidth - 15, "Score: %d", _player->getScore());
	
	int mid = _termWidth/2;
	for (int i = 0; i < _player->getHp(); ++i){
		mvwprintw(w_info, 1, mid, "❤️");
		mid += 4;
	}
}

void Game::drawMain() {
    addEnemies();
    moveEnemies();

    _player->draw();
}

Game::Game() {

    initNcurses();
    this->_player = new Player(this->w_main);
    this->_menu = new Menu(this);
    _pause = 0;
    _game = 0;

    for (int i = 0; i < SIMPLE_ENEMY_MAX; i++) {
        _enemies_simple[i] = new SimpleEnemy(w_main);
    }
    for (int j = 0; j < ENEMY_BULLETS_MAX; j++) {
        _enemies_bullets[j] = new Bullet(0, 0, 1, w_main);
        _enemies_bullets[j]->setIco("o");
    }

    for (int k = 0; k < MIDDLE_ENEMY_MAX; k++) {
        _enemies_middle[k] = new MiddleEnemy(w_main, _enemies_bullets);
    }

}

void Game::run() {

    //first show start menu
    _menu->runStartScreen();
    _game = 1;
    _player->setTime();

    while (1) {
        checkControls();
        checkBulletCollision();
        checkEnemyCollision();

        wclear(this->w_main);
        wclear(this->w_info);
        drawMain();
        drawInfo();
        wrefresh(this->w_main);
        wrefresh(this->w_info);
		// usleep(2000);
    }
}

void Game::restart() {
    delete _player;
    _player = new Player(w_main);
    _game = 1;

    for (int i = 0; i < SIMPLE_ENEMY_MAX; i++){
        _enemies_simple[i]->setVisible(0);
    }
}

void Game::addEnemies() {
    if (time(0) % 11 == 0) {
        for (int i = 0; i < SIMPLE_ENEMY_MAX; ++i) {
            if (!_enemies_simple[i]->getVisible()) {
                _enemies_simple[i]->setDefaults();
                _enemies_simple[i]->setVisible(1);
                break;
            }
        }

        for (int j = 0; j < MIDDLE_ENEMY_MAX; j++) {
            if (!_enemies_middle[j]->getVisible()){
                _enemies_middle[j]->setDefaults();
                _enemies_middle[j]->setVisible(1);
            }
        }
    }
}

void Game::moveEnemies() {
    for (int i = 0; i < SIMPLE_ENEMY_MAX; ++i) {
        if (_enemies_simple[i]->getVisible()) {
            _enemies_simple[i]->move();
            _enemies_simple[i]->draw();
            if (_enemies_simple[i]->getY() >= _termHeight - INFO_HEIGHT) {
                _enemies_simple[i]->setVisible(0);
            }
        }
    }

    for (int j = 0; j < MIDDLE_ENEMY_MAX; j++) {
        if (_enemies_middle[j]->getVisible()) {
            _enemies_middle[j]->move();
        //    if (((int)difftime(time(0), _player->getTime()) % 3) == 0)
                _enemies_middle[j]->shoot(); //enemy shooting
            _enemies_middle[j]->draw();
            if (_enemies_middle[j]->getY() >= _termHeight - INFO_HEIGHT) {
                _enemies_middle[j]->setVisible(0);
            }
        }
    }

    for (int k = 0; k < ENEMY_BULLETS_MAX; k++) {
        if (_enemies_bullets[k]->getVisIble()){
            _enemies_bullets[k]->move();
            _enemies_bullets[k]->draw();
            if (_enemies_bullets[k]->getY() >= _termHeight - INFO_HEIGHT) {
                _enemies_bullets[k]->setVisible(0);
            }
        }
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
	time_t pauseStart = time(0);

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
				_player->fixPauseTime(difftime(time(0), pauseStart));
			}
			break;
        case ' ':
            _player->shoot();
            break;
    }
}

void Game::checkBulletCollision() {
    Bullet **pBullet = _player->getBullets();
    //TODO: enemy bullets

    for (int i = 0; i < PLAYER_BULLETS_NUM; i++) {
        if (pBullet[i]->getVisIble()) {
            for (int j = 0; j < SIMPLE_ENEMY_MAX; j++) {
                if (_enemies_simple[j]->getVisible()){
                    if (_enemies_simple[j]->getX() == pBullet[i]->getX() &&
                        _enemies_simple[j]->getY() == pBullet[i]->getY()) {
                        pBullet[i]->setVisible(0);
                        _enemies_simple[j]->setVisible(0);
                        _player->addScore(_enemies_simple[j]->getScoreCost());

                        break;
                    }
                }
            }

            for (int k = 0; k < MIDDLE_ENEMY_MAX ; k++) {
                if (_enemies_middle[k]->getVisible()){
                    if (_enemies_middle[k]->getX() == pBullet[i]->getX() &&
                            _enemies_middle[k]->getY() == pBullet[i]->getY()) {
                        pBullet[i]->setVisible(0);
                        _enemies_middle[k]->setVisible(0);
                        _player->addScore(_enemies_middle[k]->getScoreCost());

                        break;
                    }
                }
            }
        }
    }

    for (int k = 0; k < ENEMY_BULLETS_MAX; k++) {
        if (_enemies_bullets[k]->getVisIble()){
            if ((_enemies_bullets[k]->getX() >= _player->getX() &&
                _enemies_bullets[k]->getX() <= _player->getX() + 1) &&
                _enemies_bullets[k]->getY() == _player->getY()) {
                _enemies_bullets[k]->setVisible(0);
                _player->reduceHP();
                if (_player->getHp() <= 0){
                    drawFinalScreen();
                }
            }
        }
    }
}

void Game::checkEnemyCollision() {
    int pX = _player->getX();
    int pY = _player->getY();

    for (int i = 0; i < SIMPLE_ENEMY_MAX; i++) {
        if (_enemies_simple[i]->getVisible()) {
            if ((pX == _enemies_simple[i]->getX() ||
                 pX == _enemies_simple[i]->getX() - 1) &&
                pY == _enemies_simple[i]->getY()) {
                _player->reduceHP();
                _enemies_simple[i]->setVisible(0);

                if (_player->getHp() == 0) {
                    drawFinalScreen();
                }
            }
        }
    }

    for (int j = 0; j < MIDDLE_ENEMY_MAX; j++) {
        if (_enemies_middle[j]->getVisible()) {
            if ((pX == _enemies_middle[j]->getX() ||
                 pX == _enemies_middle[j]->getX() - 1) &&
                pY == _enemies_middle[j]->getY()) {
                _player->reduceHP();
                _enemies_middle[j]->setVisible(0);

                if (_player->getHp() == 0) {
                    drawFinalScreen();
                }
            }
        }
    }
}

void Game::drawFinalScreen() {
    wclear(w_main);

    while (1) {
        wattron(w_main, COLOR_PAIR(TEXT_YELLOW));
        mvwprintw(w_main, 10, 10, "YOU DIE =(");
        mvwprintw(w_main, 11, 10, "SCORE %d", _player->getScore());
        wrefresh(w_main);
        int key = wgetch(stdscr);
        if (key > 0)
            break;

    }
    wattron(w_main, COLOR_PAIR(TEXT_WHITE));
    this->restart();
    _game = 0;
    _pause = 0;
    this->run();
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