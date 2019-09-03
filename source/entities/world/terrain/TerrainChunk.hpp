#ifndef SAH_TERRAINCHUNK
#define SAH_TERRAINCHUNK

#include <iostream>
#include <random>
#include <math.h>

#include "../../../common/Vectors.hpp"
#include "../../../engine/Model.hpp"

#include "TerrainConfig.hpp"
#include "Bioms.hpp"

#include "../props/Tree.hpp"
#include "../props/Grass.hpp"

class TerrainChunk {
private:
    glm::vec2 m_gridPos;
    Model m_model;

    std::vector<Tree> m_trees;
    std::vector<Grass> m_grass;

    void generateMesh();
    void generateTile(int x, int z);
    void addProps(float x, float z);

public:
    TerrainChunk(int x, int z);
    TerrainChunk() {};
    ~TerrainChunk() {};

    void render();

};

#endif
