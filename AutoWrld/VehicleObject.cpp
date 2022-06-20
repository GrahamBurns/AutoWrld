#include "VehicleObject.h"

VehicleObject::VehicleObject()
{
	buildVehicle();
}

void VehicleObject::setVelocity()
{
}

void VehicleObject::buildVehicle()
{
	// 10,10 , 10,11
	// 11,10 , 11,11
	// 12,10 , 12,11


	CogObject* a = temp();
	a->setPos(20, 20);
	vehicle.push_back(a);


	CogObject* b = temp();
	b->setPos(20, 21);
	vehicle.push_back(b);


	CogObject* c = temp();
	c->setPos(21, 20);
	vehicle.push_back(c);

	CogObject* d = temp();
	d->setPos(21, 21);
	vehicle.push_back(d);


	CogObject* e = temp();
	e->setPos(22, 20);
	vehicle.push_back(e);


	CogObject* f = temp();
	f->setPos(22, 21);
	vehicle.push_back(f);



}

void VehicleObject::canMove()
{
}

void VehicleObject::findDriverSeat()
{
}

void VehicleObject::findFront()
{



}
void VehicleObject::moveVehicle()
{
	xOffset += 1;
	yOffset += 1;
	for (int i = 0; i < vehicle.size();i++) {
		vehicle[i]->setPos(vehicle[i]->xpos + xOffset, vehicle[i]->ypos + yOffset);
		
	}
	xOffset = 0;
	yOffset = 0;
}

void VehicleObject::setTarget(int targetX, int targetY, int job, int atJob)
{
	jobs[0] = targetX;
	jobs[1] = targetY;
	jobs[2] = job;
	jobs[3] = atJob;
}

CogObject* VehicleObject::temp()
{
	CogObject* a = new CogObject();

	return a;
}
