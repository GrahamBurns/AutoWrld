#include "Krog.h"

Krog::Krog()
{
	texturePath = texture;
	isAlive = true;
	baseSkills[0] = (5); // will replace with a function that is called and needs to pass creature Type similar with subclasses for modibility

}

Krog::~Krog()
{
}

void Krog::setKrogMemory(GameObject* npc)
{
	this->entityMemory = npc;
}

GameObject* Krog::getKrogMemory()
{
	return nullptr;
}

void Krog::consume(int y) {

}