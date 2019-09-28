#ifndef SAH_TERRAINCHUNK
#define SAH_TERRAINCHUNK

#include <iostream>
#include <random>
#include <math.h>

#include "../../../../common/Vectors.hpp"
#include "TerrainChunkModel.hpp"

#include "TerrainConfig.hpp"
#include "Bioms.hpp"

#include "../props/Tree.hpp"
#include "../props/Grass.hpp"

class TerrainChunk {
private:
    glm::vec2 m_pos = glm::vec2(0.0f, 0.0f);
    glm::vec2 m_gridPos = glm::vec2(0.0f, 0.0f);
    TerrainChunkModel m_model;

    std::vector<Tree> m_trees;
    std::vector<Grass> m_grass;

    float m_LOD = 1;

    // DEBUG: random chunk color
    glm::vec3 m_chunkColor;

    void generateMesh();
    void generateTile(int x, int z);
    void addProps(float x, float z);

    // vertex attrib
    glm::vec3 getVertexPos(int x, int z);
    glm::vec3 getVertexNormal(int x, int z);

public:
    TerrainChunk(int x, int z, float lod);
    TerrainChunk() {};
    ~TerrainChunk() {};

    void render();
};

#endif
