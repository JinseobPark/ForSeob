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

	mSOUND->Play(SOUND_NAME::BG);
	mSOUND->SetVolume(SOUND_NAME::BG, 0.2f);
	mSOUND->SetVolume(SOUND_NAME::CLICK, 0.05f);
}

void GameLogic::Update(float dt)
{
	if(mINPUT->IsTriggered(GLFW_KEY_A))
		mSOUND->Play(SOUND_NAME::CLICK);
	if (mINPUT->IsReleased(GLFW_KEY_S))
		mSOUND->Play(SOUND_NAME::CLICK);
	if (mINPUT->IsPressed(GLFW_KEY_D))
		mSOUND->Play(SOUND_NAME::CLICK);

	if(mINPUT->IsMouseButtonReleased(GLFW_MOUSE_BUTTON_1))
		mSOUND->Play(SOUND_NAME::CLICK);
	if (mINPUT->IsMouseButtonPressed(GLFW_MOUSE_BUTTON_2))
		mSOUND->Play(SOUND_NAME::CLICK);

	float cameraSpeed = 0.01f;

}
