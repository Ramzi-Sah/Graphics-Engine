#include "Light.hpp"

/*------------------------- Ambient Light ------------------------------*/
void Light::setAmbientLight(glm::vec3 _ambientLight) {
    // set all shader program's ambientLight uniform
    for (auto it = ShaderLoader::shaderPrograms.cbegin(); it != ShaderLoader::shaderPrograms.cend(); ++it) {
        glUseProgram(it->second);
        unsigned int ambientLightLoc = glGetUniformLocation(it->second, "ambientLight");
        glUniform3f(ambientLightLoc, _ambientLight.r, _ambientLight.g, _ambientLight.b);
    }
};

/*------------------------- Defuse Light ------------------------------*/
void Light::createDirectionalLight(glm::vec3 lightDirection, glm::vec3 lightColor) {

    // set all shader program's ambientLight uniform
    for (auto it = ShaderLoader::shaderPrograms.cbegin(); it != ShaderLoader::shaderPrograms.cend(); ++it) {
        glUseProgram(it->second);
        unsigned int lightPosLoc = glGetUniformLocation(it->second, "lightDir");
        glUniform3f(lightPosLoc, lightDirection.x, lightDirection.y, lightDirection.z);

        unsigned int lightColorLoc = glGetUniformLocation(it->second, "lightColor");
        glUniform3f(lightColorLoc, lightColor.r, lightColor.g, lightColor.b);
    }
};

/*------------------------ handle uniforms -------------------------------*/
void Light::setUniformLight() {

};

void Light::update() {
    setUniformLight();
};
