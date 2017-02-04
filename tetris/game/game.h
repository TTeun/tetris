#ifndef GAME__H
#define GAME__H

#include "renderer/renderer.h"
#include "timer/timer.h"
#include "gameobjects/gameobjects.h"

class Game {
public:
    Game(size_t w, size_t h);
    void play();
    bool blockHit(FreeBlock *fr, SetBlock *st);

    size_t width;
    size_t height;

    GameObjects *objects;

private:
    Timer *timer;
    Renderer *renderer;
};

#endif