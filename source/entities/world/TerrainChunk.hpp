#ifndef SAH_TERRAINCHUNK
#define SAH_TERRAINCHUNK

#include <iostream>
#include <random>
#include <math.h>

#include "../../engine/Model.hpp"
#include "../../common/Vectors.hpp"
#include "../../common/PerlinNoise.hpp"

class TerrainChunk {
private:
    glm::vec2 m_position;

    // for terrain chunk model
    void generateMesh(); // FIXME: use only 1 vertex

public:
    TerrainChunk(float gridX, float gridZ);
    ~TerrainChunk() {};

    // chunk model
    Model model;

    // terrain chunks params
    static const int nbrChunks;
    static const int nbrTiles;
    static const float tileSize;

};

#endif
