#include "GUI.hpp"

bool GUI::m_mouseEnabled;
ImVec2 GUI::m_windowSize;

GUI::GUI(GLFWwindow* window) {
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();

    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330 core");

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // ovverride styles to our theme
    setTheme();
};

void GUI::update(float deltaTime) {
    // get imGUIio configs
    static ImGuiIO& io = ImGui::GetIO();

    // feed inputs to dear imgui, start new frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    static bool show_demo_window = false;
    static bool show_params_window = false;
    static bool show_test_window = false;

    // Parameters ui
    {
        ImGui::SetNextWindowPos(ImVec2(20, 20)); //set pos
        ImGui::SetNextWindowSize(ImVec2(340, 105)); // set size

        ImGui::Begin("Debug UI", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);

        ImGui::Text("Enable/disable menus.");
        ImGui::Checkbox("Parameters", &show_params_window);
        // ImGui::Checkbox("Test Window", &show_test_window);
        // ImGui::Checkbox("GUI Demo Window", &show_demo_window);      // Edit bools storing our window open/close state

        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", deltaTime * 1000, 1/deltaTime);

        glm::vec3 playerPos = Entities::GUIget_playerPos();
        ImGui::Text("Player Pos X: %.1f | Y: %.1f | Z: %.1f", playerPos.x, playerPos.y, playerPos.z);
        ImGui::End();
    }

    if (!m_mouseEnabled) {
        // disable imGUI mouse input
        io.ConfigFlags = ImGuiConfigFlags_NoMouse;
    } else {
        // enable imGUI mouse input
        io.ConfigFlags = !ImGuiConfigFlags_NoMouse;

        // 2. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
        if (show_demo_window) {
            ImGui::ShowDemoWindow(&show_demo_window);
        }

        // params window
        if (show_params_window) {
            ImGui::SetNextWindowPos(ImVec2(20,130)); //set pos
            ImGui::SetNextWindowSize(ImVec2(350,150)); // set size

            ImGui::Begin("Parameters", &show_params_window, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)

            ImGui::ColorEdit3("Clear color", (float*)&clear_color); // Edit 3 floats representing a color

            // setCamView
            static bool camFreeView = false;
            ImGui::Checkbox("Free camera view", &camFreeView);
            Camera::handleGUI_freeCam_button(camFreeView);

            ImGui::End();
        }

        // 3. Show another simple window.
        if (show_test_window) {
            // make it full screen
            ImGui::SetNextWindowPos(ImVec2(0, 0)); //set pos
            ImGui::SetNextWindowSize(m_windowSize); // set size

            ImGui::Begin("Test Window", &show_test_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)

            ImGui::Text("test");

            static float f = 0.0f;
            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f

            static int counter = 0;
            if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            if (ImGui::Button("Close Me"))
                show_test_window = false;

            ImGui::End();
        }

        // help ui
        {
            ImGui::SetNextWindowPos(ImVec2(m_windowSize.x - 300, m_windowSize.y - 75)); //set pos

            ImGui::Begin("Help", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground);

            ImGui::Text("Change Camera mode \"V\"");
            ImGui::Text("Spwan a Prop \"B\" / Rotate \"R\" / Place \"left click\"");

            ImGui::End();
        }
    }
    // Render dear imgui into screen
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
};

/*------------------------------------*/
void GUI::setMouseEnable(bool _mouseEnabled) {
    m_mouseEnabled = _mouseEnabled;
}
void GUI::setMouseWindowSize(unsigned int _window_width, unsigned int _window_height) {
    m_windowSize = ImVec2(_window_width, _window_height);
}

