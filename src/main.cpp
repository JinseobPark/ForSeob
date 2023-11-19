#include <iostream>
#include "Engine.h"

#if defined(DEBUG) || defined(_DEBUG)
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#else
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif


int main()
{
#if defined(DEBUG) || defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_crtBreakAlloc( number); //number = 메모리 할당 번호
#endif

	try
	{
		Engine SeobDuo;
		if (!SeobDuo.initialize()) return 0;
		SeobDuo.run();
	}
	catch (_exception)
	{
		std::cout << "failed. program down\n";
		return 0;
	}

}