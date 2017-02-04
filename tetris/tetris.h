#ifndef TETRIS__H
#define TETRIS__H

#include "game/keyhandler/keyhandler.h"
#include "game/game.h"
class Tetris {
public:
    Tetris()
        :
        game(new Game(12, 22)),
        keyHandler(new KeyHandler(game->renderer->window))
    {
        std::cout << "Tetris constructor started\n";
    }
    Game *game;
    KeyHandler *keyHandler;
};

#endif