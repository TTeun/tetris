#include "setblock.h"

SetBlock::SetBlock(size_t w, size_t h) {
    matrix.reserve(h + 4);
    for (size_t i = 0; i < h + 4; ++i) {
        matrix[i].reserve(w + 4);
        for (size_t j = 0; j < w + 4; ++j)
            matrix[i][j] = false;
    }
}


void SetBlock::updateBuffers(size_t w, size_t h) {
    float dx = 1.5f / (float)h;
    float halfW = dx * (w / 2.0f);
    float halfH = dx * (h / 2.0f);
    coords.clear();
    colours.clear();

    for (size_t i = 2; i < h + 2; ++i)
        for (size_t j = 2; j < w + 2; ++j)
            if (matrix[i][j])
                appendSquare(-halfW + (j - 2) * dx, halfH - (i - 2) * dx, dx, 0.5, 0.2, 0.2);



}