#include "JobAssigner.h"

void JobAssigner::addJobToList(int x, int y, int job)
{
}

void JobAssigner::FindJob(int y, GameObject* npc)
{

	switch (y) {
	case 0: //
		npc->wait(y);
		break;
	case 1:
		npc->consume();
		break;
	};
}
