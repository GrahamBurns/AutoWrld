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
    if (npc->getJob(3) == 1) {
        doAction(npc);
        return;
    }

    int x = 0, y = 0;       

        if (npc->getX() > npc->getJob(0))
            x--;
        else if (npc->getX() < npc->getJob(0))
            x++;
        else
            x = x;

        if (npc->getY() > npc->getJob(1))
            y--;
        else if (npc->getY() < npc->getJob(1))
            y++;
        else
            y = y;

        map->cleanTile(npc->getX(), npc->getY(), npc->getID());
        npc->setLocation(npc->getX() + x, npc->getY() + y);

        if (npc->getJob(0) == x && npc->getJob(1) == y) { //TRIGGER JOB
            npc->setTarget(npc->getX(), npc->getY(), npc->getJob(2), 1);
        }
}

void PathFindingAi::doAction(GameObject* NPC) {
    //find what job it is and do it
    if (NPC->waitTime != 0 && !(NPC->needsNewTask()))
        NPC->waitTime -= 1;
    else 
       NPC->setNeedsTask(true);
} 