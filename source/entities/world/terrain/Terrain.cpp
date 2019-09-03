#include "Terrain.hpp"

Terrain::Terrain() {
    // generate terrain chunks
    for (int x = 0; x < nbrTerrainChunks; x++) {
        for (int z = 0; z < nbrTerrainChunks; z++) {
            // add it to terrain chunk list
            terrainChunks[x][z] = TerrainChunk(x - offset, z - offset);
        }
    }
}

void Terrain::render() {
    // render all chunks
    for (int x = 0; x < nbrTerrainChunks; x++) {
        for (int z = 0; z < nbrTerrainChunks; z++) {
            terrainChunks[x][z].render();
        }
    }
}

void Terrain::update(float _x, float _z) {
    // from pos to grid pos
    int GridPosX = posToGridPos(_x);
    int GridPosZ = posToGridPos(_z);

    // reorder terrainChunks array and create new terrain chunks row
    if (terrainPosX != GridPosX) {

        if (terrainPosX < GridPosX) {
            for (int x = 0; x < nbrTerrainChunks; x++) {
                for (int z = 0; z < nbrTerrainChunks; z++) {
                    if (x+1 == nbrTerrainChunks)
                        terrainChunks[x][z] = TerrainChunk(GridPosX + nbrTerrainChunks-1 - offset, GridPosZ + z - offset);
                    else
                        terrainChunks[x][z] = terrainChunks[x+1][z];
                }
            }
        } else {
            for (int x = nbrTerrainChunks-1; x >= 0; x--) {
                for (int z = nbrTerrainChunks-1; z >= 0; z--) {
                    if (x == 0)
                        terrainChunks[0][z] = TerrainChunk(GridPosX - offset, GridPosZ + z - offset);
                    else
                        terrainChunks[x][z] = terrainChunks[x-1][z];
                }
            }
        }

        terrainPosX = GridPosX;
    }

    if (terrainPosZ != GridPosZ) {

        if (terrainPosZ < GridPosZ) {
            for (int x = 0; x < nbrTerrainChunks; x++) {
                for (int z = 0; z < nbrTerrainChunks; z++) {
                    if (z+1 == nbrTerrainChunks)
                        terrainChunks[x][z] = TerrainChunk(GridPosX + x - offset, GridPosZ + nbrTerrainChunks-1 - offset);
                    else
                        terrainChunks[x][z] = terrainChunks[x][z+1];
                }
            }
        } else {
            for (int x = nbrTerrainChunks-1; x >= 0; x--) {
                for (int z = nbrTerrainChunks-1; z >= 0; z--) {
                    if (z == 0)
                        terrainChunks[x][0] = TerrainChunk(GridPosX + x - offset, GridPosZ - offset);
                    else
                        terrainChunks[x][z] = terrainChunks[x][z-1];
                }
            }
        }

        terrainPosZ = GridPosZ;
    }

}

int Terrain::posToGridPos(float _val) {
    return _val / nbrTiles / tileSize;
};
