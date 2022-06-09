#pragma once
#include <SDL/SDL_render.h>
#include <string>

class Actors {

public:
	Actors();
	Actors(int x, int y, int id);
	~Actors();
	void Render();
	void Update(int xpos, int ypos);
	int getX();
	int getY();
	int getID();
	int getJob(int i);
	int* getActionArr();

	void setID(int id);
	void setTarget(int targetX, int targetY, int targetID);
	void doAction();
	bool needsNewTask();

	std::string texturePath;

private:

	int job[3]; // x = 1, y = 2, id = 3: will help link things like what to build there or who they fighting
	int actions[10];
	int actionPoint = 0;
	bool needsTask = true;




	int objId;
	int xpos = 0;
	int ypos = 0;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};