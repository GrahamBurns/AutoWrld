#pragma once
#include "GameObject.h"
class JobAssigner {
	
	
	JobAssigner();
	~JobAssigner();
	void addJobToList(int x, int y, int job);
	void FindJob(int y, GameObject* npc);



};