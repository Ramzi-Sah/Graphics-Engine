#ifndef SAH_Entities
#define SAH_Entities

#include <iostream>
#include <vector>

#include "world/World.hpp"
#include "player/Player.hpp"

class Entities {
private:
    static World* m_world;
    static Player* m_player;

public:
    Entities();
    ~Entities() {};

    // rendering
    static void render();

    // logic
    static void update(float deltaTime);

    // handle
    static void keyEventInput(int key, int action);
    static void MouseEventInput(bool mouseEnabled, int xpos, int ypos);
    static void MouseClickEventInput(bool mouseEnabled, int button, int action, int mouseXPos, int mouseYPos);

    // GUI
    static glm::vec3 GUIget_playerPos();
};

#endif
