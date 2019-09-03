#ifndef SAH_PROPS
#define SAH_PROPS

#include "../../../common/Vectors.hpp"
#include "../../../engine/Model.hpp"
#include "../../../engine/assets/AssetLoader.hpp"

class Props {
private:


public:
    Props();
    ~Props() {};

    // render
    Model m_model;
    void render();

    // transform
    void setPosition(float _posX, float _posY, float _posZ);
    void setScale(float _scaleX, float _scaleY, float _scaleZ);
    void setRotation(float _rotDeg, glm::vec3 axes);
};

#endif
