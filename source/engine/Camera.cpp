#include "Camera.hpp"

Camera::Camera(float width, float height) {
    // set perspective mat uniform
    Camera::setPerspectiveMat((float)width/(float)height);

    // set view mat uniform
    setUniformTransform();

    // for rotation
    lastX = width/2;
    lastY = height/2;
};

/*------------------------------- projection matrix ---------------------------------------*/
float Camera::FOV = 45.0f;
float Camera::minDistView = 0.1f;
float Camera::maxDistView = 100.0f;

glm::mat4 Camera::m_projection;

void Camera::setPerspectiveMat(float resolution) {
    m_projection = glm::perspective((float)glm::radians(FOV), resolution, minDistView, maxDistView);

    // set all shader program's projection uniform
    for (auto it = ShaderLoader::shaderPrograms.cbegin(); it != ShaderLoader::shaderPrograms.cend(); ++it) {
        glUseProgram(it->second);
        unsigned int projectionMatLoc = glGetUniformLocation(it->second, "projection");
        glUniformMatrix4fv(projectionMatLoc, 1, GL_FALSE, glm::value_ptr(Camera::m_projection));
    }
};

/*------------------------------- view matrix ---------------------------------------*/
void Camera::setUniformTransform() {
    // set all shader program's view uniform
    for (auto it = ShaderLoader::shaderPrograms.cbegin(); it != ShaderLoader::shaderPrograms.cend(); ++it) {
        glUseProgram(it->second);
        unsigned int viewMatLoc = glGetUniformLocation(ShaderLoader::getShader("Default"), "view");
        glUniformMatrix4fv(viewMatLoc, 1, GL_FALSE, glm::value_ptr(m_view));
    }
}

void Camera::setTransform() {
    m_view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

    // set transform uniform for shader
    setUniformTransform();
}

/*----------------------------------------------------------------------------------*/
void Camera::processInput(GLFWwindow* window, float deltaTime, bool mouseDisabled, double xpos, double ypos) {
    // for rotation calculations
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;

    if (!mouseDisabled) {
        xoffset *= sensitivity * deltaTime;
        yoffset *= sensitivity * deltaTime;

        yaw += xoffset;
        pitch += yoffset;

        // block cazmera on too height pitch
        if(pitch > 89.0f)
            pitch = 89.0f;
        if(pitch < -89.0f)
            pitch = -89.0f;

        // calculate new front vector
        glm::vec3 front;
        front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        front.y = sin(glm::radians(pitch));
        front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

        // set camera front vector
        cameraFront = glm::normalize(front);
    }

    // for movement calculations
    float cameraSpeed = cameraSpd * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPos += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;

    // set cam transforms
    setTransform();
}
