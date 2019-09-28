#include "Camera.hpp"

Camera::Camera() {
    // set perspective mat uniform
    setPerspectiveMat(m_windowWidth, m_windowHeight);

    // init to a rotation
    attachToRot(true, m_yaw, m_ypos);

    // set cam transforms
    setTransform();
};

/*------------------------------- projection matrix ---------------------------------------*/
float Camera::FOV = 60.0f;
float Camera::minDistView = 0.1f;
float Camera::maxDistView = 1000.0f;

unsigned int Camera::m_windowWidth, Camera::m_windowHeight;
glm::mat4 Camera::m_projection;

void Camera::setPerspectiveMat(unsigned int _windowWidth, unsigned int _windowHeight) {
    // reset window size
    m_windowWidth = _windowWidth;
    m_windowHeight = _windowHeight;

    // calculate resolution
    float resolution = (float)m_windowWidth / (float)m_windowHeight;

    // set perspective matrix
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

void Camera::freeMove(float deltaTime) {
    // reCheck is free cam enabled
    if (m_camFreeView) {

        // calculate speed
        float speed_D = speed * deltaTime;

        // update player pos
        if (goUp_Key)
            cameraPos -= cameraFront * speed_D;
        if (goDown_Key)
            cameraPos += cameraFront * speed_D;
        if (goLeft_Key)
            cameraPos -= glm::normalize(glm::cross(cameraUp, cameraFront)) * speed_D;
        if (goRight_Key)
            cameraPos += glm::normalize(glm::cross(cameraUp, cameraFront)) * speed_D;

        // update camera target
        cameraTarget = cameraPos - cameraFront;

        // std::cout << "cameraTarget: " << cameraTarget.x << " " << cameraTarget.y << " " << cameraTarget.z << '\n';
    };

    // set cam transforms
    setTransform();
};

void Camera::freeRot(bool mouseEnabled, float yaw, float pitch) {
    // set rot
    m_yaw = -yaw;
    m_pitch = -pitch;

    // convert îtch & yaw to pos
    glm::vec3 front;

    front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    front.y = sin(glm::radians(m_pitch));
    front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));

    cameraFront = glm::normalize(front);
};

void Camera::attachToPos(glm::vec3 _position, float deltaTime) {
    // reCheck is free cam disabled
    if (!m_camFreeView) {
        // switch cam view state
        switch (camView) {
            case firstPerson:
                // calculate camera pos
                cameraPos = _position + cameraTargetOffset;

                // calculate camera target
                cameraTarget = _position - cameraOffset;

                // add pitch to camera target
                cameraTarget.y += cameraRadius * glm::radians(m_pitch) + 10; // add 10 degrees

                cameraFront = +glm::normalize(cameraTarget);

                break;

            case thirdPerson:
                // calculate camera pos
                cameraPos = _position + cameraOffset;

                // calculate camera target
                cameraTarget = _position + cameraTargetOffset;

                // add pitch to camera target
                cameraPos.y -= cameraRadius * sin(glm::radians(m_pitch));

                cameraFront = glm::normalize(cameraPos);

                break;
            default:
                // not suposed to hapen
                std::cout << "ERROR: camView not defined" << std::endl;
                break;
        }
    }

    // set cam transforms
    setTransform();
};

void Camera::attachToRot(bool mouseEnabled, float yaw, float pitch) {
    // set rot
    m_yaw = yaw;
    m_pitch = pitch;

    // convert pitch to pos
    cameraOffset.x = cameraRadius * sin(glm::radians(m_yaw));
    cameraOffset.z = cameraRadius * cos(glm::radians(m_yaw));
};

glm::vec3 Camera::getPos() {
    return cameraPos;
};

int Camera::camView = firstPerson;
void Camera::basculateView() {
    camView++;
    if (camView >= 2) {
        camView = 0;
    }
};
int Camera::getCamVew() {
    return Camera::camView;
};
/*--------------------- physics -------------------------*/
Ray Camera::rayCast(unsigned int screen_x, unsigned int screen_y) {
    // ray cast theory <3 http://antongerdelan.net/opengl/raycasting.html

    // convert to openGL normalized coordinate system
    float x = 2.0f * screen_x / m_windowWidth - 1.0f;
    float y = 1.0f - 2.0f * screen_y / m_windowHeight ;

    // vec4 front direction vector
    glm::vec4 ray_clip = glm::vec4(x, y, -1.0f, 1.0f);

    // clip to view coordinate
    glm::vec4 ray_eye = glm::inverse(m_projection) * ray_clip;
    ray_eye = glm::vec4(ray_eye.x, ray_eye.y, -1.0, 0.0);

    // view to world coordinate
    glm::vec4 ray_wor = glm::inverse(m_view) * ray_eye;

    // ray direction
    glm::vec3 rayDir = glm::normalize(glm::vec3(ray_wor.x, ray_wor.y, ray_wor.z));

    Ray ray(rayDir, cameraPos);

    return ray;
};
Ray Camera::rayCastMiddleScreen() {
    return rayCast(m_windowWidth/2, m_windowHeight/2);
}

/*-------------------------------------------------------*/
bool Camera::m_camFreeView = false;
void Camera::handleGUI_freeCam_button(bool _camFreeView) {
    m_camFreeView = _camFreeView;
}

/*----------------------- handle --------------------------------*/
bool Camera::goUp_Key = false;
bool Camera::goDown_Key = false;
bool Camera::goLeft_Key = false;
bool Camera::goRight_Key = false;
void Camera::keyEventInput(int key, int action) {
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
