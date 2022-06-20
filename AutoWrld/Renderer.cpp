#include "Renderer.h"
#include "TextureManager.h"

Renderer::Renderer()
{
	textures.reserve(15);
	loadedTextures.reserve(15);
	srcRect.h = 16;
	srcRect.w = 16;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
}

void Renderer::loadTextures(GameObject* thing)
{
	bool foundTex = false;
	for (int i = 0; i < loadedTextures.size();i++) {
		if (thing->texturePath == loadedTextures[i]) {
			foundTex = true;
			thing->loadCode = i;
		}
	}
	if (!foundTex) {
		textures.push_back(TextureManager::loadTexture(thing->texturePath.c_str()));
		loadedTextures.push_back(thing->texturePath);
		thing->loadCode = loadedTextures.size() - 1;
	}
}

void Renderer::render(GameObject* thing,int xOffset,int yOffset)
{
	destRect.x = (thing->getX() + xOffset) * 16;
	destRect.y = (thing->getY() + yOffset) * 16;


	TextureManager::Draw(textures[thing->loadCode], srcRect, destRect);
}

void Renderer::loadTexturesVehicle(VehicleObject* thing)
{
	bool foundTex = false;

	for (int x = 0; x < thing->vehicle.size();x++) {
		for (int i = 0; i < loadedTextures.size() ;i++) {
			if (thing->vehicle[x]->texturePath == loadedTextures[i]) {
				foundTex = true;
				thing->vehicle[x]->loadCode = i;
			}
		}
		if (!foundTex) {
			textures.push_back(TextureManager::loadTexture(thing->vehicle[x]->texturePath.c_str()));
			loadedTextures.push_back(thing->vehicle[x]->texturePath);
			thing->vehicle[x]->loadCode = loadedTextures.size() - 1;
		}
	}
}

void Renderer::renderVehicle(VehicleObject* thing, int xOffset, int yOffset)
{

	for (int x = 0; x < thing->vehicle.size();x++) {

		destRect.x = (thing->vehicle[x]->xpos + xOffset) * 16;
		destRect.y = (thing->vehicle[x]->ypos + yOffset) * 16;

		TextureManager::Draw(textures[thing->vehicle[x]->loadCode], srcRect, destRect);
	}


}