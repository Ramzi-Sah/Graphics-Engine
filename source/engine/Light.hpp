#ifndef SAH_LIGHT
#define SAH_LIGHT

#define SAH_DIRECTIONAL_LIGHT
#define SAH_POINT_LIGHT

#include <vector>

#include "assets/ShaderLoader.hpp"

class Light {
private:

public:
    Light() {};
    ~Light() {};

    static void createDirectionalLight(glm::vec3 lightDirection, glm::vec3 lightColor);
    static void setAmbientLight(glm::vec3 _ambientLight);

    // load light into shader programs
    static void setUniformLight();
    static void update();


};

#endif
