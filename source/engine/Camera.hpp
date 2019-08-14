#ifndef SAH_CAMERA
#define SAH_CAMERA

#include <map>

#include "../common/Vectors.hpp"
#include "assets/ShaderLoader.hpp"

class Camera {
private:
    // for movements
    float cameraSpd = 2.5f;
    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f,  3.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f,  0.0f);

    // for rotations (pitch/yaw/roll)
    float sensitivity = 3.0f;

    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    float yaw = -90.0f;
    float pitch =  0.0f;
    float lastX;
    float lastY;

    // for projection matrix
    static float FOV;
    static float minDistView;
    static float maxDistView;

    // for view matrix
    glm::mat4 m_view = glm::mat4(1.0f);

public:
    Camera(float width, float height);
    ~Camera() {};

    // for projection matrix
    static glm::mat4 m_projection;
    static void setPerspectiveMat(float resolution);

    // for view matrix transformation
    void setUniformTransform();
    void setTransform();

    // for input
    void processInput(GLFWwindow* window, float deltaTime, bool mouseDisabled, double xpos, double ypos);

};

#endif
