#pragma once

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <iostream>
#include <vector>
#include <SDL/SDL_events.h>

class AssetManager;
class ColliderComponent;

class WrldLoop
{
public:
	WrldLoop();
	~WrldLoop();

	void init(const char* title, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	bool running() { return isRunning; }
	void render();
	void clean();

	static SDL_Renderer* renderer;
	static SDL_Event event;
	static bool isRunning;
	static SDL_Rect camera;
	static AssetManager* assets;
	enum groupLabels : std::size_t
	{
		groupMap,
		groupPlayers,
		groupColliders,
		groupProjectiles
	};

private:

	int cnt = 0;
	SDL_Window* window;
};