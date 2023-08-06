#ifndef RENDER_LOOP_H
#define RENDER_LOOP_H

#include "config.h"

class RenderLoop {
private:
    void processInput(GLFWwindow* window);

public:
    void render(GLFWwindow* window,
        const unsigned int shaderProgram,
        const unsigned int VAO);
};

#endif