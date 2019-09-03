#include "AssetLoader.hpp"

void AssetLoader::createShaderPrograms() {
    ShaderLoader::createShaderProgram("Default", "assets/shaders/default");
}

void AssetLoader::createTextures() {
    TextureLoader::createTexture("Default", "assets/textures/default.jpg");
}

void AssetLoader::createModels() {
    // player
    ModelLoader::createModel("player", "player");

    // animals

    // static props
    ModelLoader::createModel("axis", "axis");
    ModelLoader::createModel("tree", "tree");
    ModelLoader::createModel("grass_1", "grass/grass_1");
}
