#pragma once
#include "Shader.h"
#include <vector>
#include <map>
#include <string>
class ShaderManager
{
public:
	ShaderManager() {}
	~ShaderManager() {}

	void initialize();

	Shader getShader(std::string name_) { return _shader_map[name_]; }

private:
	std::map<std::string, Shader> _shader_map;
};