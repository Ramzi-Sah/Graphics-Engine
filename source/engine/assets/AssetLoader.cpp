#include "AssetLoader.hpp"

void AssetLoader::createShaderPrograms() {
    ShaderLoader::createShaderProgram("Default", "assets/shaders/default");
    ShaderLoader::createShaderProgram("test", "assets/shaders/test");

}
