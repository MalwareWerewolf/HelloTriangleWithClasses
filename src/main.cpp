#include "initialization.h"
#include "renderLoop.h"
#include "shader.h"
#include "window.h"
#include "vertex.h"
#include <iostream>
#include <vector>

int main()
{
    Initialization initialization;
    initialization.initializeOpenGL();

    Window window(800, 600);
    GLFWwindow* glfwWindow { window.createWindow() };

    initialization.initializeGlad();

    // build and compile our shader program
    // ------------------------------------
    Shader ourShader("../shaders/3.3.shader.vs", "../shaders/3.3.shader.fs");

    std::vector<float> vertices = {
        // positions         // colors
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom left
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f // top
    };

    Vertex vertex(1, vertices);
    vertex.initializeVertexArrayAndBufferObject();

    RenderLoop renderLoop;
    renderLoop.render(
        glfwWindow,
        ourShader.ID,
        vertex.getVAO());

    vertex.deAllocateResources();

    glfwTerminate();
    return 0;
}
