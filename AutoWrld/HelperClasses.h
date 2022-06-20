#include "GameObject.h"
#include "enums.h"

class job {
public:
	GameObject* task = nullptr;
	GameObject* who = nullptr;
	JOBS type;
	bool isComplete = false;
	bool isNeed = false;
	int req = 0;
	int timeUntilComplete = 0;

	job(JOBS j, GameObject* task, int req, bool isNeed) {
		type = j;
		who = nullptr;
		this->task = task;
		this->req = req;
		this->isNeed = isNeed;
	}

	void jobAccepter(GameObject* who) {
		this->who = who;
	}

};

// handles all thing with need
class ActionNeeds {
public:
	ActionNeeds(){}

	void doAction(job j) {
		if (j.isNeed) {

			for (int i = 0; i < sizeof(j.task->needs);i++) {
				for (int x = 0; x < sizeof(j.who->needs);x++) {
					if (j.task->needs[i] == j.who->needs[x]){	// needs matching
						j.who->needMeters[x] += j.task->needMeters[x];	// does thing like drink
						break;
					}
				}
			}
			j.isComplete = true;
		} else{




		}
	}
};

class ActionOther {



};