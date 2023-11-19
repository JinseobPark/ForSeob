#pragma once
//#include "glad/glad.h"
#include "Systems/SystemComponent.h"
#include <iostream>
#include "glfw/glfw3.h"
#include "glm/glm.hpp"

class Application : public SystemComponent
{
public:
	Application();
	~Application();


    void Initialize() override;
    void Update(float deltaTime) override;

    void InitializeWindows(int&, int&);
    void ShutdownWindows();

    void processInput();
    void mouse_callback(double xpos, double ypos);
    void scroll_callback(double xoffset, double yoffset);

    bool isExit() { return glfwWindowShouldClose(_window); }

    unsigned int GetWidth() const { return m_width; }
    unsigned int GetHeight() const { return m_height; }
    GLFWwindow* GetWindow() { return _window; } // need const or not
    bool isFullscreen;

private:

    unsigned int m_width = 512;
    unsigned int m_height = 512;

    const unsigned short OPENGL_MAJOR_VERSION = 3;
    const unsigned short OPENGL_MINOR_VERSION = 2;
    bool vSync = false;
    GLFWwindow* _window = nullptr;
};
extern Application* mAPPLICATION;