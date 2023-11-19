#pragma once
#include <glad/glad.h>

class Buffer
{
public:
	Buffer() {}
	~Buffer();

	void initialize();
	void initializeHeart();
	
	unsigned int getVAO() { return VAO; }
	unsigned int getVertexSize() { return _vertex_size; }

private:
	unsigned int VBO = 0, VAO = 0;
	unsigned int _vertex_size = 0;

};