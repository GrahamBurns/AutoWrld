#include "WrldLoop.h"
#include <iostream>
#include "Krog.h"
#include <wtypes.h>
#include "WrldGen.h"
#include <string>
#include "TextureManager.h"
#include "GameObject.h"
#include "WrldGen.h"
#include "ECS.h"
#include "Components.h"
#include "OverlordAI.h"
#include "Actors.h"
#include <conio.h>
#include <iostream>
#include "CameraControl.h"
#include "Actors.h"
#include "AutoGen.h"

using namespace std;
WrldGen* wrldGen = new WrldGen();
CameraControl* cam = new CameraControl();

SDL_Event WrldLoop::event;
SDL_Renderer* WrldLoop::renderer = nullptr;

WrldLoop::WrldLoop()
{}

WrldLoop::~WrldLoop()
{}

void WrldLoop::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255);
		}

		isRunning = true;
	}

	wrldGen = new WrldGen();
	wrldGen->LoadMap();
}

void WrldLoop::handleEvents()
{
	SDL_PollEvent(&event);

	switch (WrldLoop::event.key.keysym.sym)
	{
	case SDLK_w:
		cam->CameraMoveW();
		break;
	case SDLK_a:
		cam->CameraMoveA();
		break;
	case SDLK_d:
		cam->CameraMoveD();
		break;
	case SDLK_s:
		cam->CameraMoveS();
		break;
	default:
		break;
	}

	//if (WrldLoop::event.type == SDL_KEYUP)
}

int wrldTick = 0;
int coords;
OverlordAI OLA;
int xOffset = 0;
int yOffset = 0;
AutoGen* maker = new AutoGen();

void WrldLoop::update()
{
	wrldTick++;

	if (wrldTick == 60) {
		if (coords == 0) {
			OLA.MapRef(wrldGen);
			OLA.spawnEntity(1);
			maker->generateWrld();
		}
		OLA.UpdatePathAI();
		coords = 1;
		wrldTick = 0;
	}
}


void WrldLoop::render()
{
	xOffset = cam->getX();
	yOffset = cam->getY();

	SDL_RenderClear(renderer);
	wrldGen->DrawMap(xOffset,yOffset);
	if (OLA.getNPCCount() != NULL) {
		for (int i = 0; i < OLA.getNPCCount(); i++) {
			OLA.getNPC(i)->Update(OLA.getNPC(i)->getX(), OLA.getNPC(i)->getY(), xOffset, yOffset);
			OLA.getNPC(i)->Render();
		}
	}
	SDL_RenderPresent(renderer);
}

void WrldLoop::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}