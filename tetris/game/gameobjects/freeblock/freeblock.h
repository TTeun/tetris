#ifndef FREE_BLOCK__H
#define FREE_BLOCK__H

#include <iostream>
#include <vector>
#include "../renderable/renderable.h"

using namespace std;

class FreeBlock : public Renderable {
public:
    FreeBlock() = default;
    void updateBuffers(size_t w, size_t h);
    void fall();

    int xpos = 0;
    int ypos = 0;

private:

    bool shapeL[4][4] = {
        {0, 1, 0, 0},
        {0, 1, 0 , 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

};

#endif