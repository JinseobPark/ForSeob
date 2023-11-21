#include "GameLogic.h"
#include "Object/ObjectManager.h"

GameLogic* mGAMELOGIC = nullptr;

GameLogic::GameLogic()
{
	assert(mGAMELOGIC == nullptr && "No more than one instance of GameLogic system!");
	mGAMELOGIC = this;
}

void GameLogic::Initialize()
{
	camera = mOBM->CreateCamera();
}

void GameLogic::Update(float dt)
{
	float cameraSpeed = 0.01f;
}
