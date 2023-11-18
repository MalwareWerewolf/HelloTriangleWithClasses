#include "vertex.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

Vertex::Vertex(unsigned int numberOfVertices, const std::vector<float>& vertices)
    : numberOfVertices(numberOfVertices)
    , vertices(vertices)
{
}

unsigned int Vertex::getVAO() const
{
    return VAO;
}

void Vertex::initializeVertexArrayAndBufferObject()
{
    unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3 // second triangle
    };
    glGenVertexArrays(numberOfVertices, &VAO);
    glGenBuffers(numberOfVertices, &VBO);
    glGenBuffers(numberOfVertices, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}

void Vertex::deAllocateResources()
{
    glDeleteVertexArrays(numberOfVertices, &VAO);
    glDeleteBuffers(numberOfVertices, &VBO);
    glDeleteBuffers(numberOfVertices, &EBO);
}