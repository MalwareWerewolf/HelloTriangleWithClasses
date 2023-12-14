#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
public:
    Window(unsigned int width, unsigned int height);
    GLFWwindow* CreateWindow();

private:
    unsigned int width {};
    unsigned int height {};
};

#endif /* window_h */
