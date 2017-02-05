#ifndef RENDERABLE__H
#define RENDERABLE__H

#include <cstdlib>
#include <iostream>
#include <GL/glew.h>
#include <vector>


class Renderable {
public:
    void setup();
    void appendSquare(float x, float y, float dx, float R, float G, float B);
    void render(size_t width, size_t height, GLuint drawType);


    virtual void updateBuffers(size_t w, size_t h) {};
    float colour[3];
    GLuint VertexArrayID;
    GLuint vertexbuffer;
    GLuint colorbuffer;

    std::vector <float> coords;
    std::vector <float> colours;

};

#endif