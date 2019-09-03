#include "Props.hpp"

Props::Props() {
    // set default model
    m_model = ModelLoader::getModel("axis");
};

/*------------------ rander --------------*/
void Props::render() {
    m_model.render();
};

/*------------------ transfrom --------------*/
void Props::setPosition(float _posX, float _posY, float _posZ) {
    m_model.setPosition(glm::vec3(_posX, _posY, _posZ));
};

void Props::setScale(float _scaleX, float _scaleY, float _scaleZ) {
    m_model.setScale(glm::vec3(_scaleX, _scaleY, _scaleZ));
};

void Props::setRotation(float _rotDeg, glm::vec3 axes) {
    m_model.setRotation(_rotDeg, axes);
};
