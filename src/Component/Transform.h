#pragma once
#include "Component.h"
#include "glm/glm.hpp"

class Transform : public Component
{
public:
	Transform() : Component(ComponentType::CT_TRANSFORM)
	{
		position = glm::vec3(0, 0, 0);
		rotation = glm::vec3(0, 0, 0);
		scale = glm::vec3(1, 1, 1);
	}
	Transform(const Transform& trans) : Component(ComponentType::CT_TRANSFORM)
	{
		position = trans.position;
		rotation = trans.rotation;
		scale = trans.scale;
	}
	~Transform() {}

	glm::vec3 GetPosition() const { return position; }
	glm::vec3 GetRotation() const { return rotation; }
	glm::vec3 GetScale() const { return scale; }

	void setPosition(const glm::vec3& pos) { position = pos; }
	void setPosition(const float x, const float y, const float z) { position = glm::vec3(x, y, z); }
	void setRotation(const glm::vec3& rot) { rotation = rot; }
	void setRotation(const float x, const float y, const float z) { rotation = glm::vec3(x, y, z); }
	void setScale(const glm::vec3& s) { scale = s; }
	void setScale(const float x, const float y, const float z) { scale = glm::vec3(x, y, z); }


	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};

