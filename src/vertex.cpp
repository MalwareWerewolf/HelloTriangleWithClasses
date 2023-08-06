#include "vertex.h"

Vertex::Vertex(unsigned int numberOfVertices, const std::vector<float>& vertices)
    : numberOfVertices(numberOfVertices)
    , vertices(vertices)
{
}

unsigned int Vertex::getVAO() const
{
    return VAO;
}

void Vertex::InitializeVertexArrayAndBufferObject()
{
    glGenVertexArrays(numberOfVertices, &VAO);
    glGenBuffers(numberOfVertices, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);
}

void Vertex::DeAllocateResources()
{
    if (VAO > 0 && VBO > 0) {
        glDeleteVertexArrays(numberOfVertices, &VAO);
        glDeleteBuffers(numberOfVertices, &VBO);
    }
}