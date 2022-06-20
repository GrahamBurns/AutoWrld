#pragma once
#include "GameObject.h"
#include "WrldGen.h"


class PathFindingAi
{
public:
	PathFindingAi(WrldGen *wg);

	void updatePath(int x, int y, int pathValue);
	void actions(GameObject* NPC);

private:
	int pathingMap[30][30];
	WrldGen* map;
};

