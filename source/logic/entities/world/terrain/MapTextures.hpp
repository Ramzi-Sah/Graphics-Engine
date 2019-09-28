#ifndef SAH_MapTextures
#define SAH_MAPTEXTURES

#include <iostream>
#include "../../../../common/Geometry.hpp"
#include "../../../../engine/assets/TextureLoader.hpp"
#include "TerrainConfig.hpp"

class MapTextures {
private:
    // height map
    static unsigned char* heightMap;
    static int width_heightMap, height_heightMap, nbrChannels_heightMap;
    static float getPixel_heightMap(int x, int z);

    // blend map grass
    static unsigned char* blendMap_grass;
    static int width_blendMap_grass, height_blendMap_grass, nbrChannels_blendMap_grass;
    static float getPixel_blendMap_grass(int x, int z);

public:
    // height map
    static void loadMapTexture_heightMap(std::string filePath);
    static float interpolateHeight(float x, float z);

    // blend map grass
    static void loadMapTexture_blendMap_grass(std::string filePath);
    static float interpolateGrassVal(float x, float z);

};

#endif
