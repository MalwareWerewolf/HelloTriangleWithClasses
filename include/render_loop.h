#ifndef RENDER_LOOP_H
#define RENDER_LOOP_H

#include "config.h"

class RenderLoop {
public:
    void render(GLFWwindow* window,
        const unsigned int shaderProgram,
        const unsigned int VAO);

private:
    void processInput(GLFWwindow* window);
};

#endif