#include "Camera.h"
#include "Object/ObjectClass.h"

Camera::Camera() : Component(ComponentType::CT_CAMERA)
{
	m_view = glm::mat4(1.0f);
	m_proj = glm::mat4(1.0f);
	mGRAPHICS->m_camera = this; //Only ONE
}

Camera::~Camera()
{
	mGRAPHICS->m_camera = nullptr;
}

void Camera::Initialize()
{
	m_transform = (Transform*)GetOwner()->GetComponent(ComponentType::CT_TRANSFORM);
	SetPosition(0.0f, 2.0f, -10.0f);
}

void Camera::Update()
{
}

void Camera::Rotation()
{
}
