/*
    File: Display.hpp
    Author: Ramzi Sah

    Description:
        handle display window
*/

#ifndef SAH_DISPLAY
#define SAH_DISPLAY

#include <iostream>

#include <glad.h>
#include <GLFW/glfw3.h>

#include "Camera.hpp"
#include "assets/AssetLoader.hpp"
#include "../logic/entities/Entities.hpp"
#include "GUI/GUI.hpp"

class Display {
private:
    // events for callback
    static void error_callback(int error, const char* description);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
    static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

    // for input
    static bool scapeKeyPressed;
    static bool V_KeyPressed;
    static bool MouseLeftBtn_KeyPressed;

public:
    Display(const char* title, unsigned int width, unsigned int height);
    ~Display() {};

    static void setDisableMouse();

    // size getters
    static unsigned int window_width;
    static unsigned int window_height;
    unsigned int getWindowWidth();
    unsigned int getWindowHeight();

    static bool mouseDisabled;
    static double mouseXPos;
    static double mouseYPos;

    static GLFWwindow* window;
};

#endif
