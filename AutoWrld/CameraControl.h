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

	float x = 0.0f;
	float y = 0.0f;
};

