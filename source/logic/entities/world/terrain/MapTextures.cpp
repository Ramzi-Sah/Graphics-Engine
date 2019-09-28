#include "MapTextures.hpp"

// height map
unsigned char* MapTextures::heightMap;
int MapTextures::width_heightMap, MapTextures::height_heightMap, MapTextures::nbrChannels_heightMap;

void MapTextures::loadMapTexture_heightMap(std::string filePath) {
    // load terrain hight map
    heightMap = stbi_load(filePath.c_str(), &width_heightMap, &height_heightMap, &nbrChannels_heightMap, 0);
    if (!heightMap) {
        std::cout << "Warning: Failed to load map data \"" << "assets/terrain/terrain.png" << "\"." << std::endl;
        std::terminate();
    };
};

float MapTextures::getPixel_heightMap(int x, int z) {
    return heightMap[(z * width_heightMap + x) * nbrChannels_heightMap] / 255.0f;
};

float MapTextures::interpolateHeight(float x, float z) {
    // init y value
    float y = 0.0f;

    // chek if is on hight map
    if (x < width_heightMap * heightMapSizeMultiplayer && x > 0 && z < height_heightMap * heightMapSizeMultiplayer && z > 0) {

        // heighmap size
        x /= heightMapSizeMultiplayer;
        z /= heightMapSizeMultiplayer;

        // get grid pos values std::roundf(x / tileSize) * tileSize;
        int pixelX = std::roundf(x);
        int pixelZ = std::roundf(z);

        if (pixelX > x)
            pixelX -= 1;
        if (pixelZ > z)
            pixelZ -= 1;

        // resize x & y to grid coordenates
        float pixelOffset_x = x - pixelX;
        float pixelOffset_z = z - pixelZ;

        /*------------- bicubic interpolation --------------*/
        // 16 terms
        static float pixelHeights[4][4];

        // get heights
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                pixelHeights[i][j] = getPixel_heightMap(pixelX + i - 1, pixelZ + j - 1);
            };
        };

        // calculate a coeficients
        y = Geometry::bicubicInterpolate(pixelHeights, pixelOffset_x, pixelOffset_z);

        // mult by map size
        y *= heightMapSizeMultiplayer;
    };

    // return height value
    return y;
};

/*-------------------------------------------------------------*/
// blend map grass
unsigned char* MapTextures::blendMap_grass;
int MapTextures::width_blendMap_grass, MapTextures::height_blendMap_grass, MapTextures::nbrChannels_blendMap_grass;

void MapTextures::loadMapTexture_blendMap_grass(std::string filePath) {
    // load terrain hight map
    blendMap_grass = stbi_load(filePath.c_str(), &width_blendMap_grass, &height_blendMap_grass, &nbrChannels_blendMap_grass, 0);
    if (!blendMap_grass) {
        std::cout << "Warning: Failed to load map data \"" << "assets/terrain/terrain.png" << "\"." << std::endl;
        std::terminate();
    };
};

float MapTextures::getPixel_blendMap_grass(int x, int z) {
    return blendMap_grass[(z * width_blendMap_grass + x) * nbrChannels_blendMap_grass] / 255.0f;
};

float MapTextures::interpolateGrassVal(float x, float z) {
    // init y value
    float y = 0.0f;

    // chek if is on hight map
    if (x < width_blendMap_grass * heightMapSizeMultiplayer && x > 0 && z < height_blendMap_grass * heightMapSizeMultiplayer && z > 0) {

        // heighmap size
        x /= heightMapSizeMultiplayer;
        z /= heightMapSizeMultiplayer;

        // get grid pos values std::roundf(x / tileSize) * tileSize;
        int pixelX = std::roundf(x);
        int pixelZ = std::roundf(z);

        if (pixelX > x)
            pixelX -= 1;
        if (pixelZ > z)
            pixelZ -= 1;

        // resize x & y to grid coordenates
        float pixelOffset_x = x - pixelX;
        float pixelOffset_z = z - pixelZ;

        /*------------- bicubic interpolation --------------*/
        // 16 terms
        static float pixelHeights[4][4];

        // get heights
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                pixelHeights[i][j] = getPixel_blendMap_grass(pixelX + i - 1, pixelZ + j - 1);
            };
        };

        // calculate a coeficients
        y = Geometry::bicubicInterpolate(pixelHeights, pixelOffset_x, pixelOffset_z);

        // std::cout << y << '\n';
    };

    // return height value
    return y;
};
