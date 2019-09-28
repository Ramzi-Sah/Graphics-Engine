#ifndef SAH_BIOMS
#define SAH_BIOMS

#include <iostream>
#include <math.h>

#include "../../../../common/Vectors.hpp"
#include "../../../../common/PerlinNoise.hpp"
#include "../../../../engine/assets/ShaderLoader.hpp"

#include "TerrainConfig.hpp"
#include "MapTextures.hpp"

class Bioms {
private:
    // perlin noise
    static PerlinNoise m_hightsNoise;
    static PerlinNoise m_TreesNoise;
    static PerlinNoise m_GrassNoise;

public:
    Bioms() {};
    ~Bioms() {};

    static void init();

    static float getHight(float x, float z);
    static float getGrassValue(float x, float z);

    static bool getTree(float x, float z);
    static bool getGrass(float x, float z);
};

#endif
