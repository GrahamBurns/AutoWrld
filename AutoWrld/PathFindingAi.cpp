#include "PathFindingAi.h"
#include <iostream>

PathFindingAi::PathFindingAi(WrldGen* wg)
{
    map = wg;
}

void PathFindingAi::updatePath(int x, int y, int pathValue)
{
    pathingMap[x][y] = pathValue;
}

void PathFindingAi::actions(GameObject* npc)
{

      //  map->cleanTile(npc->getX(), npc->getY(), npc->getID());
       // npc->setLocation(npc->getX() + x, npc->getY() + y);
}