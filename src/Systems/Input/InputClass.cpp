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
	glfwSetKeyCallback(p_window, key_callback);
	glfwSetCursorPosCallback(p_window, cursor_position_callback);
	glfwSetWindowUserPointer(p_window, this);
}

void InputClass::Shutdown()
{
}

void InputClass::Update(float)
{
	for (auto& key : m_keyStates) {
		if (key.second == KeyState::BePressed) {
			key.second = KeyState::Pressed;
		}
		else if (key.second == KeyState::BeReleased) {
			key.second = KeyState::Released;
		}
		else if(key.second == KeyState::Pressed) {
			key.second = KeyState::Held;
		}
	}
	for (auto& key : m_mouseButtonStates) {
		if (key.second == KeyState::BePressed) {
			key.second = KeyState::Pressed;
		}
		else if (key.second == KeyState::BeReleased) {
			key.second = KeyState::Released;
		}
		else if (key.second == KeyState::Pressed) {
			key.second = KeyState::Held;
		}
	}
}

void InputClass::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (mINPUT != nullptr) {
		mINPUT->handleMouseClick(button, action, mods);
	}
}

void InputClass::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (mINPUT != nullptr) {
		mINPUT->handleKey(key, action, mods);
	}
}

void InputClass::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (mINPUT != nullptr) {
		mINPUT->handleCursorPosition(xpos, ypos);
	}
}


void InputClass::handleKey(int key, int action, int mods)
{
	if (action == GLFW_PRESS) {
		m_keyStates[key] = KeyState::BePressed;
		std::cout <<"Pressed Input : " << key << std::endl;
	}
	else if (action == GLFW_RELEASE) {
		m_keyStates[key] = KeyState::BeReleased;
		std::cout << "Released Input : " << key << std::endl;
	}
}

void InputClass::handleMouseClick(int button, int action, int mods)
{
	if (action == GLFW_PRESS) {
		m_mouseButtonStates[button] = KeyState::BePressed;
		std::cout << button << " Pressed Input : X = " << m_mouseX << ", Y = " << m_mouseY << std::endl;
	}
	else if (action == GLFW_RELEASE) {
		m_mouseButtonStates[button] = KeyState::BeReleased;
		std::cout << button << " Released Input : X = " << m_mouseX << ", Y = " << m_mouseY << std::endl;
	}
}

bool InputClass::IsTriggered(int key)
{
	return m_keyStates[key] == KeyState::Pressed;
}

bool InputClass::IsPressed(int key)
{
	return m_keyStates[key] == KeyState::Pressed || m_keyStates[key] == KeyState::Held;
}

bool InputClass::IsReleased(int key)
{
	if (m_keyStates[key] == KeyState::Released) {
		m_keyStates[key] = KeyState::None;
		return true;
	}
	return false;
}

bool InputClass::IsMouseButtonPressed(int button)
{
	return m_mouseButtonStates[button] == KeyState::Pressed;
}

bool InputClass::IsMouseButtonReleased(int button)
{
	if (m_mouseButtonStates[button] == KeyState::Released) {
		m_mouseButtonStates[button] = KeyState::None;
		return true;
	}
	return false;
}


