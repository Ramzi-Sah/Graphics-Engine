#include "World.hpp"

Terrain* World::m_terrain;
 Axis* World::m_axis;

World::World(float _x, float _z) {
    // set light
    Light::setAmbientLight(glm::vec3(0.5f, 0.5f, 0.5f));
    Light::createDirectionalLight(glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.8f, 0.8f, 0.8f));

    // DEBUG: render Axis
    m_axis = new Axis();

    // create terrain
    m_terrain = new Terrain(_x, _z);
}

/*----------------------------------------*/
void World::update(float playerPosX, float playerPosZ) {
    // update terrain
    m_terrain->update(playerPosX, playerPosZ);
};

void World::render() {
    // DEBUG: render Axis
    // m_axis->render();

    // render terrain
    m_terrain->render();

    // render all props
    for (int i = 0; i < props.size(); i++) {
        props[i]->render();
    };
};


/*------------------ prop handling ------------------------*/
std::vector<Props*> World::props;
void World::deleteProp(Props* prop) {
    // get all props
    for (int i = 0; i < props.size(); i++) {
        // get prop from pionter
        if (prop->id == props[i]->id) {
            // std::cout << "prop deleted id: " << props[i]->id << " type: " << props[i]->type << '\n';

            // delete prop from props list
            props.erase(props.begin() + i);

            // FIXME: is prop deleted ?
            delete prop;
        }
    }
};

Axis* World::createAxis(glm::vec3 pos) {
    // instinitiate axis
    Axis* ax = new Axis();
    ax->setPosition(pos.x, pos.y, pos.z);

    // push it to list
    props.push_back(ax);

    return ax;
};

Wall* World::createWall(glm::vec3 pos) {
    // instinitiate axis
    Wall* wall = new Wall();
    wall->setPosition(pos.x, pos.y, pos.z);

    // push it to list
    props.push_back(wall);

    return wall;
};
