#ifndef SAH_Entity
#define SAH_Entity

#include <vector>

#include "../common/Vectors.hpp"
#include "../engine/Model.hpp"

class Entity {
private:
    glm::vec3 m_position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 m_size = glm::vec3(1.0f, 1.0f, 1.0f);


public:
    Entity();
    ~Entity() {};

};

#endif
