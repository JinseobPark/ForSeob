#pragma once
#include "Systems/SystemComponent.h"

class PhysicsClass : public SystemComponent
{
public:
	PhysicsClass();
	~PhysicsClass();

	void Initialize() override;
	void Update(float dt) override;


private:
};
extern PhysicsClass* mPHYSICS;
