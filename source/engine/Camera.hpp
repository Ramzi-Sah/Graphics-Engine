#ifndef SAH_CAMERA
#define SAH_CAMERA

#include <map>
#include <math.h>

#include "assets/ShaderLoader.hpp"
#include "../common/Vectors.hpp"
#include "../common/Ray.hpp"

class Camera {
private:
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f,  0.0f);

    float cameraRadius = 10.0f;
    glm::vec3 cameraOffset = glm::vec3(0.0f, cameraRadius, -cameraRadius);
    glm::vec3 cameraPos = cameraOffset;
    float m_ypos = 0.0f;

    glm::vec3 cameraTargetOffset = glm::vec3(0.0f, 3.5f,  0.0f);
    glm::vec3 cameraTarget = cameraTargetOffset;
    glm::vec3 cameraFront = glm::vec3(1.0f, 0.0f, 0.0f);
    float terrainHeight = 0.0f;

    float lastY = 0.0f; // mouse pos
    float m_pitch = 0.0f; // pitch rotation
    float m_yaw = 0.0f;  // yaw rotation

    float sensitivity = 0.05f; // rotation sensitivity
    float speed = 40.0f; // camera speed

    // for projection matrix
    static float FOV;
    static float minDistView;
    static float maxDistView;

    // key handling
    static bool goUp_Key;
    static bool goDown_Key;
    static bool goLeft_Key;
    static bool goRight_Key;

    // for view matrix
    glm::mat4 m_view = glm::mat4(1.0f);

    // cam view
    enum SAH_CAMVIEW {
        firstPerson,
        thirdPerson
    };

public:
    Camera();
    ~Camera() {};

    // for projection matrix
    // static float m_resolution;
    static unsigned int m_windowWidth, m_windowHeight;
    static glm::mat4 m_projection;
    static void setPerspectiveMat(unsigned int _windowWidth, unsigned int _windowHeight);

    // for view matrix transformation
    void setUniformTransform();
    void setTransform();

    void setPos(glm::vec3 _position);
    glm::vec3 getPos();

    void attachToPos(glm::vec3 _position, float deltaTime);
    void attachToRot(bool mouseEnabled, float yaw, float pitch);

    static bool m_camFreeView;
    void freeMove(float deltaTime);
    void freeRot(bool mouseEnabled, float yaw, float pitch);


    // basculate views
    static int camView;
    static void basculateView();
    static int getCamVew();

    // physics
    Ray rayCast(unsigned int screen_x, unsigned int screen_y);
    Ray rayCastMiddleScreen();

    // gui
    static void handleGUI_freeCam_button(bool _camFreeView);

    // handle
    static void keyEventInput(int key, int action);


};

#endif
