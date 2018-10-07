#include <iostream>
#include "Game.hpp"
#include <locale.h>
#include <ncurses.h>


int main() {
    setlocale(LC_ALL, ""); //for unicode
    Game game;

    game.run();
}