#pragma once
#include "Components.h"


class CameraControl 
{


public:


	float getX();
	float getY();
	void CameraMoveW();
	void CameraMoveA();
	void CameraMoveD();
	void CameraMoveS();

	int x = 0;
	int y = 0;
};

