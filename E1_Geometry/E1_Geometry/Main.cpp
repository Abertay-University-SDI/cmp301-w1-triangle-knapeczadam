// Main.cpp
#include "App1.h"
#include "App2.h"
#include "../DXFramework/System.h"

#define SHOW_QUAD 0

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{
	
#if SHOW_QUAD
	BaseApplication* app = new App2();
#else
	BaseApplication* app = new App1();
#endif
	
	System* system;

	// Create the system object.
	system = new System(app, 1200, 675, true, false);

	// Initialize and run the system object.
	system->run();

	// Shutdown and release the system object.
	delete system;
	system = 0;

	return 0;
}