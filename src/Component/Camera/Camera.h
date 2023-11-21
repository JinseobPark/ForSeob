#pragma once
#include "Systems/Graphics/Graphics.h"
#include "Component/Component.h"
#include "Component/ComponentHeaders.h"
#include <glm/glm.hpp>

class Camera : public Component
{
public:
	Camera();
	~Camera();

	void Initialize() override;

	//Get Set
	void SetPosition(float x, float y, float z) { m_transform->setPosition(x, y, z); }
	void SetPosition(glm::vec3 pos) { m_transform->setPosition(pos); }
	void SetRotation(float x, float y, float z) { m_transform->setRotation(x, y, z); }
	void SetRotation(glm::vec3 pos) { m_transform->setRotation(pos); }

	glm::vec3 GetPosition() const { return m_transform->GetPosition(); }
	glm::vec3 GetRotation() const { return m_transform->GetRotation(); }

	void Update();

	glm::mat4 GetView() const { return m_view; }
	glm::mat4 GetProj() const { return m_proj; }

	//Camera Move
	void Rotation();

private:
	friend class Graphics;
	Transform* m_transform = nullptr;

	glm::mat4 m_view;
	glm::mat4 m_proj;

};