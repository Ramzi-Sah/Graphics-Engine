#ifndef SAH_ASSETLOADER
#define SAH_ASSETLOADER

#include "ShaderLoader.hpp"
#include "TextureLoader.hpp"
#include "ModelLoader.hpp"

class AssetLoader {
private:

public:
    static void createShaderPrograms();
    static void createTextures();
    static void createModels();
};

#endif
