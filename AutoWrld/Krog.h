#pragma once
#include <string>
#include "GameObject.h"

class Krog : public GameObject
{
public:
	Krog();
	~Krog();
	
	void setKrogMemory(GameObject*);
	GameObject* getKrogMemory();
	void consume(int y);

private:
	int hunger = 100;
	int health = 100;
	GameObject* entityMemory = nullptr;
	std::string texture = "assets/Krog.png";
};