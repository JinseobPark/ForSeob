#include "ObjectClass.h"

Object::Object()
{
	m_object_id = 0;
	p_name = "EmptyObject";
}

Object::~Object()
{
	for (auto component : m_components)
		delete component.second;
    p_name.clear();
}

void Object::Initialize()
{
    for (auto component : m_components)
        component.second->Initialize();
}

void Object::Destroy(Object* obj)
{
}

bool Object::AddComponent(Component* pComponent)
{
    if (pComponent->GetType() > ComponentType::CT_NONE && pComponent->GetType() < ComponentType::CT_COUNT)
    {
        auto it = m_components.find(pComponent->GetType());
        if (it == m_components.end())
        {
            m_components[pComponent->GetType()] = pComponent;
            pComponent->SetOwner(this); 
            return true; 
        }
        else
            return false; 
    }
    else
        return false; 
}

Component* Object::GetComponent(ComponentType cType)
{
    auto it = m_components.find(cType);
    if (it == m_components.end())
        return nullptr;
    else
        return it->second;
}
