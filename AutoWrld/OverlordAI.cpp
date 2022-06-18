#include "OverlordAI.h"
#include <iostream>
#include "GameObject.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "AutoGen.h"

OverlordAI::OverlordAI()
{
}

void OverlordAI::LocalWeather(int rainfallPer, int season)
{
}

void OverlordAI::MapRef(WrldGen* worldGen) {
    wg = worldGen;
    pathAI = new PathFindingAi(wg);
}
void OverlordAI::Jobassignment()
{
    //someone who has nothing to do call this toll free number.
    // realy should be its own class
    // have a list of jobs created by stuff like stone that needs to be pick up with create it 
}

void OverlordAI::SearchJob() {
}

void OverlordAI::UpdatePathAI() {
    for (int i = 0; i < NPC.size();i++) {
        pathAI->actions(NPC[i]);
    }
}

AutoGen gen;
int count = 0;

void OverlordAI::spawnEntity(int x, int y) // also needs to set x and y
{
    //TESTING STUFF

    for (int i = 0; i < 250; i++) {
        Krog* krog = new Krog();

       x = gen.getrandNum(0, 20);
       y = gen.getrandNum(0, 20);

        krog->Update(gen.getrandNum(0, 50), gen.getrandNum(0, 50), 0, 0);      // needs to start at zero becuase array starts at 0 not 1 stupid!! so he at 6,6 ALSO only take -1 from here not from anywhere else
        krog->setID(i);
        krog->setTarget(gen.getrandNum(0, 50), gen.getrandNum(0, 50), 0, 0);
        NPC.push_back(krog);
        std::cout << i << " " << "Spawned at x:" << x << " y:" << y << std::endl;

    }
}



GameObject* OverlordAI::getNPC(int id)
{
    return NPC[id];
}

int OverlordAI::getNPCCount() {
    return NPC.size();
}
