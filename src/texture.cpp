#include "texture.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>
#include <filesystem>
#include <iostream>
#include <vector>
#include <string>

unsigned int Texture::loadTexture(const char* texturePath)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width = 0, height = 0, nrChannels = 0;
    stbi_set_flip_vertically_on_load(true);

    std::filesystem::path p(texturePath);
    std::vector<std::filesystem::path> candidates;
    candidates.push_back(p);
    candidates.push_back(std::filesystem::absolute(p));
    candidates.push_back(std::filesystem::current_path() / p);
    candidates.push_back(std::filesystem::path("resources") / p);
    candidates.push_back(std::filesystem::path("resources/textures") / p);
    candidates.push_back(std::filesystem::path("textures") / p);

    unsigned char* data = nullptr;
    for (const auto& cand : candidates) {
        std::string s = cand.string();
        std::cout << "Trying texture path: '" << s << "' (exists: " << std::boolalpha << std::filesystem::exists(cand) << ")\n";
        if (!std::filesystem::exists(cand))
            continue;
        data = stbi_load(s.c_str(), &width, &height, &nrChannels, 0);
        if (data) {
            std::cout << "Loaded texture from: " << s << " (" << width << "x" << height << ", channels=" << nrChannels << ")\n";
            break;
        } else {
            std::cout << "stbi_load failed: " << stbi_failure_reason() << " for " << s << "\n";
        }
    }

    if (data) {
        GLenum format = GL_RGB;
        if (nrChannels == 1)
            format = GL_RED;
        else if (nrChannels == 3)
            format = GL_RGB;
        else if (nrChannels == 4)
            format = GL_RGBA;

        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Failed to load texture '" << texturePath << "' — cwd='" << std::filesystem::current_path().string() << "'\n";
        std::cout << "stbi failure reason: " << stbi_failure_reason() << "\n";
    }
    stbi_image_free(data);

    return textureID;
}

Texture::Texture(const char* texturePath1, const char* texturePath2)
{
    texture1 = loadTexture(texturePath1);
    texture2 = loadTexture(texturePath2);
}