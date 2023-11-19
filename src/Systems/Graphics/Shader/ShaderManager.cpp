#include "ShaderManager.h"
#include <fstream>

void ShaderManager::initialize()
{
	Shader defaulter; 
	defaulter.Load("src\\GLSL\\shader.vs", "src\\GLSL\\shader.fs");
	_shader_map["default"] = defaulter;
}
