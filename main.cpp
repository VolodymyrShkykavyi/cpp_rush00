#include <iostream>
#include "Game.hpp"
#include <locale.h>
#include <ncurses.h>
#include <time.h>
#include <stdlib.h>

int main() {
    setlocale(LC_ALL, ""); //for unicode
    srand(time(NULL));
    Game game;

    game.run();
}