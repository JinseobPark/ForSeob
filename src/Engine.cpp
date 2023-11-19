#include "Engine.h"

Engine* ENGINE = nullptr;

Engine::Engine()
{
	assert(ENGINE == nullptr && "More than onc instance of the Engine cannot be created!");
}

Engine::~Engine()
{
	DestroyAllSystems();
}

bool Engine::initialize()
{
	bool result = true;
	AddSystem(new Application());
	AddSystem(new Graphics());
	AddSystem(new TimerClass());
	AddSystem(new PhysicsClass());
	AddSystem(new InputClass());
	AddSystem(new SoundClass());
	AddSystem(new GameLogic());


	for (auto sys : gameSystems)
		sys->Initialize();

	return true;
}

void Engine::run()
{
	bool running = true;
	while (running)
	{
		running = Update();
	}
}

void Engine::DestroyAllSystems()
{
	for (auto sys = gameSystems.rbegin(); sys < gameSystems.rend(); ++sys)
		delete* sys;
}

void Engine::Shutdown()
{
}

bool Engine::Update()
{
	// Update the system stats.
	float dt = mTIMER->getDeltaTime();

	for (auto sys : gameSystems)
	{
		sys->Update(dt);
	}
	
	return !mAPPLICATION->isExit();
}

void Engine::AddSystem(SystemComponent* system)
{
	gameSystems.push_back(system);
}

