#include "Player.hpp"

Player::Player() {
    // instinitiate camera
    m_model = ModelLoader::getModel("player");

    // init camera
    camera = new Camera();
};
/*------------------ render  --------------*/
void Player::render() {
    if (camera->getCamVew() != 0) { // 0 is firstPerson
        m_model.render();
    }
};

/*------------------ logic  --------------*/
glm::vec3 Player::update(float deltaTime) {
    // calculate position
    float speed_D = speed * deltaTime;
    if (goUp_Key)
        m_position -= speed_D * m_front;
    if (goDown_Key)
        m_position += speed_D * m_front;
    if (goLeft_Key)
        m_position += speed_D * glm::cross(m_front, glm::vec3(0.0f, 1.0f, 0.0f));
    if (goRight_Key)
        m_position -= speed_D * glm::cross(m_front, glm::vec3(0.0f, 1.0f, 0.0f));

    m_position.y = Bioms::getHight(m_position.x, m_position.z);
    setPosition(m_position.x, m_position.y, m_position.z);


    // update camera position
    camera->attachToPos(m_position, deltaTime);

    return m_position;
};

/*------------------ handle --------------*/
void Player::keyEventInput(int key, int action) {
    // handle movements keys
    if (!goUp_Key && key == GLFW_KEY_W && action == GLFW_PRESS) {
        goUp_Key = true;
    }
    if (goUp_Key && key == GLFW_KEY_W && action == GLFW_RELEASE) {
        goUp_Key = false;
    }

    if (!goDown_Key && key == GLFW_KEY_S && action == GLFW_PRESS) {
        goDown_Key = true;
    }
    if (goDown_Key && key == GLFW_KEY_S && action == GLFW_RELEASE) {
        goDown_Key = false;
    }

    if (!goLeft_Key && key == GLFW_KEY_A && action == GLFW_PRESS) {
        goLeft_Key = true;
    }
    if (goLeft_Key && key == GLFW_KEY_A && action == GLFW_RELEASE) {
        goLeft_Key = false;
    }

    if (!goRight_Key && key == GLFW_KEY_D && action == GLFW_PRESS) {
        goRight_Key = true;
    }
    if (goRight_Key && key == GLFW_KEY_D && action == GLFW_RELEASE) {
        goRight_Key = false;
    }

};

void Player::MouseEventInput(bool mouseDisabled, double xpos, double ypos) {
    // for rotation calculations
    float xoffset = lastX - xpos;
    lastX = xpos;

    if (!mouseDisabled) {
        xoffset *= sensitivity;

        yaw += xoffset;

        // set rotation
        setRotation(yaw, glm::vec3(0.0f, 1.0f, 0.0f));

        // calculate new front vector
        m_front.x = sin(glm::radians(yaw));
        m_front.z = cos(glm::radians(yaw));

        // set camera front vector
        m_front = glm::normalize(m_front);
    }

    // update camera rotation
    camera->attachToRot(mouseDisabled, yaw, ypos);
}
/*------------------ transfrom --------------*/
void Player::setPosition(float _posX, float _posY, float _posZ) {
    m_model.setPosition(glm::vec3(_posX, _posY, _posZ));
};

void Player::setScale(float _scaleX, float _scaleY, float _scaleZ) {
    m_model.setScale(glm::vec3(_scaleX, _scaleY, _scaleZ));
};

void Player::setRotation(float _rotDeg, glm::vec3 axes) {
    m_model.setRotation(_rotDeg, axes);
};

float Player::getYaw() {
    return yaw;
};
