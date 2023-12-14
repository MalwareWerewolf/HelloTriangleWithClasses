#include "window.hpp"

Window::Window(unsigned int width, unsigned int height)
    : width(width)
    , height(height)
{
}

GLFWwindow* Window::CreateWindow()
{
    GLFWwindow* window { glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL) };
    if (window == NULL) {
        glfwTerminate();
        throw "Failed to create GLFW window";
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    });

    return window;
}
