#include "Graphics.h"

Graphics* mGRAPHICS = nullptr;

Graphics::Graphics()
{
	assert(mGRAPHICS == nullptr && "No more than one instance of Graphics system!");
	mGRAPHICS = this;
}

Graphics::~Graphics()
{
	if (_shader_manager)	delete _shader_manager;
	if (_buffer)	delete _buffer;
}

void Graphics::Initialize()
{
	_shader_manager = new ShaderManager();
	_shader_manager->initialize();
	_buffer = new Buffer();
	_buffer->initialize();
	//_buffer->initializeHeart();
}

void Graphics::Update(float dt)
{
	float red = glm::abs(glm::cos(1.2f * mTIMER->getTotalTime()));
	float green = glm::abs(glm::sin(mTIMER->getTotalTime()));
	float blue = glm::abs(glm::sin(mTIMER->getTotalTime()) * glm::cos(mTIMER->getTotalTime()));
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Draw();

	glfwSwapBuffers(mAPPLICATION->GetWindow());
	glfwPollEvents();
}

void Graphics::Shutdown()
{
}

void Graphics::Draw()
{
	// batch each object
	_shader_manager->getShader("default").use();
	glBindVertexArray(_buffer->getVAO());
	glDrawArrays(GL_TRIANGLES, 0, _buffer->getVertexSize());
}
