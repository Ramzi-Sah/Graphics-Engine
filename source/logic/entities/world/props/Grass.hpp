#ifndef SAH_GRASS
#define SAH_GRASS

#include <random>
#include <vector>

#include "Props.hpp"

class Grass : public Props {
private:
    std::vector<std::string> m_grassVector = {"grass_1"};

public:
    Grass() {
        unsigned int grassType = rand() % m_grassVector.size();
        m_model = ModelLoader::getModel(m_grassVector[grassType]);
    };
};

#endif
