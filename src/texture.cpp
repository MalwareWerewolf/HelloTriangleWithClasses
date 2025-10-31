#include "texture.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>
#include <filesystem>
#include <iostream>
#include <vector>
#include <string>

Texture::Texture(const char* texturePath1, const char* texturePath2)
{
    // texture 1
    // ---------
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.

    std::filesystem::path p1(texturePath1);
    std::vector<std::filesystem::path> candidates1;
    candidates1.push_back(p1);
    candidates1.push_back(std::filesystem::absolute(p1));
    candidates1.push_back(std::filesystem::current_path() / p1);
    candidates1.push_back(std::filesystem::path("resources") / p1);
    candidates1.push_back(std::filesystem::path("resources/textures") / p1);
    candidates1.push_back(std::filesystem::path("textures") / p1);

    unsigned char* data = nullptr;
    for (const auto& cand : candidates1) {
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
        std::cout << "Failed to load texture '" << texturePath1 << "' — cwd='" << std::filesystem::current_path().string() << "'\n";
        std::cout << "stbi failure reason: " << stbi_failure_reason() << "\n";
    }
    stbi_image_free(data);

    // texture 2
    // ---------
    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    std::filesystem::path p2(texturePath2);
    std::vector<std::filesystem::path> candidates2;
    candidates2.push_back(p2);
    candidates2.push_back(std::filesystem::absolute(p2));
    candidates2.push_back(std::filesystem::current_path() / p2);
    candidates2.push_back(std::filesystem::path("resources") / p2);
    candidates2.push_back(std::filesystem::path("resources/textures") / p2);
    candidates2.push_back(std::filesystem::path("textures") / p2);

    data = nullptr;
    for (const auto& cand : candidates2) {
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
        std::cout << "Failed to load texture '" << texturePath2 << "' — cwd='" << std::filesystem::current_path().string() << "'\n";
        std::cout << "stbi failure reason: " << stbi_failure_reason() << "\n";
    }
    stbi_image_free(data);
}