#ifndef SAH_MATERIAL
#define SAH_MATERIAL

#include "Vectors.hpp"
#include "../engine/assets/TextureLoader.hpp"

struct Material {
    glm::vec4 defuse = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
    unsigned int map_defuse = TextureLoader::getTexture("Default");

    Material() {};

    void setDefuse(glm::vec4 _defuse) {
        defuse = _defuse;
    };

    void setDefuseMap(unsigned int _defuseMap) {
        map_defuse = _defuseMap;
    };
};

#endif
