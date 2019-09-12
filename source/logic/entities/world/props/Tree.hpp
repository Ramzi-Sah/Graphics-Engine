#ifndef SAH_TREE
#define SAH_TREE

#include "Props.hpp"

class Tree : public Props {
public:
    Tree() {
        m_model = ModelLoader::getModel("tree");
    };
};

#endif
