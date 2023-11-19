#include "GameLogic.h"

GameLogic* mGAMELOGIC = nullptr;

GameLogic::GameLogic()
{
	assert(mGAMELOGIC == nullptr && "No more than one instance of GameLogic system!");
	mGAMELOGIC = this;
}

void GameLogic::Initialize()
{

}

void GameLogic::Update(float dt)
{
}
