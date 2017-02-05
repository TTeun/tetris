#include "renderable.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

void Renderable::setup() {
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0 );

    glGenBuffers(1, &colorbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0 );

    glBindVertexArray(0);
}

void Renderable::appendSquare(float x, float y, float dx, float R, float G, float B) {
    x += 0.03 * dx;
    y += 0.03 * dx;
    dx = 0.94 * dx;
    std::vector <float> block = {
        x, y, 0.0f,
        x + dx, y, 0.0f,
        x + dx, y - dx, 0.0f,
        x + dx, y - dx, 0.0f,
        x, y - dx, 0.0f,
        x, y, 0.0f,
        x + dx / 10, y - dx / 10, 0.0,
        x + dx / 5, y - dx / 10, 0.0,
        x + dx / 10, y - dx / 5, 0.0,
        x + 9 * dx / 10, y - 9 * dx / 10, 0.0,
        x + 4 * dx / 5, y - 9 * dx / 10, 0.0,
        x + 9 * dx / 10, y - 4 * dx / 5, 0.0,
    };
    coords.insert(coords.end(), block.begin(), block.end());
    for (int i = 0; i < 6; ++i) {
        colours.push_back(R);
        colours.push_back(G);
        colours.push_back(B);
    }
    for (int i = 0; i < 3; ++i) {
        colours.push_back(1.0);
        colours.push_back(1.0);
        colours.push_back(1.0);
    }
    for (int i = 0; i < 3; ++i) {
        colours.push_back(0.1);
        colours.push_back(0.1);
        colours.push_back(0.1);
    }
}

void Renderable::render(size_t width, size_t height, GLuint drawType) {

    updateBuffers(width, height);

    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, coords.size() * sizeof(float), &coords[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glBufferData(GL_ARRAY_BUFFER, colours.size() * sizeof(float), &colours[0], GL_STATIC_DRAW);

    glBindVertexArray(VertexArrayID);
    glDrawArrays(drawType, 0, (coords.size() / 3) );
}

