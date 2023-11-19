#pragma once
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <cassert>

class SystemComponent
{
public:
	// Initialize Component 
	virtual void Initialize() = 0;

	// Update Component
	virtual void Update(float deltaTime) = 0;

	virtual ~SystemComponent()
	{
		// nothing
	}
	
}; // class SystemComponent