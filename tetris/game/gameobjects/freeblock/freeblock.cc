#include "freeblock.h"
#include <random>

FreeBlock::FreeBlock(Shapes *_shapes)
    :
    shapes(_shapes)
{
    std::cout << "FreeBlock constructor started\n";

    init();
};

void FreeBlock::init() {

    xpos = 0;
    ypos = 0;

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, Shapes::NUMSHAPES - 1); // define the range

    type = static_cast<Shapes::SHAPES_TYPES>(distr(eng));

}

void FreeBlock::updateBuffers(size_t w, size_t h) {
    float dx = 1.5f / (float)h;
    float halfW = dx * (w / 2.0f);
    float halfH = dx * (h / 2.0f);
    coords.clear();
    colours.clear();

    for (size_t i = 0; i < 4; ++i)
        for (size_t j = 0; j < 4; ++j)
            if (shapes->shapes1[rot][type][i] & (1 << j))
                appendSquare(-halfW + (w / 2 + (xpos + j - 1)) * dx, halfH - (ypos + i) * dx, dx, 1.0, 0.2, 0.2);




}

void FreeBlock::fall() {
    ++ypos;
}
