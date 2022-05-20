#pragma once
#include <string>

class WrldGen
{
public:

	WrldGen(std::string tID, int ms, int ts);
	~WrldGen();

	void GenWrld();
	void LoadMap(std::string path, int sizeX, int sizeY);
	void AddTile(int srcX, int srcY, int xpos, int ypos);

private:
	std::string texID;
	int mapScale;
	int tileSize;
	int scaledSize;

};
