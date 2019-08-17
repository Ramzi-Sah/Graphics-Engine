#include "AssetLoader.hpp"

void AssetLoader::createShaderPrograms() {
    ShaderLoader::createShaderProgram("Default", "assets/shaders/default");
    ShaderLoader::createShaderProgram("test", "assets/shaders/test");
}

void AssetLoader::createTextures() {
    TextureLoader::createTexture("Default", "assets/textures/default.jpg");
    TextureLoader::createTexture("box", "assets/textures/container.jpg");
    TextureLoader::createTexture("wall", "assets/textures/wall.jpg");
}

void AssetLoader::createModels() {
    ModelLoader::createModel("test");
    ModelLoader::createModel("tank");
    ModelLoader::createModel("tree");
}
