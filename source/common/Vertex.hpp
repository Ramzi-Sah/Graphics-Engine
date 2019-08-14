#ifndef SAH_VERTEX
#define SAH_VERTEX

#include "Vectors.hpp"

struct Vertex {
    glm::vec3 position;
    glm::vec4 color;
    glm::vec2 uv;

    Vertex(glm::vec3 _position, glm::vec4 _color, glm::vec2 _uv) {
        position = _position;
        color = _color;
        uv = _uv;
    }
};

#endif
