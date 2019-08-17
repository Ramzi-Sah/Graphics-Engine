#ifndef SAH_TERRAIN
#define SAH_TERRAIN

#include <vector>

#include "../Entity.hpp"
#include "TerrainChunk.hpp"

class Terrain : public Entity {
private:
    static std::vector<TerrainChunk> m_terrainChunks;


public:
    Terrain();
    ~Terrain() {};

    void render();
};

#endif
