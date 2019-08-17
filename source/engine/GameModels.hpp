#ifndef SAH_GAMEMODELS
#define SAH_GAMEMODELS

#include <vector>

#include "Model.hpp"

class GameModels {
private:

public:
    GameModels() {};
    ~GameModels() {};

    static std::vector<Model*> models;

    // model prefab
    static Model* createCube(float posX, float posY, float posZ, glm::vec4 color);
};

#endif
