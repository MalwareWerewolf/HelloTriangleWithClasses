#include "shader.h"

unsigned int Shader::createShader(GLenum shaderType, const char* shaderSource)
{
    unsigned int shader { glCreateShader(shaderType) };
    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);

    // check for shader compile errors
    int success {};
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        throw "ERROR::SHADER::VERTEX::COMPILATION_FAILED";
    }

    return shader;
}

void Shader::deleteShaders(const std::vector<GLuint>& shaderIDs)
{
    for (const GLuint shaderID : shaderIDs) {
        glDeleteShader(shaderID);
    }
}