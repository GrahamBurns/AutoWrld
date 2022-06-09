#include "WrldGen.h"
#include "TextureManager.h"
#include <iostream>

int map[50][50];

WrldGen::WrldGen()
{
	dirt = TextureManager::loadTexture("assets/Kerg.png");
	grass = TextureManager::loadTexture("assets/derp.png");
	water = TextureManager::loadTexture("assets/derp.png");

	LoadMap();
	src.x = 0;
	src.y = 0;
	src.w = dest.w = 16;
	src.h = dest.h = 16;

	dest.x = dest.y = 0;
}

WrldGen::~WrldGen()
{
}

int arr[50][50];

void WrldGen::LoadMap()
{
	for (int row = 0; row < XSIZE; row++) {
		for (int column = 0; column < YSIZE; column++) {
			map[row][column] = arr[row][column];
		}
	}
}

void WrldGen::DrawMap(int xOffset, int yOffset)
{
	int type = 0;

	for (int row = 0; row < XSIZE; row++) {
		for (int column = 0; column < YSIZE; column++) {
			type = map[row][column];

			dest.x = ((column + xOffset)) * 16;
			dest.y = (row + yOffset) * 16;

			switch (type) {
			case 0:
					TextureManager::Draw(water, src, dest);
					break;
			case 1:
					TextureManager::Draw(dirt, src, dest);
					break;
			case 2:
					TextureManager::Draw(water, src, dest);
					break;
			}
		}
	}
}

int WrldGen::pathChecker(int x, int y)
{	
	return map[x][y];
}

void WrldGen::cleanTile(int x, int y,int id) {
	map[x][y] = 0; //is dirt for now
}

void WrldGen::placeInMap(int y, int x,int id) { //only thing that will need this is lesser updated things such as Chairs or walls 
	map[x][x] = id;
}
