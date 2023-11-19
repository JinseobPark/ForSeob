#pragma once
#include "Systems/SystemComponent.h"

class SoundClass : public SystemComponent
{
public:
	SoundClass();
	~SoundClass();


	void Initialize()override;
	void Update(float) override;
	void Shutdown();
private:


};
extern SoundClass* mSOUND;