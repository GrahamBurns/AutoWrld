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
	int chance = getrandNum(1, 2);
	int choice = getrandNum(1, 3);

	 int chanceWater = 1;
	 int chanceLand = 2;
	 int chanceSand = 5;
	 int chanceForRiver = 2;
	// int chanceTree = 1;

	 for (int x = 0;x < SIZE;x++) {
		 for (int y = 0;y < SIZE;y++) {
			heatMap[x][y] = 3;
		 }
	 }

	 if (choice != 0) {
		int x = getrandNum(0, SIZE);
		int y = getrandNum(0, SIZE);



		if (chance == 1) {
			chance = getrandNum(1, 2);
			if (chance == 1)
				x = 0;
			else
				x = SIZE;
		}
		else {
			chance = getrandNum(1, 2);
			if (chance == 1)
				y = 0;
			else
				y = SIZE;
		}

		int r = getrandNum(0, SIZE);	// row
		int c = getrandNum(0, SIZE);	// column


		if (chance == 1)
			r = 0;
		else
			c = 0;

		//heatMap[r][c] = 1;





		bool met = false;
		int moveX = 0;
		int moveY = 0;
		int riverSize = getrandNum(2, 2);
		while (!met) {
			heatMap;
			moveX = 0;
			moveY = 0;

			if (riverSize + 1 > 1) {
				if ((r - riverSize) > 0)
					if ((r + riverSize) < SIZE) {
						for (int i = (riverSize * -1);i < riverSize;i++) {
							heatMap[r + i][c] = 1;
						}
					}
			}

				if (x < c)
					moveX--;
				else if (x > c)
					moveX++;
				else
					moveX = moveX;

				if (y < r)
					moveY--;
				else if (y > r)
					moveY++;
				else
					moveY = moveY;


			r += moveY;
			c += moveX;

			//heatMap[r][c] = 1;

			if (x == c && y == r) {
				met = true;
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
