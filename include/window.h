#ifndef WINDOW_H
#define WINDOW_H

#include "config.h"

class Window {
public:
    Window(unsigned int width, unsigned int height);
    GLFWwindow* createWindow();

private:
    unsigned int width {};
    unsigned int height {};
};

#endif /* window_h */
