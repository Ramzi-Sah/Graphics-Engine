#ifndef SAH_TREE
#define SAH_TREE

#include "Props.hpp"

class Tree : public Props {
public:
    Tree() {
        type = "tree";
        m_model = ModelLoader::getModel(type);
    };
};

#endif
