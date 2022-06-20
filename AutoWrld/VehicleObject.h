#pragma once
#include <vector>
#include "GameObject.h"
#include "CogObject.h"
class VehicleObject {
public:

	VehicleObject();

	void setVelocity();
	void buildVehicle();
	void canMove();
	void findDriverSeat();
	void findFront();
	void moveVehicle();
	void setTarget(int targetX, int targetY, int job, int atJob);

	CogObject* temp();


	int velocity = 1;						// how many spaces it moves per tick
	int x = 20;
	int y = 20;
	int xOffset, yOffset;				// where to move the whole vehicle
	int jobs[4];
	int id;




	// checks
	bool hasPowerSource = true;
	bool hasDriver = true;
	bool isMoving = true;
	
	std::vector<CogObject*> vehicle;	// replace with cog object 

};
