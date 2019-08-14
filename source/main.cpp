#include <iostream>
#include <math.h>
#include <random>

#define STB_IMAGE_IMPLEMENTATION

#include "engine/Display.hpp"
#include "engine/assets/ShaderLoader.hpp"
#include "engine/assets/AssetLoader.hpp"
#include "engine/GameModels.hpp"
#include "engine/Model.hpp"
#include "engine/Camera.hpp"

static const int width = 800;
static const int height = 600;

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

    // create camera
    Camera cam = Camera(width, height);

    // DEBUG: test some models
    for (int i = 0; i < 10; i ++) {
        Model* test = GameModels::createCube(rand() % 10 - 5, rand() % 10 - 5, rand() % 10 - 5, glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
        test->setAlbedoTexture("assets/textures/container.jpg");
    }

    // openGL render configs
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // GL_POINT, GL_LINE, GL_FILL
    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(display.window)) {
        // calculate deltaTime
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // handle inputs
        display.processInput();
        cam.processInput(display.window, deltaTime, Display::mouseDisabled, Display::mouseXPos, Display::mouseYPos);

        // handle glfw events
        glfwPollEvents();

        // clear openGL back buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);







        // render models
        for (int i = 0; i < GameModels::models.size(); i++) {
            GameModels::models[i]->render();
        }

        // swap openGL buffers
        glfwSwapBuffers(display.window);
    }

    return 0;
}
