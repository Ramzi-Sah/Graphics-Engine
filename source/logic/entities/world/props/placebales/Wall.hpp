#ifndef SAH_WALL
#define SAH_WALL

#include "Placebale.hpp"

class Wall : public Placebale {
private:

public:
    Wall() {
        type = "wall";
        m_model = ModelLoader::getModel(type);
    };
};

#endif
