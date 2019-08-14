#include "Display.hpp"

Display::Display(const char* title, unsigned int width, unsigned int height) {
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

    // set openGL context
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // init glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "ERROR: Failed to initialize GLAD." << std::endl;
    }

    // set openGL vew port
    glViewport(0, 0, width, height);
}
bool Display::mouseDisabled = true;
void Display::setDisableMouse() {
    mouseDisabled = !mouseDisabled;
    if (mouseDisabled)
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    else
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
};

void Display::processInput() {
    // handle escape key for mouse disable/enable
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        scapeKeyPressed = true;
    } else if (scapeKeyPressed && glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_RELEASE) {
        scapeKeyPressed = false;
        setDisableMouse();
    }

}
/* ---------- event functions ---------- */
// handle error events
void Display::error_callback(int error, const char* description) {
    fprintf(stderr, "glfw Error: %s\n", description);
}

// handle key press events
void Display::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        // glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

// handle resize window event
void Display::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // reset openGL viewPort
    glViewport(0, 0, width, height);

    // reset camera perspective
    Camera::setPerspectiveMat((float)width/(float)height);
}

double Display::mouseXPos;
double Display::mouseYPos;
void Display::mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    mouseXPos = xpos;
    mouseYPos = ypos;
};
