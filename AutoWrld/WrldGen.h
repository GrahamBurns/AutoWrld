#pragma once
#include "WrldLoop.h"
#include "GameObject.h"
#include <string>

class WrldGen
{
public:
	WrldGen();
	~WrldGen();

	void LoadMap();
	void DrawMap(int xOffset,int yOffset);
	void cleanTile(int x, int y, int id);
	void placeInMap(int y, int x,int id);
	int pathChecker(int x, int y);
	
private:

	SDL_Rect src, dest;

	static const int XSIZE = 50;
	static const int YSIZE = 50;

	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;
	int _worldY = 0;
	int _worldX = 0;
};

