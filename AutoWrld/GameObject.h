#pragma once
#include <SDL/SDL_render.h>
#include <string>


class GameObject {

public:
	GameObject();
	GameObject(int x, int y, int id);
	~GameObject();

	int getX();
	int getY();
	int getID();
	int getHunger();
	int getJob(int i);
	int* getActionArr();
	
	void setNeedsTask(bool task);
	void setID(int id);
	void setTarget(int targetX, int targetY, int job, int atJob);
	void setLocation(int x, int y);
	bool needsNewTask();

	void Render();
	void Update(int xpos, int ypos, int xOffset, int yOffset);
	void consume();
	void wait(int typeOfWaiting);

	std::string texturePath;


	int jobs[4]; // x = 0, y = 1, id = 2: will help link things like what to build there or who they fighting, taskID = 3: task id will say what they need to do when they get there.
	int actions[10];
	int skills[5];
	int actionPoint = 0;
	bool needsTask = true;

	int loadCode;
	int objId;
	int Hunger;
	int Health;
	bool isAlive;
	int waitTime;

	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};