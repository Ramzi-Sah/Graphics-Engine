#ifndef SAH_WORLD
#define SAH_WORLD

#include "../../../engine/Light.hpp"
#include "terrain/Terrain.hpp"

// static props
#include "props/Axis.hpp"
#include "props/Tree.hpp"
#include "props/Grass.hpp"

class World {
private:
    static Terrain* m_terrain;

public:
    World();
    ~World() {};

    void render();
    void update(float playerPosX, float playerPosZ);
};


#endif
