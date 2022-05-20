#pragma once
#include <string>
#include "GameObject.h"

class Krog : public GameObject
{
public:
	Krog();
	~Krog();

private:
	int _krogHealth = 100;
	std::string texture = "assets/Krog.png";
};
