/*
    File: Display.cpp
    Author: Ramzi Sah

    Description:
        Display class definition
*/

#include "Display.hpp"

GLFWwindow* Display::window;
unsigned int Display::window_width;
unsigned int Display::window_height;

Display::Display(const char* title, unsigned int width, unsigned int height) {
    // init glfw
    if (!glfwInit()) {
        std::cout << "ERROR: glfw init failed." << std::endl;
    }

    // setting some glfw attribs
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // GLFWwindow is a struct containing window attribs
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window) {
        std::cout << "ERROR: can't start window." << std::endl;
    }

    // register glfw functions
    glfwSetErrorCallback(error_callback);
    glfwSetKeyCallback(window, key_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    // set openGL context
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // init glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "ERROR: Failed to initialize GLAD." << std::endl;
    }

    // openGL render configs
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // GL_POINT, GL_LINE, GL_FILL
    glEnable(GL_DEPTH_TEST); // enable depth test
    // glEnable(GL_CULL_FACE); // enable face culling
    glFrontFace(GL_CW); // set face culling to clock wise
    glEnable(GL_BLEND); // enable blending for transparency
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // set blending function

    // set window size values
    framebuffer_size_callback(window, width, height);

    // call mouse handler
    setDisableMouse();
}

bool Display::mouseDisabled = false;
void Display::setDisableMouse() {
    mouseDisabled = !mouseDisabled;
    if (mouseDisabled)
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    else
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // handle gui mouse
    GUI::setMouseEnable(mouseDisabled);
};

unsigned int Display::getWindowWidth() {
    return window_width;
};
unsigned int Display::getWindowHeight() {
    return window_height;
};

/* ---------- event functions ---------- */
// handle error events
void Display::error_callback(int error, const char* description) {
    fprintf(stderr, "glfw Error: %s\n", description);
}

// handle key press events
bool Display::scapeKeyPressed = false;
bool Display::V_KeyPressed = false;
bool Display::MouseLeftBtn_KeyPressed = false;
void Display::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    // handle escape key for mouse disable/enable
    if (!scapeKeyPressed && key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        scapeKeyPressed = true;
    }
    if (scapeKeyPressed && key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE) {
        scapeKeyPressed = false;

        // disable mouse
        setDisableMouse();
    }

    // handle v key for view mod change
    if (!V_KeyPressed && key == GLFW_KEY_V && action == GLFW_PRESS) {
        V_KeyPressed = true;
    }
    if (V_KeyPressed && key == GLFW_KEY_V && action == GLFW_RELEASE) {
        V_KeyPressed = false;

        // change view mod
        Camera::basculateView();
    }

    // handle entities key input
    Entities::keyEventInput(key, action);

    // std::cout << "key: " << key << " | action:" << action<< '\n';
}

// handle resize window event
void Display::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // reset size values
    window_width = width;
    window_height = height;

    // reset openGL viewPort
    glViewport(0, 0, window_width, window_height);

    // reset camera perspective
    Camera::setPerspectiveMat((float)window_width / (float)window_height);

    // handle GUI window size
    GUI::setMouseWindowSize(window_width, window_height);
}

double Display::mouseXPos;
double Display::mouseYPos;
void Display::mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    // reset mouse pos var members
    mouseXPos = xpos;
    mouseYPos = ypos;

    // handle entities mouse input event
    Entities::MouseEventInput(mouseDisabled, xpos, ypos);

    // std::cout << "xpos: " << mouseXPos << " | ypos: " << ypos << '\n';
};

// handle mouse left button key ingame click
void Display::mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {

}
