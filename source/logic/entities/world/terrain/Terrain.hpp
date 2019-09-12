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
    int terrainPosX = 0, terrainPosZ = 0;
    int offset = nbrTerrainChunks / 2;


public:
    Terrain();
    ~Terrain() {};

    void render();
    void update(float x, float z);

    static int posToGridPos(float _val);
};

#endif
