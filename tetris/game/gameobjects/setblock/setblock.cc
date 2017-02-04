#include "setblock.h"

SetBlock::SetBlock(size_t w, size_t h) {
    matrix.reserve(h);
    for (size_t i = 0; i < h; ++i) {
        matrix[i].reserve(w);
        for (size_t j = 0; j < w; ++j)
            matrix[i][j] = false;
    }
}


void SetBlock::updateBuffers(size_t w, size_t h) {
    float dx = 1.5f / (float)h;
    float halfW = dx * (w / 2.0f);
    float halfH = dx * (h / 2.0f);
    coords.clear();

    for (size_t i = 0; i < w; ++i)
        for (size_t j = 0; j < h; ++j)
            if (matrix[i][j])
                appendSquare(-halfW + j * dx, halfH - i * dx, dx);



    colours.clear();
    for (size_t i = 0; i < coords.size(); i += 3) {
        colours.push_back(1.0f);
        colours.push_back(0.2f);
        colours.push_back(0.2f);
    }

}