#ifndef RENDER_H
#define RENDER_H

#include "shader.hpp"
#include "texture.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Render {
public:
    void RenderLoop(GLFWwindow* window,
        Shader& shader,
        Texture& texture,
        const unsigned int VAO);

private:
    void ProcessInput(GLFWwindow* window);
};

#endif