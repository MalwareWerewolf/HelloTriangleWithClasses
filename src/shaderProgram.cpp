#include "shaderProgram.h"

ShaderProgram::ShaderProgram()
{
    programID = glCreateProgram();
}

unsigned int ShaderProgram::getProgramID() const
{
    return programID;
}

void ShaderProgram::attachShaders(const std::vector<unsigned int>& shaderIDs)
{
    for (const unsigned int shaderID : shaderIDs) {
        glAttachShader(programID, shaderID);
    }
}

void ShaderProgram::link()
{
    int success {};
    char infoLog[512];

    glLinkProgram(programID);
    glGetProgramiv(programID, GL_LINK_STATUS, &success);

    if (!success) {
        glGetProgramInfoLog(programID, 512, NULL, infoLog);
        throw "ERROR::SHADER::PROGRAM::LINKING_FAILED";
    }
}

void ShaderProgram::DeAllocateShaderProgram()
{
    glDeleteProgram(programID);
}