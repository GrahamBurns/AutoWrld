#pragma once
#include "GameObject.h"
#include "Actors.h"
#include <vector>
#include "WrldGen.h"
#include "Krog.h"
#include "PathFindingAi.h"

class OverlordAI
{
public:
	OverlordAI();
	void LocalWeather(int rainfallPer, int season);
	void spawnEntity(int creatureID);
	GameObject* getNPC(int id);
	void UpdatePathAI();
	int getNPCCount();
	void MapRef(WrldGen* wrldGen);

private:

	WrldGen* wg = nullptr;
	std::vector <GameObject*> NPC;
	int entityIDCount = 1;
	PathFindingAi* pathAI = nullptr;

};

