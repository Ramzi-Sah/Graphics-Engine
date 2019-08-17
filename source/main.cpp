#include <iostream>
#include <math.h>
#include <random>

#define STB_IMAGE_IMPLEMENTATION

#include "engine/Display.hpp"
#include "engine/assets/AssetLoader.hpp"
#include "engine/assets/ModelLoader.hpp"
#include "engine/GameModels.hpp"
#include "engine/Model.hpp"
#include "engine/Camera.hpp"
#include "engine/Light.hpp"

#include "entities/world/Terrain.hpp"

static const int width = 1280;
static const int height = 720;

float deltaTime = 0.0f;	// Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame

int main(int argc, char** argv) {
    // init glfw
    if (!glfwInit()) {
        std::cout << "ERROR: glfw init failed." << std::endl;
        return 1;
    }

    // setting some glfw attribs
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // start display
    Display display("SAH Game", width, height);

    // import assets
    AssetLoader::createShaderPrograms();
    AssetLoader::createTextures();
    AssetLoader::createModels();

    // create camera
    Camera cam = Camera(width, height);
    cam.setPos(glm::vec3(0.0f, 10.0f, 0.0f));

    // set light
    Light::setAmbientLight(glm::vec3(0.3f, 0.3f, 0.3f));
    Light::createDirectionalLight(glm::vec3(0.8f, 1.0f, 0.8f), glm::vec3(1.0f, 1.0f, 1.0f));

    // DEBUG: test some models
    for (int i = 0; i < 100; i ++) {
        Model* test = GameModels::createCube(rand() % 100 - 5, rand() % 100 + 0.2f, rand() % 100 - 5, glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
        test->setAlbedoTexture("box");
    }

    // create a tank
    Model testModelLoader = *ModelLoader::getModel("tank");
    testModelLoader.setTransform(glm::vec3(20.0f, 0.0f, 20.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    testModelLoader.setPolygoneMode(GL_LINE);

    // create a tree
    Model testTree = *ModelLoader::getModel("tree");
    testTree.setTransform(glm::vec3(5.0f, 0.0f, 5.0f), glm::vec3(1.0f, 1.0f, 1.0f));

    // instinitiate terrain entity
    Terrain terrain;

    // openGL render configs
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // GL_POINT, GL_LINE, GL_FILL
    glEnable(GL_DEPTH_TEST); // enable depth test
    glEnable(GL_CULL_FACE); // enable face culling
    glFrontFace(GL_CW); // set face culling to clock wise

    while (!glfwWindowShouldClose(display.window)) {
        // calculate deltaTime
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // handle glfw events
        glfwPollEvents();

        // handle inputs
        display.processInput();
        cam.processInput(display.window, deltaTime, Display::mouseDisabled, Display::mouseXPos, Display::mouseYPos);

        // clear openGL back buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);





        testModelLoader.render();
        testTree.render();

        terrain.render();

        // DEBUG: render test models
        for (int i = 0; i < GameModels::models.size(); i++) {
            GameModels::models[i]->render();
        }

        // swap openGL buffers
        glfwSwapBuffers(display.window);
    }

    return 0;
}
