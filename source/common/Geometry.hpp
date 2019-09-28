#ifndef SAH_GEOMETRY
#define SAH_GEOMETRY

#include <math.h>
#include "Vectors.hpp"

namespace Geometry {
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

    // bicubic interpolation theory https://www.paulinternet.nl/?page=bicubic
    static float cubicInterpolate(float p[4], float x) {
	    return p[1] + 0.5 * x*(p[2] - p[0] + x*(2.0*p[0] - 5.0*p[1] + 4.0*p[2] - p[3] + x*(3.0*(p[1] - p[2]) + p[3] - p[0])));
    };
    static float bicubicInterpolate(float p[4][4], float x, float y) {
    	static float arr[4];

    	arr[0] = cubicInterpolate(p[0], y);
    	arr[1] = cubicInterpolate(p[1], y);
    	arr[2] = cubicInterpolate(p[2], y);
    	arr[3] = cubicInterpolate(p[3], y);

    	return cubicInterpolate(arr, x);
    };

}

#endif
