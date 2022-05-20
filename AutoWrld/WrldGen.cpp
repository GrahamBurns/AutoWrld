#include "WrldGen.h"
#include "WrldLoop.h"
#include <fstream>
#include "ECS.h"
#include "Components.h"

extern Manager manager;
// texID is a string that  pass it in eventually not outside

WrldGen::WrldGen(std::string tID, int ms, int ts) : texID(tID),  mapScale(ms), tileSize(ts)
{
	scaledSize = ms * ts;
}

WrldGen::~WrldGen()
{
}

void WrldGen::GenWrld()
{
	std::string filename("output.txt");
	std::fstream output_fstream;

	output_fstream.open(filename, std::ios_base::out);
	if (!output_fstream.is_open()) {
		std::cerr << "Failed to open " << filename << '\n';
	}
	
	srand(time(NULL));
	int y = 10;
	for (int i = 0; i < 100;i++) {
		int n = rand() % 5 + 1;
		if (y == 10) {
			output_fstream << std::endl;
			y = 0;
		}
		else {
			output_fstream << n;
		}
		y++;
	}
	std::cerr << "Done Writing!" << std::endl;

}

void WrldGen::LoadMap(std::string path, int sizeX, int sizeY)
{
	char c;
	std::fstream WrldGenFile;
	WrldGenFile.open(path);

	int srcX = 32, srcY = 32;
	AddTile(srcX, srcY, 10 * scaledSize, 10 * scaledSize);
	auto& tcol(manager.addEntity());
	//says what it is 
	tcol.addComponent<ColliderComponent>("terrain", 100 * scaledSize, 100 * scaledSize, scaledSize);
	tcol.addGroup(WrldLoop::groupColliders);

	/*
	for (int y = 0; y < sizeY; y++) // wont need it just determines world size and tile size
	{
		for (int x = 0; x < sizeX; x++)
		{
			WrldGenFile.get(c);				//gets line to find 
			srcY = atoi(&c) * tileSize;
			WrldGenFile.get(c);
			srcX = atoi(&c) * tileSize;
			AddTile(srcX, srcY, x * scaledSize, y * scaledSize);
			WrldGenFile.ignore();
		}
	}

	WrldGenFile.ignore();
	*/
	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			WrldGenFile.get(c);
			if (c == '1')
			{

				// generate no go collider
				auto& tcol(manager.addEntity());
				//says what it is 
				tcol.addComponent<ColliderComponent>("terrain", x * scaledSize, y * scaledSize, scaledSize);
				tcol.addGroup(WrldLoop::groupColliders);
			}
			WrldGenFile.ignore();
		}
	}
	WrldGenFile.close();
}

void WrldGen::AddTile(int srcX, int srcY, int xpos, int ypos)
{
	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(srcX, srcY, xpos, ypos, tileSize, mapScale, texID);
	tile.addGroup(WrldLoop::groupMap);
}