#include "Bioms.hpp"

PerlinNoise Bioms::m_hightsNoise = PerlinNoise(SEED);
float Bioms::getHight(float x, float z) {
    float y = m_hightsNoise.noise(x * FREQUANCY, z * FREQUANCY) + m_hightsNoise.noise(x * FREQUANCY * 2, z * FREQUANCY * 2) / 2 + m_hightsNoise.noise(x * FREQUANCY * 4, z * FREQUANCY * 4) / 4;
    y = pow(y, ELEVATION);
    y *= AMPLITUDE;

    return y;
}

glm::vec3 Bioms::getColor(float x, float z) {
    // FIXME: handle terrain colors
    return glm::vec3(0.2f, 1.0f, 0.3f);
}

PerlinNoise Bioms::m_TreesNoise = PerlinNoise(SEED+1);
bool Bioms::getTree(float x, float z) {
    float y = m_hightsNoise.noise(x * FREQUANCY * 20 / tileSize, z * FREQUANCY * 20 / tileSize);
    y = pow(y, ELEVATION);
    y *= AMPLITUDE;

    if (y > 5) {
        return true;
    }

    return false;
}

PerlinNoise Bioms::m_GrassNoise = PerlinNoise(SEED+2);
bool Bioms::getGrass(float x, float z) {
    float y = m_GrassNoise.noise(x * FREQUANCY * 25 / tileSize, z * FREQUANCY * 25 / tileSize);
    y = pow(y, ELEVATION);
    y *= AMPLITUDE;

    if (y > 5) {
        return true;
    }

    return false;
}
