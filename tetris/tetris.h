#ifndef TETRIS__H
#define TETRIS__H

#include "game/game.h"

class Tetris {
public:
    Tetris()
        :
        game(new Game(12, 22))
    {
        std::cout << "Tetris constructor started\n";
    }
    Game *game;

};

#endif