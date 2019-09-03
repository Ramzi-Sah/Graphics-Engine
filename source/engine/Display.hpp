#ifndef SAH_DISPLAY
#define SAH_DISPLAY

#include <iostream>

#include "../dependencies/glad.h"
#include <GLFW/glfw3.h>

#include "Camera.hpp"
#include "assets/AssetLoader.hpp"

class Display {
private:
    // events for callback
    static void error_callback(int error, const char* description);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    static void mouse_callback(GLFWwindow* window, double xpos, double ypos);

public:
    Display(const char* title, unsigned int width, unsigned int height);
    ~Display() {};

    void setDisableMouse();

    // for input
    bool scapeKeyPressed = false;
    bool V_KeyPressed = false;
    void processInput();

    static bool mouseDisabled;
    static double mouseXPos;
    static double mouseYPos;

    GLFWwindow* window;


};

#endif
