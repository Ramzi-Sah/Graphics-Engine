#ifndef SAH_RAY
#define SAH_RAY

#include "Vectors.hpp"

struct Ray {
    glm::vec3 direction;
    glm::vec3 position;

    Ray() {};

    Ray(glm::vec3 _direction, glm::vec3 _position) {
        direction = _direction;
        position = _position;
    };
};

#endif
