#pragma once
#include "Systems/SystemComponent.h"

class Object;
class GameLogic : public SystemComponent
{
public:
	GameLogic();
	~GameLogic() {}


	void Initialize() override;
	void Update(float dt) override;

private:
	// temporary only one camera
	Object* camera = nullptr;

};
extern GameLogic* mGAMELOGIC;