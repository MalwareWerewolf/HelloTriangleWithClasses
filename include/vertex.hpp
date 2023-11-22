#ifndef VERTEX_H
#define VERTEX_H

#include <vector>

class Vertex {
public:
    Vertex(unsigned int numberOfVertices, const std::vector<float>& vertices, const std::vector<int>& indices);

    unsigned int getVAO() const;

    void deAllocateResources();

private:
    unsigned int numberOfVertices {};
    unsigned int VAO {};
    unsigned int VBO {};
    unsigned int EBO {};
};

#endif