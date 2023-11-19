#pragma once
#include "Systems/SystemComponent.h"

class TimerClass : public SystemComponent
{
public:
	TimerClass();
	~TimerClass() {}

	void Initialize() override;
	void Update(float) override;

	float getDeltaTime() const { return _deltaTime; }
	float getTotalTime() const { return _totalTime; }

private:
	float _deltaTime = 0.0f;
	float _lastFrame = 0.0f;
	float _totalTime = 0.0f;
};
extern TimerClass* mTIMER;
