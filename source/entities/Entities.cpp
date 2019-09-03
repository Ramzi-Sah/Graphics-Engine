#include "Entities.hpp"

Entities::Entities(unsigned int _width, unsigned int _height) {
    // create camera
    camera = new Camera(_width, _height);
};

//FIXME: can be optimized (when no input)
void Entities::update(GLFWwindow* window, float deltaTime) {
    // update player
    glm::vec3 playerPos = m_player.update(window, deltaTime, Display::mouseDisabled, Display::mouseXPos);

    // attach camera to player
    camera->attach(playerPos, deltaTime, m_player.getYaw(), Display::mouseDisabled, Display::mouseYPos);

    // update terrain
    m_terrain.update(playerPos.x, playerPos.z);
};

void Entities::render() {
    // render terrain
    m_terrain.render();

    // render player
    m_player.render();
};
