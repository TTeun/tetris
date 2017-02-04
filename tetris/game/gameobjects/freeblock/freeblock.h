#ifndef FREE_BLOCK__H
#define FREE_BLOCK__H

#include <iostream>
#include <vector>
#include "../renderable/renderable.h"
#include "../shapes.h"

using namespace std;

class FreeBlock : public Renderable {
public:
    FreeBlock(Shapes *_shapes);
    void updateBuffers(size_t w, size_t h);
    void fall();
    void init();

    int xpos;
    int ypos;

    Shapes *shapes;
    Shapes::SHAPES_TYPES type;
    short int rot = 0;
private:

};

#endif