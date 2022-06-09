#pragma once
#include <fstream>


class AutoGen {
public:
	AutoGen();
	~AutoGen();

	int getrandNum(int low, int high);

	int surroundingChecker(int x, int y,int Pref);

	void generateWrld();
	void saveWrld();



private:
	std::ofstream file;
	std::string filePath = "assets/Map.txt";
};