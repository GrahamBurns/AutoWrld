#include <Windows.h>
#include "wtypes.h"
#include "WrldLoop.h"

WrldLoop* wrldLoop = nullptr;

int main(int argc,char** argv) {


	Uint32 frameStart;
	int frameTime;

	int Fps = 60;
	float frameDelay = 1000.0 / Fps;


	wrldLoop = new WrldLoop();
	wrldLoop->init("AutoWrld", 1250, 980, false);

	while (wrldLoop->running())
	{
		frameStart = SDL_GetTicks();

		wrldLoop->update();
		wrldLoop->render();
		wrldLoop->handleEvents();
		//wrldLoop->handleMouseEvents();
		frameTime = SDL_GetTicks() - frameStart;
		
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}

	}

	wrldLoop->clean();
	return 0;
}