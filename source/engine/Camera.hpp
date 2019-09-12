#ifndef SAH_CAMERA
#define SAH_CAMERA

#include <map>
#include <math.h>

#include "../common/Vectors.hpp"
#include "assets/ShaderLoader.hpp"

class Camera {
private:
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f,  0.0f);

    float cameraRadius = 10.0f;
    float cameraHight = 3.5f;
    glm::vec3 cameraOffset = glm::vec3(0.0f, cameraRadius, -cameraRadius);
    glm::vec3 cameraPos = cameraOffset;
    float m_yaw = 0.0f;
    float m_ypos = 0.0f;

    glm::vec3 cameraTargetOffset = glm::vec3(0.0f, 3.5f,  0.0f);
    glm::vec3 cameraTarget = cameraTargetOffset;
    glm::vec3 cameraFront = glm::vec3(1.0f, 0.0f, 0.0f);
    float terrainHeight = 0.0f;

    float lastY = 0.0f; // mouse pos
    float pitch = 0.0f; // rotation
    float sensitivity = 0.05f; // rotation sensitivity

    // for projection matrix
    static float FOV;
    static float minDistView;
    static float maxDistView;

    // for view matrix
    glm::mat4 m_view = glm::mat4(1.0f);

    // cam view
    enum SAH_CAMVIEW {
        firstPerson,
        thirdPerson,
        freeCam
    };

public:
    Camera();
    ~Camera() {};

    // for projection matrix
    static float m_resolution;
    static glm::mat4 m_projection;
    static void setPerspectiveMat(float resolution);

    // for view matrix transformation
    void setUniformTransform();
    void setTransform();

    void setPos(glm::vec3 _position);
    void attachToPos(glm::vec3 _position, float deltaTime);
    void attachToRot(bool mouseDisabled, float yaw, double ypos);
    glm::vec3 getPos();

    // basculate views
    static int camView;
    static void basculateView();
    static int getCamVew();


};

#endif
