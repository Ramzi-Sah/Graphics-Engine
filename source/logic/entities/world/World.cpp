#include "World.hpp"

Terrain* World::m_terrain;

World::World() {
    // set light
    Light::setAmbientLight(glm::vec3(0.5f, 0.5f, 0.5f));
    Light::createDirectionalLight(glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.8f, 0.8f, 0.8f));

    // create terrain
    m_terrain = new Terrain();


}

/*----------------------------------------*/
void World::update(float playerPosX, float playerPosZ) {
    // update terrain
    m_terrain->update(playerPosX, playerPosZ);
};

void World::render() {
    // render terrain
    m_terrain->render();
};
