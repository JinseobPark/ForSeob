#include "TimerClass.h"

TimerClass* mTIMER = nullptr;

TimerClass::TimerClass()
{
    assert(mTIMER == nullptr && "No more than one instance of Timer system!");
    mTIMER = this;
}

void TimerClass::Initialize()
{
    _lastFrame = static_cast<float>(glfwGetTime());
}

void TimerClass::Update(float)
{
    float currentFrame = static_cast<float>(glfwGetTime());
    _deltaTime = currentFrame - _lastFrame;
    _lastFrame = currentFrame;
    _totalTime += _deltaTime;
}
