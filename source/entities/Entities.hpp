#ifndef SAH_Entities
#define SAH_Entities

#include <iostream>
#include <vector>

#include "../common/Vectors.hpp"
#include "../engine/Display.hpp"
#include "Player.hpp"
#include "world/World.hpp"

class Entities {
private:
    Camera* camera;
    Terrain m_terrain;
    Player m_player;

public:
    Entities(unsigned int _width, unsigned int _height);
    ~Entities() {};

    void update(GLFWwindow* window, float deltaTime);
    void render();
};

#endif
