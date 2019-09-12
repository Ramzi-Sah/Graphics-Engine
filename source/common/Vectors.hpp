#ifndef SAH_VECTORS
#define SAH_VECTORS

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct Vector2 {
    float x, y;

    Vector2() {};
    Vector2(float _x, float _y) {
        x = _x;
        y = _y;
    };
};

struct Vector3 {
    float x, y, z;

    Vector3() {};
    Vector3(float _x, float _y, float _z) {
        x = _x;
        y = _y;
        z = _z;
    };
};

struct Vector4 {
    float x, y, z, w;

    Vector4() {};
    Vector4(float _x, float _y, float _z, float _w) {
        x = _x;
        y = _y;
        z = _z;
        w = _w;
    };
};

#endif
