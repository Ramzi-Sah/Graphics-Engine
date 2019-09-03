#ifndef SAH_PLAYER
#define SAH_PLAYER

#include "../common/Vectors.hpp"
#include "../engine/Model.hpp"
#include "../engine/assets/AssetLoader.hpp"
#include "world/World.hpp"

class Player {
private:
    Model m_model;
    glm::vec3 m_position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 m_front = glm::vec3(0.0f, 0.0f, 1.0f);
    float yaw = 0.0f; // rotation
    float lastY = 0.0f; // for mouse rotation

    float sensitivity = 3.0f; // rotation sensitivity
    float speed = 10.0f;

public:
    Player();
    ~Player() {};

    void render();
    glm::vec3 update(GLFWwindow* window, float deltaTime, bool mouseDisabled, double xpos);

    // transform
    void setPosition(float _posX, float _posY, float _posZ);
    void setScale(float _scaleX, float _scaleY, float _scaleZ);
    void setRotation(float _rotDeg, glm::vec3 axes);

    float getYaw();
};

#endif
