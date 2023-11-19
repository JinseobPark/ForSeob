#pragma once
#include "Systems/SystemHeader.h"

#include <string>
#include <vector>

class TimerClass;
class GraphicsClass;

class Engine
{
public:
	Engine();
	~Engine();

	bool initialize();
	void run();

	void DestroyAllSystems();
	void Shutdown();

private:
	bool Update();
	void AddSystem(SystemComponent* system);

private:
	std::vector<SystemComponent*> gameSystems;

};

extern Engine* ENGINE;