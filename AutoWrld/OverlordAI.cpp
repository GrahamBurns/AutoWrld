#include "OverlordAI.h"
#include <iostream>
#include "GameObject.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "AutoGen.h"
#include "NeedUnfufillment.h"

OverlordAI::OverlordAI()
{
    NPC.reserve(1000);

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
    //jobCreator.

}

void OverlordAI::UpdatePathAI() {
    for (int i = 0; i < NPC.size();i++) {
        pathAI->actions(NPC[i]);

    }
    for (int i = 0; i < vehicle.size();i++) {
        vehicle[i]->moveVehicle();

    }
}

void OverlordAI::UpdateNeeds() {
    for (int i = 0; i < NPC.size();i++) {
        if (NPC[i]->isActive) {
            for (int x = 0;x < NPC[i]->needs.size(); x++) {
                NPC[i]->needMeters[x] -= (NPC[i]->excertion + 1);
                if (NPC[i]->needMeters[x] == 0) {
                    //needsManager->needUnfufilled(NPC[i]->needs[i], NPC[i]->sufferingAmount);

                }

            }
        }
    }
}


AutoGen gen;
int count = 0;
VehicleObject* vet = new VehicleObject();

void OverlordAI::spawnEntity(int x, int y) // also needs to set x and y
{
    //TESTING STUFF
    /*
    for (int i = 0; i < 1000; i++) {
        Krog* krog = new Krog();

       x = gen.getrandNum(0, 20);
       y = gen.getrandNum(0, 20);

        krog->setLocation(gen.getrandNum(0, 50), gen.getrandNum(0, 50));
        krog->setID(i);
        krog->setTarget(gen.getrandNum(0, 50), gen.getrandNum(0, 50), 0, 0);
        NPC.push_back(krog);
        std::cout << i << " " << "Spawned at x:" << x << " y:" << y << std::endl;

        VEHICLE TEST STUFF BELOW

        x = gen.getrandNum(0, 20);
        y = gen.getrandNum(0, 20);

    vet->id = 0;
    vet->setTarget(gen.getrandNum(0, 50), gen.getrandNum(0, 50), 0, 0);
    vehicle.push_back(vet);
    UpdatePathAI();

    }
    */
    x = gen.getrandNum(0, 20);
    y = gen.getrandNum(0, 20);

    vet->id = 0;
    vet->setTarget(gen.getrandNum(0, 50), gen.getrandNum(0, 50), 0, 0);
    vehicle.push_back(vet);
    UpdatePathAI();

}



GameObject* OverlordAI::getNPC(int id)
{
    return NPC[id];
}


int OverlordAI::getNPCCount() {
    return NPC.size();
}

VehicleObject* OverlordAI::getVehicle(int id)
{
    return vehicle[id];
}

int OverlordAI::getVehicleCount() {
    return vehicle.size();
}