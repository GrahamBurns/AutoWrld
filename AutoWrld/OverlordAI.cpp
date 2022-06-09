#include "OverlordAI.h"
#include <iostream>
#include "GameObject.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

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


void OverlordAI::spawnEntity(int creatureID) // also needs to set x and y
{
    //TESTING STUFF
   Krog* krog = new Krog();
   krog->Update(10, 10,0,0);      // needs to start at zero becuase array starts at 0 not 1 stupid!! so he at 6,6 ALSO only take -1 from here not from anywhere else
   krog->setID(5);
   krog->setTarget(3, 3, 0,0);
   NPC.push_back(krog);

   krog = new Krog();
   krog->Update(13, 13,0,0);      // needs to start at zero becuase array starts at 0 not 1 stupid!! so he at 6,6
   krog->setID(6);
   krog->setTarget(0, 0, 0,1);
   NPC.push_back(krog);

  // std::cout << "Amount of entities: " << NPC. << std::endl;
}




GameObject* OverlordAI::getNPC(int id)
{
    return NPC[id];
}

int OverlordAI::getNPCCount() {
    return NPC.size();
}
