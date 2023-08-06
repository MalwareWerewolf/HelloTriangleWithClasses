#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

#include "config.h"
#include <vector>

class ShaderProgram {
private:
    unsigned int programID {};

public:
    ShaderProgram();

    unsigned int getProgramID() const;

    void attachShaders(const std::vector<GLuint>& shaderIDs);
    void link();
    void DeAllocateShaderProgram();
};

#endif /* shaderProgram_h */
