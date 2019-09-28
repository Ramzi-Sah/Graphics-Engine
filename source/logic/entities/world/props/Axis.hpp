#ifndef SAH_AXIS
#define SAH_AXIS

#include "Props.hpp"

class Axis : public Props {
public:
    Axis() {
        type = "axis";
        m_model = ModelLoader::getModel(type);
    };
};

#endif
