#ifndef SAH_TERRAIN
#define SAH_TERRAIN

#include <iostream>
#include <vector>

#include "../../../../engine/Model.hpp"
#include "../../../../common/Vectors.hpp"

#include "TerrainConfig.hpp"
#include "TerrainChunk.hpp"

class Terrain {
private:
    TerrainChunk terrainChunks[nbrTerrainChunks][nbrTerrainChunks];

    // for terrain update
    int terrainPosX, terrainPosZ;
    int offset = nbrTerrainChunks / 2;

    // Lod 2
    void updateLOD2(int _x, int _z);
    TerrainChunk terrainChunks2[nbrTerrainChunks * 4][nbrTerrainChunks * 4 + nbrTerrainChunks + 1]; // 4 in a square


public:
    Terrain(float _x, float _z);
    ~Terrain() {};

    void render();
    void update(float x, float z);

    static int posToGridPos(float _val);
};

#endif
