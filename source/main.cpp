/*
    File: main.cpp
    Author: Ramzi Sah

    Description:
        main program entry point
*/

#include <iostream>
#include <math.h>
#include <random>

#define STB_IMAGE_IMPLEMENTATION

#include "engine/Display.hpp"
#include "engine/assets/AssetLoader.hpp"
#include "logic/SceanHandler.hpp"

static const int width = 1280;
static const int height = 720;

float deltaTime = 0.0f;	// Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame
float currentFrame;

int main(int argc, char** argv) {
    // create display
    Display display("SAH Game Engine", width, height);

    // import assets
    AssetLoader::createShaderPrograms();
    AssetLoader::createTextures();
    AssetLoader::createModels();

    // init SceanHandler
    SceanHandler::init(&display);

    while (!glfwWindowShouldClose(Display::window)) {
        // calculate deltaTime
        currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // handle glfw events
        glfwPollEvents();

        // update Scean handler
        SceanHandler::update(deltaTime);
    }

    return 0;
}
