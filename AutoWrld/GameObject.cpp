#include "GameObject.h"
#include "TextureManager.h"
#include <string>
//                        class.texture(), class.getX(), class.getY()
GameObject::GameObject(int x , int y ,int id)
{
	objId = id;
	ypos = y;
	xpos = x;
}

GameObject::GameObject() {
	
}

GameObject::~GameObject()
{
}



void GameObject::consume()
{
}

void GameObject::wait(int typeOfWaiting)
{
	switch (typeOfWaiting)
	{
	case 0:	//Building
		waitTime = 15 - skills[0]; //15 is build time of wall,skills 0 is building skill
		break;
	default:
		break;
	}
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

int GameObject::getJob(int i)
{
	return jobs[i];
}

int* GameObject::getActionArr()
{
	return actions;
}

void GameObject::setNeedsTask(bool task)
{
	this->needsTask = task;
}

void GameObject::setID(int id) {
	objId = id;
}

int GameObject::getHunger() {
	return Hunger;
}

void GameObject::setTarget(int targetX, int targetY, int job,int atJob)
{
	jobs[0] = targetX;
	jobs[1] = targetY;
	jobs[2] = job;
	jobs[3] = atJob;
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