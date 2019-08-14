#include "GameModels.hpp"

std::vector<Model*> GameModels::models;

/*----------------------- model prefabs -------------------------------*/
Model* GameModels::createTriangle(float posX, float posY, glm::vec4 color) {
    // instinitiate Model object
    Model* model = new Model();

    // set vertecies
    model->addVertex(
        glm::vec3(0.2f, -0.2f, 0.0f),
        color,
        glm::vec2(1.0f, 0.0f)
    );
    model->addVertex(
        glm::vec3(-0.2f, -0.2f, 0.0f),
        color,
        glm::vec2(0.0f, 0.0f)
    );
    model->addVertex(
        glm::vec3(0.2f, 0.2f, 0.0f),
        color,
        glm::vec2(1.0f, 1.0f)
    );

    // load Vertex Buffer Object
    model->loadVertices();

    // set Element Buffer Object
    unsigned int indeces[] = {0, 1, 2};
    model->setIndecies(indeces, 3);

    // set pos
    model->setTransform(glm::vec3(posX, posY, -3.0f), glm::vec3(1.0f, 1.0f, 1.0f));

    // add the model to models list
    models.push_back(model);

    return model;
}

Model* GameModels::createSquare(float posX, float posY, glm::vec4 color) {
    // instinitiate Model object
    Model* model = new Model();

    // set vertecies
    model->addVertex(
        glm::vec3(0.2f, -0.2f, 0.0f),
        color,
        glm::vec2(1.0f, 0.0f)
    );
    model->addVertex(
        glm::vec3(-0.2f, -0.2f, 0.0f),
        color,
        glm::vec2(0.0f, 0.0f)
    );
    model->addVertex(
        glm::vec3(0.2f, 0.2f, 0.0f),
        color,
        glm::vec2(1.0f, 1.0f)
    );
    model->addVertex(
        glm::vec3(-0.2f, 0.2f, 0.0f),
        color,
        glm::vec2(0.0f, 1.0f)
    );

    // load Vertex Buffer Object
    model->loadVertices();

    // set Element Buffer Object
    unsigned int indeces[] = {0, 1, 2, 1, 3, 2};
    model->setIndecies(indeces, 6);

    // set pos
    model->setTransform(glm::vec3(posX, posY, -3.0f), glm::vec3(1.0f, 1.0f, 1.0f));

    // add the model to models list
    models.push_back(model);

    return model;
}

Model* GameModels::createCube(float posX, float posY, float posZ, glm::vec4 color) {
    // instinitiate Model object
    Model* model = new Model();

    // set vertecies
    model->addVertex(
        glm::vec3(0.2f, -0.2f, 0.2f),
        color,
        glm::vec2(1.0f, 0.0f)
    );
    model->addVertex(
        glm::vec3(-0.2f, -0.2f, 0.2f),
        color,
        glm::vec2(0.0f, 0.0f)
    );
    model->addVertex(
        glm::vec3(-0.2f, 0.2f, 0.2f),
        color,
        glm::vec2(0.0f, 1.0f)
    );
    model->addVertex(
        glm::vec3(0.2f, 0.2f, 0.2f),
        color,
        glm::vec2(1.0f, 1.0f)
    );

    model->addVertex(
        glm::vec3(0.2f, -0.2f, -0.2f),
        color,
        glm::vec2(1.0f, 0.0f)
    );
    model->addVertex(
        glm::vec3(-0.2f, -0.2f, -0.2f),
        color,
        glm::vec2(0.0f, 0.0f)
    );
    model->addVertex(
        glm::vec3(-0.2f, 0.2f, -0.2f),
        color,
        glm::vec2(0.0f, 1.0f)
    );
    model->addVertex(
        glm::vec3(0.2f, 0.2f, -0.2f),
        color,
        glm::vec2(1.0f, 1.0f)
    );

    // load Vertex Buffer Object
    model->loadVertices();

    // set Element Buffer Object
    unsigned int indeces[] = {
        0, 1, 2,
        0, 2, 3,

        4, 5, 6,
        4, 6, 7,

        4, 0, 3,
        4, 3, 7,

        5, 1, 2,
        5, 2, 6,

        3, 2, 6,
        3, 6, 7,

        0, 1, 5,
        0, 5, 4
    };
    model->setIndecies(indeces, 36);

    // set pos
    model->setTransform(glm::vec3(posX, posY, posZ), glm::vec3(1.0f, 1.0f, 1.0f));

    // add the model to models list
    models.push_back(model);

    return model;
}
