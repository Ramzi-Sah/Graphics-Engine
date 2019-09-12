#ifndef SAH_AXIS
#define SAH_AXIS

#include "Props.hpp"

class Axis : public Props {
public:
    Axis() {
        m_model = ModelLoader::getModel("axis");
    };
};

#endif
