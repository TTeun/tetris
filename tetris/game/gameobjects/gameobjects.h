#ifndef GAME__OBJECTS__H
#define GAME__OBJECTS__H

#include "arena/arena.h"
#include "freeblock/freeblock.h"
#include "setblock/setblock.h"
#include <vector>

class GameObjects {
public:
    GameObjects(size_t w, size_t h)
        :
        arena(new Arena()),
        freeBlock(new FreeBlock()),
        setBlock(new SetBlock(w, h))
    {
        std::cout << "GameObjects constructor started\n";
    }
    Arena *arena;
    FreeBlock *freeBlock;
    SetBlock *setBlock;

private:

};

#endif