#pragma once
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>

class WrldLoop
{
public:
	WrldLoop();
	~WrldLoop();

	void init(const char* title, int width, int height, bool fullscreen);

	void GetDesktopResolution(int& horizontal, int& vertical);

	void handleEvents();
	void update();
	bool running() { return isRunning; }
	void render();
	void clean();

	static SDL_Renderer* renderer;
	static SDL_Event event;
private:

	int _horizontal = 0;
	int _vertical = 0;
	bool isRunning = false;
	SDL_Window* window;

};
