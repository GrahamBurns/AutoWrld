#pragma once
#include <string>
class CogObject {
public:
	CogObject();

	void use();
	void setPos(int x, int y);


	std::string texturePath = "assets/Kerg.png";

	int xpos;
	int ypos;
	int Health;
	int loadCode;
	int objId;
	int functions[15];


	bool isWorking;
	bool isBroke;
	bool isControlled;
	bool isWeapon;
	bool isRanged;
	bool isSolid;
};