#pragma once
#include "enums.h"
#include "GameObject.h"
#include "HelperClasses.h"

class JobCreator {
public:
	JobCreator();

	void createJob(JOBS j,GameObject* task);
	void assignJob(GameObject* person);
	void completeJob();

	void removeJob();


	std::vector<job> JobList;
	std::vector<job> CompletedJobList;
		// to remove job vector name.erase(i);
};

