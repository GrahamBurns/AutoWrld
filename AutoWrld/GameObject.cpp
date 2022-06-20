#include "GameObject.h"
#include "TextureManager.h"
#include <string>
//                        class.texture(), class.getX(), class.getY()
GameObject::GameObject(int x , int y ,int id)
{
	objId = id;
	ypos = y;
	xpos = x;
	needs[0] = HUNGER;
	needs[1] = THIRST;
	needs[2] = OXYGEN;
}

GameObject::GameObject() {
	
}

GameObject::~GameObject()
{
}

int GameObject::getX()
{
	return xpos;
}

int GameObject::getY()
{
	return ypos;
}

int GameObject::getID()
{
	return objId;
}

int GameObject::getNeed(NEEDS n)
{
	return needMeters[n];
}

int* GameObject::getActionArr()		// USE TO PREVENT THINGS OVERCALLING PATHFINDING
{
	return actions;
}

void GameObject::setNeedsTask(bool task)
{
	this->needsTask = task;
}

	void GameObject::setTarget(int targetX, int targetY, int job,int atJob){	//DONT NEED THIS OR tasks[]
	tasks[0] = targetX;
	tasks[1] = targetY;
	tasks[2] = job;
	tasks[3] = atJob;
}

void GameObject::setLocation(int x, int y)
{
	this->xpos = x;
	this->ypos = y;
}

bool GameObject::needsNewTask()
{
	return needsTask;
}