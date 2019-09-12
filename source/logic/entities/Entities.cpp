#include "Entities.hpp"

World* Entities::m_world;
Player* Entities::m_player;

Entities::Entities() {
    m_world = new World();
    m_player = new Player();
};

/*--------------------------------------------------*/
void Entities::update(float deltaTime) {
    // update player
    glm::vec3 playerPos = m_player->update(deltaTime);

    // update terrain
    m_world->update(playerPos.x, playerPos.z);
};

/*--------------------------------------------------*/
void Entities::render() {
    // render terrain
    m_world->render();

    // render player
    m_player->render();
};

/*--------------------------------------------------*/
void Entities::keyEventInput(int key, int action) {
    // player handle keyboard input
    m_player->keyEventInput(key, action);
};

void Entities::MouseEventInput(bool mouseDisabled, double xpos, double ypos) {
    // player handle mouse input event
    m_player->MouseEventInput(mouseDisabled, xpos, ypos);
};
