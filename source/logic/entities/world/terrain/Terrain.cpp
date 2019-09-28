#include "Terrain.hpp"

Terrain::Terrain(float _x, float _z) {
    // init bioms
    Bioms::init();

    // from pos to grid pos
    terrainPosX = posToGridPos(_x);
    terrainPosZ = posToGridPos(_z);

    // generate terrain chunks
    for (int x = 0; x < nbrTerrainChunks; x++) {
        for (int z = 0; z < nbrTerrainChunks; z++) {
            // add it to terrain chunk list
            terrainChunks[x][z] = TerrainChunk(terrainPosX + x - offset, terrainPosZ + z - offset, 1);
        };
    };

    // generate lod 2 chunks
    // updateLOD2(0, 0);
}

void Terrain::render() {
    // render base lod chunks
    for (int x = 0; x < nbrTerrainChunks; x++) {
        for (int z = 0; z < nbrTerrainChunks; z++) {
            terrainChunks[x][z].render();
        };
    };

    // // render lod 2 chunks
    // for (int x = 0; x < nbrTerrainChunks * 4; x++) {
    //     for (int z = 0; z < nbrTerrainChunks * 4 + nbrTerrainChunks + 1; z++) {
    //         terrainChunks2[x][z].render();
    //     }
    // }
};

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
                        terrainChunks[x][z] = TerrainChunk(GridPosX + nbrTerrainChunks - 1 - offset, GridPosZ + z - offset, 1);
                    else
                        terrainChunks[x][z] = terrainChunks[x+1][z];
                }
            }
        } else {
            for (int x = nbrTerrainChunks-1; x >= 0; x--) {
                for (int z = nbrTerrainChunks-1; z >= 0; z--) {
                    if (x == 0)
                        terrainChunks[0][z] = TerrainChunk(GridPosX - offset, GridPosZ + z - offset, 1);
                    else
                        terrainChunks[x][z] = terrainChunks[x-1][z];
                };
            };
        };

        // update terrain lods
        // updateLOD2(GridPosX, GridPosZ);

        // set terrain posX
        terrainPosX = GridPosX;
    };

    if (terrainPosZ != GridPosZ) {

        if (terrainPosZ < GridPosZ) {
            for (int x = 0; x < nbrTerrainChunks; x++) {
                for (int z = 0; z < nbrTerrainChunks; z++) {
                    if (z+1 == nbrTerrainChunks)
                        terrainChunks[x][z] = TerrainChunk(GridPosX + x - offset, GridPosZ + nbrTerrainChunks - 1 - offset, 1);
                    else
                        terrainChunks[x][z] = terrainChunks[x][z+1];
                };
            };
        } else {
            for (int x = nbrTerrainChunks-1; x >= 0; x--) {
                for (int z = nbrTerrainChunks-1; z >= 0; z--) {
                    if (z == 0)
                        terrainChunks[x][0] = TerrainChunk(GridPosX + x - offset, GridPosZ - offset, 1);
                    else
                        terrainChunks[x][z] = terrainChunks[x][z-1];
                };
            };
        };

        // update terrain lods
        // updateLOD2(GridPosX, GridPosZ);

        // set terrain posY
        terrainPosZ = GridPosZ;
    };
}

void Terrain::updateLOD2(int _x, int _z) {
    int k = 0;
    for (int i = 0; i <= nbrTerrainChunks; i += 4) {
    // int i = 0;
        // right
        for (int j = 0; j < nbrTerrainChunks + 1 + k * 2; j++) {
            terrainChunks2[i + 0][j] = TerrainChunk(nbrTerrainChunks/2 + 1 + k + _x, j - offset + k - 2 * k + _z, 2);
        };
        // left
        for (int j = 0; j < nbrTerrainChunks + 1 + k * 2; j++) {
            terrainChunks2[i + 1][j] = TerrainChunk(-nbrTerrainChunks/2 - 1 - k + _x, j - offset - 1 - k + _z, 2);
        };
        // up
        for (int j = 0; j < nbrTerrainChunks + 1 + k * 2; j++) {
            terrainChunks2[i + 2][j] = TerrainChunk(j - offset - 1 - k + _x, nbrTerrainChunks/2 + 1 + k + _z, 2);
        };
        // down
        for (int j = 0; j < nbrTerrainChunks + 1 + k * 2; j++) {
            terrainChunks2[i + 3][j] = TerrainChunk(j - offset + k - 2 * k + _x, -nbrTerrainChunks/2 - 1 - k + _z, 2);
        };

        k++;
    };
}

int Terrain::posToGridPos(float _val) {
    // the terrainChunks grid conatins chunks (nbrTiles) & chunks conatin tiles (tileSize)
    return _val / nbrTiles / tileSize;
};
