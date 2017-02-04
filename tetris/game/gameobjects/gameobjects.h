#ifndef GAME__OBJECTS__H
#define GAME__OBJECTS__H

#include "arena/arena.h"
#include "freeblock/freeblock.h"
#include "setblock/setblock.h"
#include "shapes.h"
#include <vector>

class GameObjects {
public:
    GameObjects(size_t w, size_t h)
        :
        shapes(new Shapes()),
        arena(new Arena()),
        freeBlock(new FreeBlock(shapes)),
        setBlock(new SetBlock(w, h))
    {
        std::cout << "GameObjects constructor started\n";
        width = w;
        height = h;
    }
    void moveRight(){std::cout << "Right\n";}
    void moveLeft(){std::cout << "moveLeft\n";}

    Shapes *shapes;
    Arena *arena;
    FreeBlock *freeBlock;
    SetBlock *setBlock;

private:
    size_t width;
    size_t height;
};

#endif