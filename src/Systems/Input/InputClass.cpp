#include "InputClass.h"
#include "../Application/Application.h"

InputClass* mINPUT = nullptr;

InputClass::InputClass()
{
	assert(mINPUT == nullptr && "No more than one instance of Input system!");
	mINPUT = this;
	p_window = nullptr;
}

InputClass::~InputClass()
{
}

void InputClass::Initialize()
{
	p_window = mAPPLICATION->GetWindow();
	m_screenWidth = mAPPLICATION->GetWidth();
	m_screenHeight = mAPPLICATION->GetHeight();

	glfwSetMouseButtonCallback(p_window, mouse_button_callback);

	glfwSetWindowUserPointer(p_window, this);
}

void InputClass::Shutdown()
{
}

void InputClass::Update(float)
{
}

void InputClass::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	InputClass* inputClass = static_cast<InputClass*>(glfwGetWindowUserPointer(window));
	if (inputClass) {
		inputClass->handleMouseClick(button, action, mods);
	}
}

void InputClass::handleMouseClick(int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
		double xpos, ypos;
		glfwGetCursorPos(p_window, &xpos, &ypos);
		std::cout << "Touch Input : X = " << xpos << ", Y = " << ypos << std::endl;
	}
}
