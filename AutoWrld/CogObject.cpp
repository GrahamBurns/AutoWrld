#include "CogObject.h"

CogObject::CogObject()
{

	 Health = 100;
	 texturePath = "assets/Kerg.png";

}

void CogObject::use()
{
}

void CogObject::setPos(int x, int y)
{
	this->xpos = x;
	this->ypos = y;
}
