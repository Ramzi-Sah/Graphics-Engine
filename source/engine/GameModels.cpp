#include "GameModels.hpp"

std::vector<Model*> GameModels::models;

/*----------------------- model prefabs -------------------------------*/
Model* GameModels::createCube(float posX, float posY, float posZ, glm::vec4 color) {
    // instinitiate Model object
    Model* model = new Model();

    // set vertecies
    model->addVertex(
        glm::vec3(0.2f, -0.2f, 0.2f),
        glm::vec2(1.0f, 0.0f),
        glm::vec3(0.0f, 0.0f, 1.0f)
    );
    model->addVertex(
        glm::vec3(-0.2f, -0.2f, 0.2f),
        glm::vec2(0.0f, 0.0f),
        glm::vec3(0.0f, 0.0f, 1.0f)
    );
    model->addVertex(
        glm::vec3(-0.2f, 0.2f, 0.2f),
        glm::vec2(0.0f, 1.0f),
        glm::vec3(0.0f, 0.0f, 1.0f)
    );
    model->addVertex(
        glm::vec3(0.2f, 0.2f, 0.2f),
        glm::vec2(1.0f, 1.0f),
        glm::vec3(0.0f, 0.0f, 1.0f)
    );

    model->addVertex(
        glm::vec3(-0.2f, -0.2f, -0.2f),
        glm::vec2(0.0f, 0.0f),
        glm::vec3(0.0f, 0.0f, -1.0f)
    );
    model->addVertex(
        glm::vec3(0.2f, -0.2f, -0.2f),
        glm::vec2(1.0f, 0.0f),
        glm::vec3(0.0f, 0.0f, -1.0f)
    );
    model->addVertex(
        glm::vec3(0.2f, 0.2f, -0.2f),
        glm::vec2(1.0f, 1.0f),
        glm::vec3(0.0f, 0.0f, -1.0f)
    );
    model->addVertex(
        glm::vec3(-0.2f, 0.2f, -0.2f),
        glm::vec2(0.0f, 1.0f),
        glm::vec3(0.0f, 0.0f, -1.0f)
    );

    model->addVertex(
        glm::vec3(0.2f, -0.2f, -0.2f),
        glm::vec2(1.0f, 0.0f),
        glm::vec3(1.0f, 0.0f, 0.0f)
    );
    model->addVertex(
        glm::vec3(0.2f, -0.2f, 0.2f),
        glm::vec2(0.0f, 0.0f),
        glm::vec3(1.0f, 0.0f, 0.0f)
    );
    model->addVertex(
        glm::vec3(0.2f, 0.2f, 0.2f),
        glm::vec2(0.0f, 1.0f),
        glm::vec3(1.0f, 0.0f, 0.0f)
    );
    model->addVertex(
        glm::vec3(0.2f, 0.2f, -0.2f),
        glm::vec2(1.0f, 1.0f),
        glm::vec3(1.0f, 0.0f, 0.0f)
    );

    model->addVertex(
        glm::vec3(-0.2f, -0.2f, 0.2f),
        glm::vec2(0.0f, 0.0f),
        glm::vec3(-1.0f, 0.0f, 0.0f)
    );
    model->addVertex(
        glm::vec3(-0.2f, -0.2f, -0.2f),
        glm::vec2(1.0f, 0.0f),
        glm::vec3(-1.0f, 0.0f, 0.0f)
    );
    model->addVertex(
        glm::vec3(-0.2f, 0.2f, -0.2f),
        glm::vec2(1.0f, 1.0f),
        glm::vec3(-1.0f, 0.0f, 0.0f)
    );
    model->addVertex(
        glm::vec3(-0.2f, 0.2f, 0.2f),
        glm::vec2(0.0f, 1.0f),
        glm::vec3(-1.0f, 0.0f, 0.0f)
    );


    model->addVertex(
        glm::vec3(0.2f, 0.2f, 0.2f),
        glm::vec2(1.0f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f)
    );
    model->addVertex(
        glm::vec3(-0.2f, 0.2f, 0.2f),
        glm::vec2(0.0f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f)
    );
    model->addVertex(
        glm::vec3(-0.2f, 0.2f, -0.2f),
        glm::vec2(0.0f, 1.0f),
        glm::vec3(0.0f, 1.0f, 0.0f)
    );
    model->addVertex(
        glm::vec3(0.2f, 0.2f, -0.2f),
        glm::vec2(1.0f, 1.0f),
        glm::vec3(0.0f, 1.0f, 0.0f)
    );

    model->addVertex(
        glm::vec3(-0.2f, -0.2f, 0.2f),
        glm::vec2(0.0f, 0.0f),
        glm::vec3(0.0f, -1.0f, 0.0f)
    );
    model->addVertex(
        glm::vec3(0.2f, -0.2f, 0.2f),
        glm::vec2(1.0f, 0.0f),
        glm::vec3(0.0f, -1.0f, 0.0f)
    );
    model->addVertex(
        glm::vec3(0.2f, -0.2f, -0.2f),
        glm::vec2(1.0f, 1.0f),
        glm::vec3(0.0f, -1.0f, 0.0f)
    );
    model->addVertex(
        glm::vec3(-0.2f, -0.2f, -0.2f),
        glm::vec2(0.0f, 1.0f),
        glm::vec3(0.0f, -1.0f, 0.0f)
    );

    // set Element Buffer Object
    unsigned int indeces[] = {
        0, 1, 2,
        0, 2, 3,

        4, 5, 6,
        4, 6, 7,

        8, 9, 10,
        8, 10, 11,

        12, 13, 14,
        12, 14, 15,

        16, 17, 18,
        16, 18, 19,

        20, 21, 22,
        20, 22, 23
    };

    // load Vertex Buffer Object
    model->loadVertices(indeces, 36, Material());

    // set pos
    model->setTransform(glm::vec3(posX, posY, posZ), glm::vec3(1.0f, 1.0f, 1.0f));

    // set color
    model->setDefuse(color);

    // add the model to models list
    models.push_back(model);

    return model;
}
