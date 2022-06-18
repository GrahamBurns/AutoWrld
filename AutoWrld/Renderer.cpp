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
