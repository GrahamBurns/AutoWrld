#pragma once
#include <SDL/SDL_render.h>
#include <string>
#include "enums.h"
#include <vector>

//SDL_SetTextureAlphaMod(img, opacity); for texture brightness 

class GameObject {

public:
	GameObject();
	GameObject(int x, int y, int id);
	~GameObject();

	int getX();
	int getY();
	int getID();
	int getNeed(NEEDS n);
	int getTask(int i);
	int* getActionArr();
	
	void setNeedsTask(bool task);
	//void setID(int id);
	void setTarget(int targetX, int targetY, int job, int atJob);
	void setLocation(int x, int y);
	bool needsNewTask();

	std::string texturePath;


	int tasks[4]; // x = 0, y = 1, id = 2: will help link things like what to build there or who they fighting, taskID = 3: task id will say what they need to do when they get there.
	int actions[10];
	int baseSkills[5];
	int actualSkills[5];


    std::vector<int>      needMeters;	// needs to be loaded from a function	(think like hunger thirst sleep ENUMS
	std::vector<NEEDS>    needs;
	std::vector<TRAITS>   traits;
	std::vector<STATES>   states;

	int health = 100;
	int excertion = 1;
	int xpos;
	int ypos;
	int loadCode;
	int objId;
	int sufferingAmount = 0;


	bool isActive;	// checks to see if it can even do things
	bool isAlive = true;
	bool needsTask = true;
	bool stateChecked = false;
};