#include "initialization.h"
#include "window.h"
#include "shader.h"
#include "vertex.h"
#include "render_loop.h"
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

    Texture texture("/Users/davidedolce/Dev/HelloTriangleWithClasses/resources/textures/container.jpg", "/Users/davidedolce/Dev/HelloTriangleWithClasses/resources/textures/awesomeface.png");

    RenderLoop renderLoop;
    renderLoop.render(
        glfwWindow,
        ourShader,
        texture,
        vertex.getVAO());

    vertex.deAllocateResources();

    glfwTerminate();
    return 0;
}
