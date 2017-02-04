#include "freeblock.h"

void FreeBlock::updateBuffers(size_t w, size_t h) {
    float dx = 1.5f / (float)h;
    float halfW = dx * (w / 2.0f);
    float halfH = dx * (h / 2.0f);
    coords.clear();

    for (size_t i = 0; i < 4; ++i)
        for (size_t j = 0; j < 4; ++j)
            if (shapeL[i][j])
                appendSquare(-halfW + (w / 2 + (xpos + j - 1)) * dx, halfH - (ypos + i) * dx, dx);



    colours.clear();
    for (size_t i = 0; i < coords.size(); i += 3) {
        colours.push_back(1.0f);
        colours.push_back(0.2f);
        colours.push_back(0.2f);
    }

}

void FreeBlock::fall() {
    ++ypos;
}
