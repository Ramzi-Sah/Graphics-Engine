#ifndef SAH_GEOMETRY
#define SAH_GEOMETRY

#include <math.h>

#include "Vectors.hpp"

static glm::vec3 degToPos(float pitch, float yaw, float radius) {
    float x, y, z;

    x = radius * cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    y = radius * sin(glm::radians(pitch));
    z = radius * sin(glm::radians(yaw)) * cos(glm::radians(pitch));

    return glm::vec3(x, y, z);
};

static glm::vec3 posToDeg(float x, float y, float z) {
    float pitch, yaw, radius;

    radius = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    pitch = atan(y / x);
    yaw = acos(z / radius);

    return glm::vec3(pitch, yaw, radius);
};

#endif