/*------------------------------------*/
void GUI::setTheme() {
    // set font
    ImGuiIO& io = ImGui::GetIO(); // get io
    ImFont* font = io.Fonts->AddFontFromFileTTF("assets/fonts/Roboto-Regular.ttf", 15.0f);

    // ger styles
    ImGuiStyle& style = ImGui::GetStyle();

    /*------------------------------------ sizes ------------------------------------*/
    style.WindowPadding = ImVec2(10.0f, 10.0f);
    style.FramePadding = ImVec2(10.0f, 5.0f);
    style.ItemSpacing = ImVec2(10.0f, 5.0f);
    style.ItemInnerSpacing = ImVec2(10.0f, 5.0f);
    style.TouchExtraPadding = ImVec2(0.0f, 0.0f);
    style.IndentSpacing = 20.0f;
    style.ScrollbarSize = 15.0f;
    style.GrabMinSize = 10.0f;

    style.WindowBorderSize = 0.0f;
    style.ChildBorderSize = 0.0f;
    style.PopupBorderSize = 0.0f;
    style.FrameBorderSize = 0.0f;
    style.TabBorderSize = 0.0f;

    style.WindowRounding = 5.0f;
    style.ChildRounding = 0.0f;
    style.FrameRounding = 0.0f;
    style.PopupRounding = 5.0f;
    style.ScrollbarRounding = 0.0f;
    style.GrabRounding = 0.0f;
    style.TabRounding = 4.0f;

    style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
    style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
    style.SelectableTextAlign = ImVec2(0.0f, 0.0f);
    style.DisplaySafeAreaPadding = ImVec2(3.0f, 3.0f);

    /*------------------------------------ colors ------------------------------------*/
    #define HI(v)   ImVec4(0.502f, 0.075f, 0.256f, v)
    #define MED(v)  ImVec4(0.455f, 0.198f, 0.301f, v)
    #define LOW(v)  ImVec4(0.232f, 0.201f, 0.271f, v)
    #define BG(v)   ImVec4(0.200f, 0.220f, 0.270f, v)
    #define TEXT(v) ImVec4(0.860f, 0.930f, 0.890f, v)

    style.Colors[ImGuiCol_Text]                  = TEXT(0.78f);
    style.Colors[ImGuiCol_TextDisabled]          = TEXT(0.28f);
    style.Colors[ImGuiCol_WindowBg]              = ImVec4(0.13f, 0.14f, 0.17f, 1.00f);
    style.Colors[ImGuiCol_ChildWindowBg]         = BG( 0.58f);
    style.Colors[ImGuiCol_PopupBg]               = BG( 0.9f);
    style.Colors[ImGuiCol_Border]                = ImVec4(0.31f, 0.31f, 1.00f, 0.00f);
    style.Colors[ImGuiCol_BorderShadow]          = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style.Colors[ImGuiCol_FrameBg]               = BG( 1.00f);
    style.Colors[ImGuiCol_FrameBgHovered]        = MED( 0.78f);
    style.Colors[ImGuiCol_FrameBgActive]         = MED( 1.00f);
    style.Colors[ImGuiCol_TitleBg]               = LOW( 1.00f);
    style.Colors[ImGuiCol_TitleBgActive]         = HI( 1.00f);
    style.Colors[ImGuiCol_TitleBgCollapsed]      = BG( 0.75f);
    style.Colors[ImGuiCol_MenuBarBg]             = BG( 0.47f);
    style.Colors[ImGuiCol_ScrollbarBg]           = BG( 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrab]         = ImVec4(0.09f, 0.15f, 0.16f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered]  = MED( 0.78f);
    style.Colors[ImGuiCol_ScrollbarGrabActive]   = MED( 1.00f);
    style.Colors[ImGuiCol_CheckMark]             = ImVec4(0.71f, 0.22f, 0.27f, 1.00f);
    style.Colors[ImGuiCol_SliderGrab]            = ImVec4(0.47f, 0.77f, 0.83f, 0.14f);
    style.Colors[ImGuiCol_SliderGrabActive]      = ImVec4(0.71f, 0.22f, 0.27f, 1.00f);
    style.Colors[ImGuiCol_Button]                = ImVec4(0.47f, 0.77f, 0.83f, 0.14f);
    style.Colors[ImGuiCol_ButtonHovered]         = MED( 0.86f);
    style.Colors[ImGuiCol_ButtonActive]          = MED( 1.00f);
    style.Colors[ImGuiCol_Header]                = MED( 0.76f);
    style.Colors[ImGuiCol_HeaderHovered]         = MED( 0.86f);
    style.Colors[ImGuiCol_HeaderActive]          = HI( 1.00f);
    style.Colors[ImGuiCol_Separator]             = ImVec4(0.14f, 0.16f, 0.19f, 1.00f);
    style.Colors[ImGuiCol_SeparatorHovered]      = MED( 0.78f);
    style.Colors[ImGuiCol_SeparatorActive]       = MED( 1.00f);
    style.Colors[ImGuiCol_ResizeGrip]            = ImVec4(0.47f, 0.77f, 0.83f, 0.04f);
    style.Colors[ImGuiCol_ResizeGripHovered]     = MED( 0.78f);
    style.Colors[ImGuiCol_ResizeGripActive]      = MED( 1.00f);
    style.Colors[ImGuiCol_PlotLines]             = TEXT(0.63f);
    style.Colors[ImGuiCol_PlotLinesHovered]      = MED( 1.00f);
    style.Colors[ImGuiCol_PlotHistogram]         = TEXT(0.63f);
    style.Colors[ImGuiCol_PlotHistogramHovered]  = MED( 1.00f);
    style.Colors[ImGuiCol_TextSelectedBg]        = MED( 0.43f);
}
