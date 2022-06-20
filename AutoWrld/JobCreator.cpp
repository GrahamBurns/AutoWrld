#include "JobCreator.h"


JobCreator::JobCreator()
{
}

void JobCreator::createJob(JOBS j, GameObject* task)
{
}

void JobCreator::assignJob(GameObject* person)	// already checked to see if they need it
{
	bool foundJob = false;
	for (int i = 0; i < JobList.size();i++) {
		
		//check if the job is available
		if (JobList[i].who == nullptr) {
			//check if they can do the job
			for (int x = 0; x < sizeof(person->tasks); x++) {
				if (JobList[i].type == person->tasks[x] && JobList[i].req == person->actualSkills[JobList[i].type]) {
					JobList[i].who = person; // assign it
					foundJob = true;
				}
			}
		}
	}

	if (!foundJob) {
		// some premade job like idle or something
		// then set job to idle and if they are idle in the needs it will have them do something
	}
}

void JobCreator::completeJob()
{
	for (int i = 0; i < JobList.size();i++) {
		if (JobList[1].timeUntilComplete == 0) {
			JobList[1].isComplete = true;
		}
	}
}

void JobCreator::removeJob() {
	
}
