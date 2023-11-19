#pragma once
#include "Systems/SystemComponent.h"

class InputClass : public SystemComponent
{
public:
	InputClass();
	~InputClass();

	void Initialize() override;
	void Shutdown();
	void Update(float) override;

	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

	void handleMouseClick(int button, int action, int mods);

private:
	GLFWwindow* p_window;
	unsigned int m_screenWidth = 0;
	unsigned int m_screenHeight = 0;
	unsigned int m_mouseX = 0;
	unsigned int m_mouseY = 0;
};
extern InputClass* mINPUT;