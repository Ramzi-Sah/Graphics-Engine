#include "Player.hpp"

Player::Player() {
    // instinitiate camera
    m_model = ModelLoader::getModel("player");

    // init camera
    camera = new Camera();

    // update camera movements
    camera->attachToRot(false, yaw, 0.0f);
    camera->attachToPos(m_position, 0.0f);
};
/*------------------ render  --------------*/
void Player::render() {
    if (camera->getCamVew() != 0 || camera->m_camFreeView) { // dont render player model if firstPerson
        m_model.render();
    }
};

/*------------------ logic  --------------*/
glm::vec3 Player::update(float deltaTime) {
    // check if mouse is disabled
    if (!m_mouseEnabled) {
        // check if in free cam mod
        if (!camera->m_camFreeView) {
            float speed_D = speed * deltaTime;
            // update player pos
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

            // update camera movements
            camera->attachToPos(m_position, deltaTime);
        } else {
            // update camera movements
            camera->freeMove(deltaTime);
        }
    }

    // move actual placing object
    if (placingObject) {
        placeObjectMove();
    };

    return m_position;
};

/*------------------ transfrom --------------*/
void Player::setPosition(float _posX, float _posY, float _posZ) {
    m_model.setPosition(glm::vec3(_posX, _posY, _posZ));
};
void Player::setPosition(glm::vec3 _pos) {
    m_model.setPosition(_pos);
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
glm::vec3 Player::getPos() {
    return m_position;
};
/*------------------ handle --------------*/
void Player::keyEventInput(int key, int action) {
    // FIXME: can be optimized
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

    // place object key
    if (key == GLFW_KEY_B && action == GLFW_PRESS) {
        if (!placingObject)
            startPlacingObject(World::createWall(SAH_NULL_VEC3));
        else if (placingObject) {
            // stop placing object
            stopPlacingObject();

            // delete prop from world prop list
            World::deleteProp(m_placableObject);

            // reset prop pointer var member
            m_placableObject = nullptr;
        };
    };

    // rotate object key
    if (key == GLFW_KEY_R && action == GLFW_PRESS) {
        if (placingObject)
            m_placableObject->addRotation(45, glm::vec3(0.0f, 1.0f, 0.0f));
    }

    // handle camera input
    Camera::keyEventInput(key, action);

};

void Player::MouseEventInput(bool mouseEnabled, int xpos, int ypos) {
    // reset member vars
    m_mouseEnabled = mouseEnabled;
    m_mousePosX = xpos;
    m_mousePosY = ypos;

    // for rotation calculations
    float xoffset = lastX - xpos;
    lastX = xpos;

    float yoffset = lastY - ypos;
    lastY = ypos;

    // check if mmouse is enabled
    if (!m_mouseEnabled) {
        // multiply by sensitivity
        xoffset *= sensitivity;
        yoffset *= sensitivity;

        // player add yaw
        yaw += xoffset;

        // player add pitch
        pitch += yoffset;
        if (pitch >= 89.0f)
            pitch = 89.0f;
        if (pitch <= -89.0f)
            pitch = -89.0f;

        // check if is free cam mod
        if (!camera->m_camFreeView) {
            // set rotation
            setRotation(yaw, glm::vec3(0.0f, 1.0f, 0.0f));

            // calculate new front vector
            m_front.x = sin(glm::radians(yaw));
            m_front.z = cos(glm::radians(yaw));

            // set camera front vector
            m_front = glm::normalize(m_front);

            // update camera rotation
            camera->attachToRot(m_mouseEnabled, yaw, pitch);
        } else {
            // update camera free rotation
            camera->freeRot(m_mouseEnabled, yaw, pitch);
        }
    }


}
void Player::MouseClickEventInput(bool mouseEnabled, int button, int action, int mouseXPos, int mouseYPos) {
    // spawn prop on mouse click
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        // if (m_mouseEnabled)
            stopPlacingObject();
    }

};

/*------------------------ physics -------------------------------*/
glm::vec3 Player::castRay() {
    // ray cast
    Ray ray;
    if (m_mouseEnabled)
        ray = camera->rayCast(m_mousePosX, m_mousePosY);
    else
        ray = camera->rayCastMiddleScreen();

    // check ray collision with terrain
    glm::vec3 terrainPos = ray.position;
    for (int i = 0; i < 200; i++) {
        terrainPos += i * 0.001f * ray.direction;

        // chek if colided
        if (terrainPos.y < Bioms::getHight(terrainPos.x, terrainPos.z)) {
            // std::cout << "terrain pos: " << terrainPos.x << " " << terrainPos.y << " " << terrainPos.z << '\n';
            return terrainPos;
        }
    }
    for (int i = 0; i < 200; i ++) {
        terrainPos += i * 0.01f * ray.direction;

        // chek if colided
        if (terrainPos.y < Bioms::getHight(terrainPos.x, terrainPos.z)) {
            // std::cout << "terrain pos: " << terrainPos.x << " " << terrainPos.y << " " << terrainPos.z << '\n';
            return terrainPos;
        }
    }

    // didn't collide with anything
    // std::cout << "can't collide with terrain" << '\n';
    return SAH_NULL_VEC3;
};

glm::vec3 Player::clipToGrid(glm::vec3 position) {
    // clip position to grid
    position.x = std::roundf(position.x / GridSize) * GridSize;
    position.z = std::roundf(position.z / GridSize) * GridSize;

    // calculate y pos
    position.y = Bioms::getHight(position.x, position.z);

    // return clipped pos
    return position;
};

// place object
void Player::startPlacingObject(Props* placebaleProp) {
    // set placing bool to true
    placingObject = true;

    // instinitiate placable object
    m_placableObject = placebaleProp;

    // std::cout << "start placing object" << '\n';
};
void Player::stopPlacingObject() {
    // set placing bool to true
    placingObject = false;

    // std::cout << "place object" << '\n';
};
void Player::placeObjectMove() {
    // get terrainPos
    glm::vec3 rayCollisionPos = castRay();

    // check if colided with terrain
    if (rayCollisionPos != SAH_NULL_VEC3) {
        // spawn an axe
        m_placableObject->setPosition(clipToGrid(rayCollisionPos));

        // std::cout << "move place object to: " << rayCollisionPos.x << rayCollisionPos.y << rayCollisionPos.z << '\n';
    };
}
