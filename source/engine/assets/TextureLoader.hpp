#ifndef SAH_TEXTURELOADER
#define SAH_TEXTURELOADER

#include <iostream>
#include <map>

#include <glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>


class TextureLoader {
private:
    static std::map<std::string, unsigned int> m_textures;

public:
    TextureLoader() {};
    ~TextureLoader() {};

    static unsigned int createTexture(std::string textureName, std::string filePath, bool AlphaChanel);
    static unsigned int getTexture(std::string textureName);

};

#endif
