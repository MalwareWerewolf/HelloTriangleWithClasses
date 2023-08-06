#ifndef WINDOW_H
#define WINDOW_H

#include "config.h"

class Window {
private:
    unsigned int width {};
    unsigned int height {};

public:
    Window(unsigned int width, unsigned int height);
    GLFWwindow* createWindow();
};

#endif /* window_h */
