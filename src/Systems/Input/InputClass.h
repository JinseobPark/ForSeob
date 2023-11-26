#pragma once
#include "Systems/SystemComponent.h"
#include <map>

enum class KeyState {
	None,
	Released,
	Pressed,
	Held,
	BePressed,
	BeReleased
};

class InputClass : public SystemComponent
{
public:
	InputClass();
	~InputClass();

	void Initialize() override;
	void Shutdown();
	void Update(float) override;

	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

	void handleKey(int key, int action, int mods);
	void handleMouseClick(int button, int action, int mods);
	bool IsTriggered(int key); 
	bool IsPressed(int key);
	bool IsReleased(int key); 


	void handleCursorPosition(double xpos, double ypos) { m_mouseX = (unsigned int)xpos; m_mouseY = (unsigned int)ypos; }
	bool IsMouseButtonPressed(int button);
	bool IsMouseButtonReleased(int button);
	std::pair<double, double> GetMousePosition() { return { m_mouseX, m_mouseY }; }
private:
	GLFWwindow* p_window;
	unsigned int m_screenWidth = 0;
	unsigned int m_screenHeight = 0;
	unsigned int m_mouseX = 0;
	unsigned int m_mouseY = 0;
	std::map<int, KeyState> m_keyStates;
	std::map<int, KeyState> m_mouseButtonStates;
};
extern InputClass* mINPUT;