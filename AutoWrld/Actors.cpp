#include "Actors.h"
#include "TextureManager.h"
#include <string>
//                        class.texture(), class.getX(), class.getY()

Actors::Actors()
{

}

Actors::Actors(int x, int y, int id)
{
	objId = id;
	ypos = y * 16;
	xpos = x * 16;
}

Actors::~Actors()
{
}

void Actors::Update(int x, int y) {
	// pass get ai
	
	xpos += x;
	ypos += y;
	
	objTexture = TextureManager::LoadTexture(texturePath.c_str());

	xpos += x;
	ypos += y;

	srcRect.h = 16;
	srcRect.w = 16;
	srcRect.x = 0;
	srcRect.y = 0;
	destRect.x = xpos;
	destRect.y = ypos;

	destRect.w = srcRect.w;
	destRect.h = srcRect.h;

}

int Actors::getX()
{
	return xpos;
}

int Actors::getY()
{
	return ypos;
}

int Actors::getID()
{
	return objId;
}

int Actors::getJob(int i)
{
	return job[i];
}

int* Actors::getActionArr()
{
	return actions;
}

void Actors::setID(int id) {
	objId = id;
}

void Actors::setTarget(int targetX, int targetY, int targetID)
{
	job[0] = targetX;
	job[1] = targetY;
	job[2] = targetID;
	//job[3] = 0; //  what to do & needs to be changed!!!!!!

}

void Actors::doAction()
{
	if (actions == NULL) {
		needsTask = true;
	}
	else {
		needsTask = false;
	}

	Update(actions[actionPoint], actions[actionPoint + 1]);
	actionPoint++;
	
	if (actionPoint == 10) {
		actionPoint = 0;
		needsTask = true;
	}

	if (actions[actionPoint] == 0 && actions[actionPoint+1] == 0) {
		actionPoint = 0;
		needsTask = true;
	}
}

bool Actors::needsNewTask()
{
	return needsTask;
}