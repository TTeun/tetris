#include "game.h"

Game::Game(size_t w, size_t h)
    :
    objects(new GameObjects(w, h)),
    timer(new Timer(0.2)),
    renderer(new Renderer(w, h))
{
    width = w;
    height = h;
    std::cout << "Game constructed\n";
}

void Game::play() {
    timer->start();
    std::cout << "Timer started\n";
    renderer->init(objects);
    std::cout << "Renderer initialized\n";

    while (!glfwWindowShouldClose(renderer->window)) {
        if (timer->ticked())
            if (not blockHit(objects->freeBlock, objects->setBlock))
                objects->freeBlock->fall();


        renderer->render(objects);
    }
}

bool Game::blockHit(FreeBlock *fr, SetBlock *st) {
    return (static_cast<size_t>(fr->ypos) == height);
}