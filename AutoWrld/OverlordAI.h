#pragma once
#include "GameObject.h"
#include <vector>
#include "WrldGen.h"
#include "Krog.h"
#include "VehicleObject.h"
#include "NeedUnfufillment.h"
#include "PathFindingAi.h"
#include "JobCreator.h"

class OverlordAI
{
public:
	OverlordAI();
	void LocalWeather(int rainfallPer, int season);
	void spawnEntity(int x,int y);
	GameObject* getNPC(int id);
	VehicleObject* getVehicle(int id);
	void UpdatePathAI();
	void UpdateNeeds();
	int getVehicleCount();
	int getNPCCount();
	void MapRef(WrldGen* wrldGen);
	void Jobassignment();

	void SearchJob();

private:

	WrldGen* wg = nullptr;
	std::vector <GameObject*> NPC;
	std::vector <VehicleObject*> vehicle;
	int entityIDCount = 1;
	PathFindingAi* pathAI = nullptr;
	JobCreator* jobCreator = new JobCreator();

};

