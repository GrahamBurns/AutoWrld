#include <ctime>
#include "AutoGen.h"
#include <iostream>

const int SIZE = 50;

int heatMap[SIZE][SIZE];
char water = '~';
char tree =  'O';
char sand =  '#';
char land = '.';



AutoGen::AutoGen()
{
	srand((unsigned)time(0));
}

AutoGen::~AutoGen()
{
}

int AutoGen::getrandNum(int low, int high)
{
	
	return low + (rand() % high);
}

int AutoGen::surroundingChecker(int x , int y,int pref) {

	int thing = heatMap[x][y];
	int bonus = 0;
	int chance = 0;

	for (int i = -1; i < 1; i++) {
		for (int j = -1; j < 1;j++) {
			if(i > 0 && i < SIZE)
				if (j > 0 && j < SIZE) {
					if (thing == heatMap[i][j])
						chance++;
					if (pref == heatMap[i][j])
						bonus++;
				}
		}

	}
	if (bonus == 0)
		return chance;
	
	return chance + (bonus / 2);

}

void AutoGen::generateWrld()
{
	int chance;
	int choice = getrandNum(1, 3);

	 heatMap[0][0] = choice;
	 int chanceWater = 1;
	 int chanceLand = 2;
	 int chanceSand = 5;
	 int chanceForRiver = 2;
	// int chanceTree = 1;

	 for (int x = 0;x < SIZE;x++) {
		 int del = 2;
		 for (int y = 0;y < SIZE;y++) {
			 choice = getrandNum(1, 3);

				 if (choice == 1) {
					 chance = surroundingChecker(x, y - 1, 2);
					 choice = getrandNum(1, chanceWater - chance);		// WATER

					 if (choice < 2) {
						 heatMap[x][y] = 1;
					 }
					 else {
						 heatMap[x][y] = 2;
						 chanceWater = 1;
					 }
				 }
				 else if (choice == 2) {						//SAND
					 chance = surroundingChecker(x, y - 1, 1);
					 choice = getrandNum(1, chanceSand - chance);

					 if (choice == 1) {
						 heatMap[x][y] = 2;
					 }
					 else {
						 heatMap[x][y] = 3;
						 chanceSand = 5;
					 }

				 }
				 else if (choice == 3) {						//LAND
					 chance = surroundingChecker(x, y - 1,2);
					 choice = getrandNum(1, chanceLand - chance);

					 if (choice < 3) {
						 heatMap[x][y] = 3;
					 }
					 else {
						 heatMap[x][y] = 1;
						 chanceLand = 1;
					 }

				 }
		 }
	 }
	 saveWrld();
}

void AutoGen::saveWrld() {
	file.open(filePath);

	for (int x = 0;x < SIZE;x++) {
		for (int y = 0; y < SIZE;y++) {
			switch (heatMap[x][y])
			{
			case 1:
				file << water;
				break;
			case 2:
				file << sand;
				break;
			case 3:
				file << land;
				break;
			}
		}
		file << std::endl;
	}
	std::cout << "FILE SAVED";
}
