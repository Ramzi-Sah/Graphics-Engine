#ifndef SAH_BIOMS
#define SAH_BIOMS

#include <iostream>
#include <math.h>

#include "../../../common/Vectors.hpp"
#include "../../../common/PerlinNoise.hpp"

#include "TerrainConfig.hpp"

class Bioms {
private:
    static PerlinNoise m_hightsNoise;

    static PerlinNoise m_TreesNoise;
    static PerlinNoise m_GrassNoise;


public:
    Bioms() {};
    ~Bioms() {};

    static float getHight(float x, float z);
    static glm::vec3 getColor(float x, float z);

    static bool getTree(float x, float z);
    static bool getGrass(float x, float z);
};

#endif
