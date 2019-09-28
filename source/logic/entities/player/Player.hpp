#ifndef SAH_PLAYER
#define SAH_PLAYER

#include "../../../common/Vectors.hpp"
#include "../../../engine/Model.hpp"
#include "../../../engine/Camera.hpp"
#include "../../../engine/assets/AssetLoader.hpp"
#include "../world/World.hpp"

#define SAH_NULL_VEC3 glm::vec3(-9999.0f, -9999.0f, -9999.0f)

class Player {
private:
    // player attribs
    Model m_model;
    glm::vec3 m_position = glm::vec3(2000.0f, 0.0f, 2500.0f);
    glm::vec3 m_front = glm::vec3(0.0f, 0.0f, 1.0f);
    float yaw = 0.0f; // rotation
    float pitch = 0.0f; // for cam pitch rotation
    float lastX = 0.0f; // for mouse rotation
    float lastY = 0.0f; // for cam pitch  rotation
    Camera* camera; // camera player

    // player params
    float sensitivity = 0.05f; // rotation sensitivity
    float speed = 50.0f;

    // key handling
    bool goUp_Key = false;
    bool goDown_Key = false;
    bool goLeft_Key = false;
    bool goRight_Key = false;

    // placing objects
    bool placingObject = false;
    Props* m_placableObject = nullptr;
    bool m_mouseEnabled = false;
    int m_mousePosX = 0, m_mousePosY = 0;

    // physics
    glm::vec3 castRay();
    void startPlacingObject(Props* placebaleProp);
    void stopPlacingObject();
    void placeObjectMove();
    glm::vec3 clipToGrid(glm::vec3 position);

public:
    Player();
    ~Player() {};

    void render();
    glm::vec3 update(float deltaTime);

    // handle
    void keyEventInput(int key, int action); // handle keyboard input
    void MouseEventInput(bool mouseEnabled, int xpos, int ypos); // handle mouse move input
    void MouseClickEventInput(bool mouseEnabled, int button, int action, int mouseXPos, int mouseYPos); // handle mouse click input

    // transform
    void setPosition(float _posX, float _posY, float _posZ);
    void setPosition(glm::vec3 _pos);
    void setScale(float _scaleX, float _scaleY, float _scaleZ);
    void setRotation(float _rotDeg, glm::vec3 axes);

    float getYaw();
    glm::vec3 getPos();

};

#endif
