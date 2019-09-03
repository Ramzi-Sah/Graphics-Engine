#include "Player.hpp"

Player::Player() {
    m_model = ModelLoader::getModel("player");
};

void Player::render() {
    m_model.render();
};

glm::vec3 Player::update(GLFWwindow* window, float deltaTime, bool mouseDisabled, double xpos) {
    // for rotation calculations
    float yoffset = lastY - xpos;
    lastY = xpos;

    if (!mouseDisabled) {
        yoffset *= sensitivity * deltaTime;

        yaw += yoffset;

        // set rotation
        setRotation(yaw, glm::vec3(0.0f, 1.0f, 0.0f));

        // calculate new front vector
        m_front.x = sin(glm::radians(yaw));
        m_front.z = cos(glm::radians(yaw));

        // set camera front vector
        m_front = glm::normalize(m_front);

        // calculate position
        float speed_D = speed * deltaTime;
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            m_position -= speed_D * m_front;
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            m_position += speed_D * m_front;
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            m_position += speed_D * glm::cross(m_front, glm::vec3(0.0f, 1.0f, 0.0f));
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            m_position -= speed_D * glm::cross(m_front, glm::vec3(0.0f, 1.0f, 0.0f));

        m_position.y = Bioms::getHight(m_position.x, m_position.z);
        setPosition(m_position.x, m_position.y, m_position.z);
    }

    return m_position;
};

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
