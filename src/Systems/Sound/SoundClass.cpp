#include "SoundClass.h"

SoundClass* mSOUND = nullptr;
SoundClass::SoundClass()
{
	assert(mSOUND == nullptr && "No more than one instance of Sound system!");
	mSOUND = this;
}

SoundClass::~SoundClass()
{
}

void SoundClass::Initialize()
{
}

void SoundClass::Update(float)
{
}

void SoundClass::Shutdown()
{
}
