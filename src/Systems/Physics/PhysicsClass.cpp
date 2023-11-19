#include "PhysicsClass.h"

PhysicsClass* mPHYSICS = nullptr;

PhysicsClass::PhysicsClass()
{
	assert(mPHYSICS == nullptr && "No more than one instance of Physics system!");
	mPHYSICS = this;
}

PhysicsClass::~PhysicsClass()
{
}

void PhysicsClass::Initialize()
{
}

void PhysicsClass::Update(float dt)
{
}
