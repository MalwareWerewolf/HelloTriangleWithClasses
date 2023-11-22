#include "vertex.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

Vertex::Vertex(unsigned int numberOfVertices, const std::vector<float>& vertices, const std::vector<int>& indices)
{
    glGenVertexArrays(numberOfVertices, &VAO);
    glGenBuffers(numberOfVertices, &VBO);
    glGenBuffers(numberOfVertices, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, vertices.size() * sizeof(int), indices.data(), GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

unsigned int Vertex::getVAO() const
{
    return VAO;
}

void Vertex::deAllocateResources()
{
    glDeleteVertexArrays(numberOfVertices, &VAO);
    glDeleteBuffers(numberOfVertices, &VBO);
    glDeleteBuffers(numberOfVertices, &EBO);
}