#ifndef SAH_MODELLOADER
#define SAH_MODELLOADER

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

#define SAH_NULL_STR "Sah_null_str"

#include "../Model.hpp"
#include "../../common/Material.hpp"
#include "TextureLoader.hpp"

class ModelLoader {
private:
    static std::map<std::string, Model*> m_models;

public:
    ModelLoader() {};
    ~ModelLoader() {};

    static void createModel(std::string modelName);
    static Model* getModel(std::string modelName);
    static void deleteModel();

};

#endif
