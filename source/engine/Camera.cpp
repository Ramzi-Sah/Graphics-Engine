#include "Camera.hpp"

Camera::Camera(float width, float height) {
    // set perspective mat uniform
    Camera::setPerspectiveMat((float)width/(float)height);

    // set cam transforms
    setTransform();

    // set view mat uniform
    setUniformTransform();
};

/*------------------------------- projection matrix ---------------------------------------*/
float Camera::FOV = 60.0f;
float Camera::minDistView = 0.1f;
float Camera::maxDistView = 300.0f;

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
    m_view = glm::lookAt(cameraPos, cameraTarget, cameraUp); // position, target and up

    // set transform uniform for shader
    setUniformTransform();
}

void Camera::setPos(glm::vec3 _position) {
    cameraPos = _position;

    // set cam transforms
    setTransform();
};

void Camera::attach(glm::vec3 _position, float deltaTime, float yaw, bool mouseDisabled, double ypos) {
    // for rotation calculations
    float xoffset = lastX - ypos;
    lastX = ypos;

    // check for mouse state
    if (!mouseDisabled) {
        xoffset *= sensitivity * deltaTime;

        pitch += xoffset;

        if (pitch >= 89.0f)
            pitch = 89.0f;
        if (pitch <= -89.0f)
            pitch = -89.0f;
    }

    // switch cam view state
    switch (camView) {
        case firstPerson:
            // convert yaw to pos
            cameraOffset.x = cameraRadius * sin(glm::radians(yaw));
            cameraOffset.z = cameraRadius * cos(glm::radians(yaw));

            // calculate camera pos
            cameraPos = _position;
            cameraPos.y += cameraHight;

            // calculate front vector
            cameraFront = -glm::normalize(glm::cross(cameraUp, glm::normalize(cameraPos)) + cameraOffset);

            // calculatre camera target
            cameraTarget = cameraPos + cameraFront;

            // set cameraPos.y pitch
            cameraTarget.y += sin(glm::radians(pitch));

            break;

        case thirdPerson:
            // convert yaw to pos
            cameraOffset.x = cameraRadius * sin(glm::radians(yaw));
            cameraOffset.z = cameraRadius * cos(glm::radians(yaw));

            cameraPos = _position + cameraOffset;
            cameraTarget = _position + cameraTargetOffset;

            // set cameraPos.y pitch
            cameraPos.y -= cameraRadius * sin(glm::radians(pitch));

            break;

        case freeCam:

            break;

        default:
            // not suposed to hapen
            std::cout << "ERROR: camView not defined" << std::endl;
            break;
    }

    // set cam transforms
    setTransform();
};

glm::vec3 Camera::getPos() {
    return cameraPos;
};

int Camera::camView = firstPerson;
void Camera::basculateView() {
    camView++;
    if (camView >= 3) {
        camView = 0;
    }
};
