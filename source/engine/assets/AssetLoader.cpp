#include "AssetLoader.hpp"

void AssetLoader::createShaderPrograms() {
    // default shader
    ShaderLoader::createShaderProgram("Default", "assets/shaders/default");

    // terrain shader
    ShaderLoader::createShaderProgram("terrain", "assets/shaders/terrain");
}

void AssetLoader::createTextures() {
    TextureLoader::createTexture("Default", "assets/textures/default.jpg", false);

    // terrain
    TextureLoader::createTexture("terrain_grass", "assets/terrain/textures/grass.jpg", false);
    TextureLoader::createTexture("terrain_rock", "assets/terrain/textures/rock.jpg", false);
}

void AssetLoader::createModels() {
    // player
    ModelLoader::createModel("player", "player");

    // building
    ModelLoader::createModel("wall", "building/wall");

    // animals

    // static props
    ModelLoader::createModel("axis", "axis");
    ModelLoader::createModel("tree", "tree");
    ModelLoader::createModel("grass_1", "grass/grass_1");
}
