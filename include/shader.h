#ifndef SHADER_H
#define SHADER_H

#include "config.h"
#include <vector>

class Shader {
public:
    unsigned int createShader(GLenum shaderType, const char* shaderSource);
    void deleteShaders(const std::vector<GLuint>& shaderIDs);
};

#endif /* shader_h */
