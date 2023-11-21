#include "ObjectClass.h"
#include "ObjectManager.h"
#include <time.h>


ObjectManager* mOBM = nullptr;
ObjectManager::ObjectManager()
{
	assert(mOBM == nullptr && "Factory already created! Only can create one.");
	mOBM = this;
	m_last_object_id = 1;
}

ObjectManager::~ObjectManager()
{
	DestroyAllObjects();
}

void ObjectManager::Initialize()
{
}

void ObjectManager::Update(float deltaTime)
{
    //Delete all objects in the ObjectToBeDeleted list
    for (auto object : m_deleted_object_list)
    {
        if (object == nullptr)
            continue;

        auto delete_obj_id = map_object_id.find(object->GetObjectID());

        assert(delete_obj_id != map_object_id.end() && "Object id bad memory.");
        if (delete_obj_id != map_object_id.end())
        {
            //delete and remove from the map
            delete object;
            map_object_id.erase(delete_obj_id);
        }
    }
    m_deleted_object_list.clear();
}

void ObjectManager::Destroy(Object* gameObject)
{
    m_deleted_object_list.push_back(gameObject);
}

Object* ObjectManager::CreateEmptyObject(std::string name)
{
    Object* gameObject = new Object();
    // grant id
    gameObject->SetObjectID(m_last_object_id);
    // mapping the id
    map_object_id[m_last_object_id] = gameObject;

    ++m_last_object_id;
    return gameObject;
}

Object* ObjectManager::CreateCamera()
{
    Object* gameObject = new Object();
    gameObject->SetObjectID(m_last_object_id);
    map_object_id[m_last_object_id] = gameObject;

    Transform* transform = new Transform();
    gameObject->AddComponent(transform);

    gameObject->SetName("Camera");
    gameObject->Initialize();
    return gameObject;
}

void ObjectManager::DestroyAllObjects()
{
    for (auto iter : map_object_id)
        delete iter.second;

    map_object_id.clear();
    m_last_object_id = 1;
}

Object* ObjectManager::FindObject(const std::string& name) const
{
    for (const auto obj : map_object_id)
    {
        if (obj.second->GetName() == name)
            return obj.second;
    }
    return nullptr;
}

Object* ObjectManager::FindObjectID(const ObjectID id) const
{
    for (const auto obj : map_object_id)
    {
        if (obj.second->GetObjectID() == id)
            return obj.second;
    }
    return nullptr;
}
