#include "initialization.h"
#include "window.h"
#include "shader.h"
#include "vertex.h"
#include "render.h"
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
    Shader ourShader("./shaders/3.3.shader.vs", "./shaders/3.3.shader.fs");

    std::vector<float> vertices = {
        // positions          // colors           // texture coords
        0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top right
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
        -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f // top left
    };

    Vertex vertex(1, vertices);
    vertex.initializeVertexArrayAndBufferObject();

    Texture texture("resources/textures/container.jpg", "resources/textures/awesomeface.png");

    Render render;
    render.renderLoop(
        glfwWindow,
        ourShader,
        texture,
        vertex.getVAO());

    vertex.deAllocateResources();

    glfwTerminate();
    return 0;
}
