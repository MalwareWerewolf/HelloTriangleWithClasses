#ifndef VERTEX_H
#define VERTEX_H

#include "config.h"
#include <vector>

class Vertex {
private:
    unsigned int numberOfVertices {};
    const std::vector<float>& vertices {};
    unsigned int VBO {};
    unsigned int VAO {};

public:
    Vertex(unsigned int numberOfVertices, const std::vector<float>& vertices);

    unsigned int getVAO() const;

    void InitializeVertexArrayAndBufferObject();
    void DeAllocateResources();
};

#endif