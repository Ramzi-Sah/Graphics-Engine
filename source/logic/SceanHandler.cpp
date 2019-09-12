#include "SceanHandler.hpp"

Display* SceanHandler::m_display;
GUI* SceanHandler::gui;
Entities* SceanHandler::entities;

void SceanHandler::init(Display* _display) {
    // set window class member
    m_display = _display;

    // init GUI system
    gui = new GUI(m_display->window);

    // init entities
    entities = new Entities();
};

void SceanHandler::update(float deltaTime) {
    /*--------------- logic ---------------*/
    // update game entities
    Entities::update(deltaTime);

    /*--------------- render ---------------*/
    // clear openGL back buffer
    glClearColor(gui->clear_color.x, gui->clear_color.y, gui->clear_color.z, gui->clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // render game entities
    Entities::render();

    // update gui
    gui->update(deltaTime);

    // swap openGL buffers
    glfwSwapBuffers(m_display->window);
}
