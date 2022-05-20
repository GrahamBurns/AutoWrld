#include "WrldLoop.h"
#include "TextureManager.h"
#include "Components.h"
#include "Vector2D.h"
#include "Collision.h"
#include "AssetManager.h"
#include <sstream>
#include "WrldGen.h"

Manager manager;
WrldGen* map;

SDL_Renderer* WrldLoop::renderer = nullptr;
SDL_Event WrldLoop::event;

SDL_Rect WrldLoop::camera = { 0,0,800,640 };

AssetManager* WrldLoop::assets = new AssetManager(&manager);

bool WrldLoop::isRunning = false;

auto& player(manager.addEntity());
auto& label(manager.addEntity());

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
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}

	//loads texture into memory
	assets->AddTexture("terrain", "assets/Krog.png");
	assets->AddTexture("player", "assets/player_anims.png");
	assets->AddTexture("projectile", "assets/proj.png");

	// map gen in here 3?mapscale and 32pixels x y
	map = new WrldGen ("assets/Krog.png", 3, 32);

	//map->GenWrld();
	map->LoadMap("output.txt", 32,32);

}

auto& tiles(manager.getGroup(WrldLoop::groupMap));
auto& players(manager.getGroup(WrldLoop::groupPlayers)); // should be actors
auto& colliders(manager.getGroup(WrldLoop::groupColliders));

void WrldLoop::handleEvents()
{

	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}



void WrldLoop::update()
{

	//SDL_Rect playerCol = player.getComponent<ColliderComponent>().collider;
	//Vector2D playerPos = player.getComponent<TransformComponent>().position;

	std::stringstream ss; // keeps string of playerposition
	//ss << "Player position: " << playerPos;

	manager.refresh();
	manager.update();

	
	for (auto& c : colliders)
	{
		SDL_Rect cCol = c->getComponent<ColliderComponent>().collider;
	//	if (Collision::AABB(cCol, playerCol))
	//	{
	//		player.getComponent<TransformComponent>().position = playerPos;
	//	}
	}
	 /*/ pew pews
	for (auto& p : projectiles)
	{
		if (Collision::AABB(player.getComponent<ColliderComponent>().collider, p->getComponent<ColliderComponent>().collider))
		{
			std::cout << "Hit player!" << std::endl;
			p->destroy();
		}
	}
	*/

	//camera.x = static_cast<int>(player.getComponent<TransformComponent>().position.x - 400);
	//camera.y = static_cast<int>(player.getComponent<TransformComponent>().position.y - 320);

	if (camera.x < 0)
		camera.x = 0;
	if (camera.y < 0)
		camera.y = 0;
	if (camera.x > camera.w)
		camera.x = camera.w;
	if (camera.y > camera.h)
		camera.y = camera.h;
}

void WrldLoop::render()
{
	SDL_RenderClear(renderer);
	for (auto& t : tiles)
	{
		t->draw();
	}

	for (auto& c : colliders)
	{
		c->draw();
	}

	for (auto& p : players)
	{
		p->draw();
	}

	//for (auto& p : projectiles)
	//{
	//	p->draw();
	//}

	label.draw();

	SDL_RenderPresent(renderer);
}

void WrldLoop::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}