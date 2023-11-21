#pragma once
#include <string>
#include <vector>
#include <map>
#include "glm/glm.hpp"
#include "Component/ComponentHeaders.h"

class Object
{
	typedef unsigned int Object_ID;
public:
	friend class ObjectManager;
	Object();
	~Object();

	void Initialize();
	void Destroy(Object* obj); // OBM에서 제거

	bool AddComponent(Component* pComponent);
	Component* GetComponent(ComponentType cType);

	Object_ID GetObjectID() { return m_object_id; }
	void SetObjectID(Object_ID obj_id) { m_object_id = obj_id; }

	std::string GetName() const { return p_name; }
	void SetName(std::string name) { p_name = name; }
private:
	std::map<ComponentType, Component*> m_components;

	Object_ID m_object_id;
	std::string p_name;
};