#include "initialization.h"
#include "renderLoop.h"
#include "shader.h"
#include "shaderConstants.h"
#include "shaderProgram.h"
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

    Shader shader;
    unsigned int vertexShader { shader.createShader(GL_VERTEX_SHADER, vertexShaderSource) };
    unsigned int fragmentShader { shader.createShader(GL_FRAGMENT_SHADER, fragmentShaderSource) };

    std::vector<GLuint> shaders { vertexShader, fragmentShader };

    ShaderProgram shaderProgram;
    shaderProgram.attachShaders(shaders);
    shaderProgram.link();
    shader.deleteShaders(shaders);

    std::vector<float> vertices = {
        -0.5f, -0.5f, 0.0f, // left
        0.5f, -0.5f, 0.0f, // right
        0.0f, 0.5f, 0.0f // top
    };

    Vertex vertex(1, vertices);
    vertex.InitializeVertexArrayAndBufferObject();

    RenderLoop renderLoop;
    renderLoop.render(
        glfwWindow,
        shaderProgram.getProgramID(),
        vertex.getVAO());

    vertex.DeAllocateResources();
    shaderProgram.DeAllocateShaderProgram();

    glfwTerminate();
    return 0;
}
