#include "game.h"

Game::Game(size_t w, size_t h)
    :
    objects(new GameObjects(w, h)),
    timer(new Timer(0.2)),
    renderer(new Renderer(w, h, this))
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

    bool notDead = true;

    while (!glfwWindowShouldClose(renderer->window) && notDead) {
        if (timer->ticked()) {
            if (not blockHit(objects->freeBlock, objects->setBlock))
                objects->freeBlock->fall();
            else {
                objects->freeBlock->init();
            }

        }
        bool rowDone;
        for (int i = 2; i < height + 2; ++i) {
            rowDone = true;
            for (int j = 2; j < width + 2; ++j)
                rowDone &= objects->setBlock->matrix[i][j];

            if (rowDone)
                for (int k = i; k > 2; --k)
                    for (int j = 2; j < width + 2; ++j)
                        objects->setBlock->matrix[k][j] = objects->setBlock->matrix[k - 1][j];

        }

        renderer->render(objects);
    }
}

void Game::rotate() {
    objects->freeBlock->rot += 1;
    objects->freeBlock->rot %= 4;
}

bool Game::blockHit(FreeBlock *fr, SetBlock *st) {

    int xpos = fr->xpos;
    int ypos = fr->ypos;
    bool collided = false;
    for (size_t i = 0; i < 4 && collided == false; ++i)
        for (size_t j = 0; j < 4 && collided == false; ++j)
            if (fr->shapes->shapes1[fr->rot][fr->type][i] & (1 << j))
                if ((ypos + i + 1 == height) || (st->matrix[2 + ypos + i + 1][width / 2 + xpos + j - 1 + 2]))
                    collided = true;


    if (collided)
        for (size_t i = 0; i < 4; ++i)
            for (size_t j = 0; j < 4; ++j)
                if (fr->shapes->shapes1[fr->rot][fr->type][i] & (1 << j))
                    st->matrix[2 + ypos + i][width / 2 + xpos + j - 1 + 2] = true;


    return collided;
}

void Game::moveLeft() {
    FreeBlock *fr = objects->freeBlock;
    SetBlock *st = objects->setBlock;

    int xpos = fr->xpos;
    int ypos = fr->ypos;
    bool canMove = true;
    for (size_t i = 0; i < 4 && canMove; ++i)
        for (size_t j = 0; j < 4 && canMove; ++j)
            if (fr->shapes->shapes1[fr->rot][fr->type][i] & (1 << j))
                if ((width / 2 + xpos + j - 1 == 0) || (st->matrix[2 + ypos + i][width / 2 + xpos + j - 2 + 2]))
                    canMove = false;

    if (canMove)
        fr->xpos--;

}

void Game::moveRight() {
    FreeBlock *fr = objects->freeBlock;
    SetBlock *st = objects->setBlock;

    int xpos = fr->xpos;
    int ypos = fr->ypos;
    bool canMove = true;
    for (size_t i = 0; i < 4 && canMove; ++i)
        for (size_t j = 0; j < 4 && canMove; ++j)
            if (fr->shapes->shapes1[fr->rot][fr->type][i] & (1 << j))
                if ((width / 2 + xpos + j == width) || (st->matrix[2 + ypos + i][width / 2 + xpos + j + 2]))
                    canMove = false;

    if (canMove)
        fr->xpos++;
}

void Game::moveDown() {
    FreeBlock *fr = objects->freeBlock;
    SetBlock *st = objects->setBlock;

    int xpos = fr->xpos;
    int ypos = fr->ypos;
    bool canMove = true;

    for (size_t i = 0; i < 4 && canMove; ++i)
        for (size_t j = 0; j < 4 && canMove; ++j)
            if (fr->shapes->shapes1[fr->rot][fr->type][i] & (1 << j))
                if ((ypos + i + 1 == height) || (st->matrix[2 + ypos + i + 1][width / 2 + xpos + j - 1 + 2]))
                    canMove = false;

    if (canMove)
        fr->ypos++;

}

