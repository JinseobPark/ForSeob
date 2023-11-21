#pragma once
#include <map>
#include "Systems/SystemComponent.h"
#include "Component/ComponentHeaders.h"
#include "ObjectClass.h"
#include <vector>
#include <string>

class Object;
using ObjectID = unsigned;

class ObjectManager : public SystemComponent
{
public:
	ObjectManager();
	~ObjectManager();

	void Initialize() override;
	void Update(float deltaTime) override;

	void Destroy(Object* gameObject);

	Object* CreateEmptyObject(std::string name);
	Object* CreateCamera();

	void DestroyAllObjects();

	//Find Object
	Object* FindObject(const std::string& name) const;
	Object* FindObjectID(const ObjectID id) const;

private:
	ObjectID m_last_object_id;
	std::map<ObjectID, Object*> map_object_id;
	std::vector<Object*> m_deleted_object_list;
};
extern ObjectManager* mOBM;