#ifndef SAH_WORLD
#define SAH_WORLD

#include "../../../engine/Light.hpp"
#include "terrain/Terrain.hpp"

// static props
#include "props/Axis.hpp"
#include "props/Tree.hpp"
#include "props/Grass.hpp"

// placebales
#include "props/placebales/Wall.hpp"

class World {
private:
    static Terrain* m_terrain;
    static Axis* m_axis;

    static std::vector<Props*> props;

public:
    World(float _x, float _z);
    ~World() {};

    void render();
    void update(float playerPosX, float playerPosZ);

    // prop handling
    static void deleteProp(Props* prop);

    // DEBUG: create axis
    static Axis* createAxis(glm::vec3 pos);
    static Wall* createWall(glm::vec3 pos);

};


#endif
