#ifndef SAH_PLAYER
#define SAH_PLAYER

#include "../../../common/Vectors.hpp"
#include "../../../engine/Model.hpp"
#include "../../../engine/Camera.hpp"
#include "../../../engine/assets/AssetLoader.hpp"
#include "../world/World.hpp"

class Player {
private:
    // player attribs
    Model m_model;
    glm::vec3 m_position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 m_front = glm::vec3(0.0f, 0.0f, 1.0f);
    float yaw = 0.0f; // rotation
    float lastX = 0.0f; // for mouse rotation
    Camera* camera; // camera player

    // player params
    float sensitivity = 0.05f; // rotation sensitivity
    float speed = 10.0f;

    // key handling
    bool goUp_Key = false;
    bool goDown_Key = false;
    bool goLeft_Key = false;
    bool goRight_Key = false;

public:
    Player();
    ~Player() {};

    void render();
    glm::vec3 update(float deltaTime);
    void keyEventInput(int key, int action);
    void MouseEventInput(bool mouseDisabled, double xpos, double ypos);

    // transform
    void setPosition(float _posX, float _posY, float _posZ);
    void setScale(float _scaleX, float _scaleY, float _scaleZ);
    void setRotation(float _rotDeg, glm::vec3 axes);

    float getYaw();
};

#endif
