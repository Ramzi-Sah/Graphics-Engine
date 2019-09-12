#ifndef SAH_SCEANHANDLER
#define SAH_SCEANHANDLER

#include "../engine/Display.hpp"
#include "../engine/GUI/GUI.hpp"
#include "entities/Entities.hpp"

class SceanHandler {
private:
    static Display* m_display;
    static GUI* gui;
    static Entities* entities;

public:
    SceanHandler();
    ~SceanHandler() {};

    static void init(Display* _display);
    static void update(float deltaTime);


};

#endif
