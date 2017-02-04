#ifndef ARENA__H
#define ARENA__H

#include <iostream>
#include <vector>
#include "../renderable/renderable.h"

class Arena : public Renderable {
public:
    Arena() = default;

    void updateBuffers(size_t w, size_t h) {
        float dx = 1.5f / (float)h;
        float halfW = dx * (w / 2.0f);
        float halfH = dx * (h / 2.0f);
        coords.clear();
        std::vector <float> block = {
            -halfW, -halfH, 0.0f,
            halfW, -halfH, 0.0f,
            halfW, halfH, 0.0f,
            -halfW, halfH, 0.0f,
        };
        coords = block;
        colours.clear();
        for (size_t i = 0; i < 16; i++)
            colours.push_back(0.7);

    }


private:

};

#endif