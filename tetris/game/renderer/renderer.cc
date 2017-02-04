#include "renderer.h"

#include <cstdlib>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "loadshader.cc"

Renderer::Renderer(size_t w, size_t h)
{
    std::cout << "Renderer constructor started\n";
    if ( !glfwInit() )
        fprintf( stderr, "Failed to initialize GLFW\n" );
    else
        std::cout << "succes\n";

    glfwWindowHint(GLFW_SAMPLES, 4);                                // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);                  // We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  //We don't want the old OpenGL

    window = glfwCreateWindow( 1024, 768, "Tetris!!! :D", NULL, NULL);
    if ( window == NULL )
    {
        fprintf(stderr, "Window is null\n");
        glfwTerminate();
    }
    glfwMakeContextCurrent(window); // Initialize GLEW
    glewExperimental = true;        // Needed in core profile
    if (glewInit() != GLEW_OK)
        fprintf(stderr, "Failed to initialize GLEW\n");

    shaderProg = LoadShaders("tetris/game/renderer/shaders/vert.vt", "tetris/game/renderer/shaders/frag.fr");

    width = w;
    height = h;
}

void Renderer::init(GameObjects *objects) {
    objects->arena->setup();
    objects->freeBlock->setup();
}

void Renderer::render(GameObjects *objects) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(shaderProg);

    objects->freeBlock->render(width, height, GL_TRIANGLES);
    objects->arena->render(width, height, GL_LINE_LOOP);

    glfwSwapBuffers(window);
    glfwPollEvents();
}

