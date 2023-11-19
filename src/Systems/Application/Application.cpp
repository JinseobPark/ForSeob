#include "Application.h"

Application* mAPPLICATION = nullptr;

Application::Application()
{
	assert(mAPPLICATION == nullptr && "No more than one instance of Application system!");
	mAPPLICATION = this;
	isFullscreen = false;
}

Application::~Application()
{
	ShutdownWindows();
}

void Application::Initialize()
{
	if (!glfwInit()) {
		std::cout << "Failed to initialize GLFW" << std::endl;
		return;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_MAJOR_VERSION);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_MINOR_VERSION);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);


	_window = glfwCreateWindow(m_width, m_height, "Global 3D Suka", nullptr, nullptr);
	if (!_window)
	{
		std::cout << "Failed to create the GLFW window\n";
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(_window);

	auto framebuffer_size_callback = [](GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); };
	glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);

	glfwSwapInterval(vSync);
	glfwSetWindowUserPointer(_window, reinterpret_cast<void*>(this));

	if (!gladLoadGLES2Loader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed load GLAD" << std::endl;
		return;
	}
	glViewport(0, 0, m_width, m_height);
}

void Application::Update(float deltaTime)
{
	processInput();

}

void Application::InitializeWindows(int&, int&)
{
}

void Application::ShutdownWindows()
{
	glfwDestroyWindow(_window);
	glfwTerminate();
}

void Application::processInput()
{
	if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(_window, true);
}

void Application::mouse_callback(double xpos, double ypos)
{
}

void Application::scroll_callback(double xoffset, double yoffset)
{
}
