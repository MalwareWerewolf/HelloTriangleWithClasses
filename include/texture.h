#ifndef TEXTURE_H
#define TEXTURE_H

class Texture {
public:
    unsigned int texture1;
    unsigned int texture2;

    Texture(const char* texturePath1, const char* texturePath2);
};

#endif