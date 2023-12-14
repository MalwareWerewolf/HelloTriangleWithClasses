#ifndef SHADER_H
#define SHADER_H

#include <glm/glm.hpp>
#include <string>

class Shader {
public:
    unsigned int ID;

    // constructor generates the shader on the fly
    // ------------------------------------------------------------------------
    Shader(const char* vertexPath, const char* fragmentPath);

    // activate the shader
    // ------------------------------------------------------------------------
    void Use();

    // utility uniform functions
    // ------------------------------------------------------------------------
    void SetBool(const std::string& name, bool value) const;
    // ------------------------------------------------------------------------
    void SetInt(const std::string& name, int value) const;
    // ------------------------------------------------------------------------
    void SetFloat(const std::string& name, float value) const;
    // ------------------------------------------------------------------------
    void SetVec2(const std::string& name, const glm::vec2& value) const;
    // ------------------------------------------------------------------------
    void SetVec2(const std::string& name, float x, float y) const;
    // ------------------------------------------------------------------------
    void SetVec3(const std::string& name, const glm::vec3& value) const;
    // ------------------------------------------------------------------------
    void SetVec3(const std::string& name, float x, float y, float z) const;
    // ------------------------------------------------------------------------
    void SetVec4(const std::string& name, const glm::vec4& value) const;
    // ------------------------------------------------------------------------
    void SetVec4(const std::string& name, float x, float y, float z, float w) const;
    // ------------------------------------------------------------------------
    void SetMat2(const std::string& name, const glm::mat2& mat) const;
    // ------------------------------------------------------------------------
    void SetMat3(const std::string& name, const glm::mat3& mat) const;
    // ------------------------------------------------------------------------
    void SetMat4(const std::string& name, const glm::mat4& mat) const;

private:
    void CheckCompileErrors(unsigned int shader, std::string type);
};

#endif /* shader_h */
