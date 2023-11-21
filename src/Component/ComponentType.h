#pragma once

enum class ComponentType
{
	CT_NONE = 0,
	CT_TRANSFORM,
	CT_MODEL,
	CT_COLLISION,
	CT_RIGID_BODY,
	CT_CAMERA,
	CT_COUNT
};

class Transform;
class Model;
class Sprite;
class Camera;
