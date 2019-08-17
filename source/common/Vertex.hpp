#ifndef SAH_VERTEX
#define SAH_VERTEX

#include "Vectors.hpp"

struct Vertex {
    glm::vec3 position;
    glm::vec2 uv;
    glm::vec3 normal;

    Vertex(glm::vec3 _position, glm::vec2 _uv, glm::vec3 _normal) {
        position = _position;
        uv = _uv;
        normal = _normal;
    }
};

#endif
