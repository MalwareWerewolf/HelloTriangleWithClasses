#ifndef VERTEX_H
#define VERTEX_H

#include <vector>

class Vertex {
public:
    Vertex(unsigned int numberOfVertices, const std::vector<float>& vertices);

    unsigned int getVAO() const;

    void initializeVertexArrayAndBufferObject();
    void deAllocateResources();

private:
    unsigned int numberOfVertices {};
    const std::vector<float>& vertices {};
    unsigned int VAO {};
    unsigned int VBO {};
    unsigned int EBO {};
};

#endif