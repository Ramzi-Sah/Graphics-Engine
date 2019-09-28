#ifndef SAH_GUI
#define SAH_GUI

#include <iostream>

#include <glad.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include "../../logic/entities/Entities.hpp"
#include "../Camera.hpp"

struct ImVec3 { float x, y, z; ImVec3(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f) { x = _x; y = _y; z = _z; } };

class GUI {
private:
    // for handle
    static bool m_mouseEnabled;
    static ImVec2 m_windowSize;

public:
    GUI(GLFWwindow* window);
    ~GUI() {};

    // logic
    void update(float deltaTime);

    // handle
    static void setMouseEnable(bool _mouseEnabled);
    static void setMouseWindowSize(unsigned int _window_width, unsigned int _window_height);
    static void setTheme();

    // public values
    ImVec4 clear_color = ImVec4(0.3f, 0.5f, 0.8f, 1.0f);


};

#endif
