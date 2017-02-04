#ifndef RENDERER__H
#define RENDERER__H

#include <cstdlib>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "../gameobjects/gameobjects.h"

class Game;

class Renderer {
public:
    Renderer(size_t w, size_t h, Game *game);
    void init(GameObjects *objects);
    void render(GameObjects *objects);
    GLFWwindow* window;
    GLuint shaderProg;

private:
    size_t width;
    size_t height;


};

#endif
