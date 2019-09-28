#include "Entities.hpp"

World* Entities::m_world;
Player* Entities::m_player;

Entities::Entities() {
    // init player
    m_player = new Player();

    // init terrain
    glm::vec3 playerPos =  m_player->getPos();
    m_world = new World(playerPos.x, playerPos.z);
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

/*----------------------- handle ---------------------------*/
void Entities::keyEventInput(int key, int action) {
    // player handle keyboard input
    m_player->keyEventInput(key, action);
};

void Entities::MouseEventInput(bool mouseEnabled, int xpos, int ypos) {
    // player handle mouse input event
    m_player->MouseEventInput(mouseEnabled, xpos, ypos);
};

void Entities::MouseClickEventInput(bool mouseEnabled, int button, int action, int mouseXPos, int mouseYPos) {
    // player handle mouse input event
    m_player->MouseClickEventInput(mouseEnabled, button, action, mouseXPos, mouseYPos);
};

/*------------------ GUI ---------------------------*/
glm::vec3 Entities::GUIget_playerPos() {
    // return player pos
    return m_player->getPos();
};
