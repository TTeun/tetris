#ifndef KEY_HANDLER__H
#define KEY_HANDLER__H

#include "../game.h"
#include <cstdlib>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class KeyHandler {
public:
    KeyHandler(GLFWwindow *_window)
        :
        window(_window)
    {
        std::cout << "KeyHandler constructor started\n";
        glfwSetKeyCallback(window, key_callback);

    }

    void static key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        Game *game = reinterpret_cast<Game*>(glfwGetWindowUserPointer(window));
        if (action == GLFW_PRESS) {


            switch (key) {
            case GLFW_KEY_A:
                game->moveLeft();
                break;
            case GLFW_KEY_LEFT:
                game->moveLeft();
                break;
            case GLFW_KEY_D:
                game->moveRight();
                break;
            case GLFW_KEY_RIGHT:
                game->moveRight();
                break;
            case GLFW_KEY_W:
                game->moveRight();
                break;
            case GLFW_KEY_UP:
                game->rotate();
                break;
            default:
                break;
            }

        }
        if (key == GLFW_KEY_DOWN || key == GLFW_KEY_S )
            game->moveDown();

    }



    enum KEYS
    {
        LEFT,
        RIGHT,
        UP,
        DOWN,
        NONE
    };

    static KEYS keystate;
private:
    GLFWwindow *window;

};

#endif