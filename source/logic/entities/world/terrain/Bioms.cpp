#include "Bioms.hpp"

// load terrain data
void Bioms::init() {
    std::string filepath;

    // load terrain hight map
    MapTextures::loadMapTexture_heightMap("assets/terrain/terrain.png");

    // grass blend map
    MapTextures::loadMapTexture_blendMap_grass("assets/terrain/terrain.png");

    // terrain textures
    unsigned int terrainShader = ShaderLoader::getShader("terrain");
    glUseProgram(terrainShader);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, TextureLoader::getTexture("terrain_grass"));
    glUniform1i(glGetUniformLocation(terrainShader, "grass_texture"), 1);

    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, TextureLoader::getTexture("terrain_rock"));
    glUniform1i(glGetUniformLocation(terrainShader, "rock_texture"), 2);

};

/*-------------------------------------------------*/
float Bioms::getHight(float x, float z) {
    return MapTextures::interpolateHeight(x, z) * AMPLITUDE;
};

float Bioms::getGrassValue(float x, float z) {
    return MapTextures::interpolateGrassVal(x, z) + 0.5f;
};

/*-------------------------------------------------*/
PerlinNoise Bioms::m_hightsNoise = PerlinNoise(SEED);
PerlinNoise Bioms::m_TreesNoise = PerlinNoise(SEED+1);
PerlinNoise Bioms::m_GrassNoise = PerlinNoise(SEED+2);
bool Bioms::getTree(float x, float z) {
    float y = m_hightsNoise.noise(x * FREQUANCY * 20 / tileSize, z * FREQUANCY * 20 / tileSize) * 7;

    if (y > 5)
        return true;

    return false;
};

bool Bioms::getGrass(float x, float z) {
    float y = m_GrassNoise.noise(x * FREQUANCY * 25 / tileSize, z * FREQUANCY * 25 / tileSize) * 10;

    if (y > 5)
        return true;

    return false;
};
