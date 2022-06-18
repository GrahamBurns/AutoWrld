#pragma once
#include <string>
#include <SDL/SDL_render.h>
#include <vector>
#include "GameObject.h"
class Renderer {
public:
	Renderer();
	void loadTextures(GameObject* thing);
	void render(GameObject* thing, int xOffset, int yOffset);

private:
	std::vector <SDL_Texture*> textures;
	std::vector <std::string> loadedTextures;

	// Intialize
	SDL_Rect srcRect;
	SDL_Rect destRect;

};