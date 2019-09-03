#include <iostream>
#include <math.h>
#include <random>

#define STB_IMAGE_IMPLEMENTATION

#include "engine/Display.hpp"
#include "engine/assets/AssetLoader.hpp"
#include "engine/assets/ModelLoader.hpp"
#include "engine/Model.hpp"
#include "engine/Light.hpp"

#include "entities/Entities.hpp"

static const int width = 1280;
static const int height = 720;

float deltaTime = 0.0f;	// Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame

int main(int argc, char** argv) {
    // create display
    Display display("SAH Game", width, height);

    // import assets
    AssetLoader::createShaderPrograms();
    AssetLoader::createTextures();
    AssetLoader::createModels();

    // init entities
    Entities entities(width, height);

    // set light
    Light::setAmbientLight(glm::vec3(0.5f, 0.5f, 0.5f));
    Light::createDirectionalLight(glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.5f, 0.5f, 0.5f));

    // openGL render configs
    glClearColor(0.3f, 0.5f, 0.8f, 1.0f);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // GL_POINT, GL_LINE, GL_FILL
    glEnable(GL_DEPTH_TEST); // enable depth test
    glEnable(GL_CULL_FACE); // enable face culling
    glFrontFace(GL_CW); // set face culling to clock wise

    float currentFrame;
    while (!glfwWindowShouldClose(display.window)) {
        // calculate deltaTime
        currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // handle glfw events
        glfwPollEvents();

        // handle inputs
        display.processInput();

        // update game entities
        entities.update(display.window, deltaTime);

        // clear openGL back buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // render game entities
        entities.render();





        // swap openGL buffers
        glfwSwapBuffers(display.window);

        // display frames per second
        // std::cout << "FPS: " << 1/deltaTime << '\n';
    }

    return 0;
}
