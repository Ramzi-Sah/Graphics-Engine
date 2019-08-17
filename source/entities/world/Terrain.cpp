#include "Terrain.hpp"

std::vector<TerrainChunk> Terrain::m_terrainChunks;

Terrain::Terrain() {
    // generate terrain chunks
    for (int x = 0; x < TerrainChunk::nbrChunks; x++) {
        for (int z = 0; z < TerrainChunk::nbrChunks; z++) {
            m_terrainChunks.push_back(TerrainChunk(x, z));
        }
    }

}

void Terrain::render() {
    // render all chunks
    for (int i = 0; i < m_terrainChunks.size(); i++) {
        m_terrainChunks[i].model.render();
    }
}
