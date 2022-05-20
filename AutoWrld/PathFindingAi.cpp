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

void PathFindingAi::actions(GameObject* NPC)
{
    int tarX = NPC->getJob(0);
    int tarY = NPC->getJob(1);
    int* j = NPC->getActionArr();


    for (int act = 0; act < 5; act++) {
        int x = 0;
        int y = 0;


        if (NPC->getX() > NPC->getJob(0))
            x--;
        else if (NPC->getX() < NPC->getJob(0))
            x++;
        else
            x = x;

        if (NPC->getY() > NPC->getJob(1))
            y--;
        else if (NPC->getY() < NPC->getJob(1))
            y++;
        else
            y = y;

        if (j[act] == x && j[act + 1] == y) {
            return;
        }

        if (3 > NPC->getX() - NPC->getJob(0) && 3 > NPC->getJob(1) - NPC->getY()) { // 3 is how close i want them to be!
            std::cout << "Hello" << std::endl;
            //NPC->
        }


        j[act] = x;
        j[act + 1] = y; // maybe out of bounds
    }

}
