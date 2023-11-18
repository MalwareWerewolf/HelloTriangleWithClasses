#ifndef RENDER_LOOP_H
#define RENDER_LOOP_H

#include "shader.h"
#include "texture.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class RenderLoop {
public:
    void render(GLFWwindow* window,
        Shader& shader,
        Texture& texture,
        const unsigned int VAO);

private:
    void processInput(GLFWwindow* window);
};

#endif