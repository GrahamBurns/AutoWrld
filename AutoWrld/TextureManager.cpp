#include "TextureManager.h"

SDL_Texture* TextureManager::loadTexture(const char* filename)
{
    SDL_Surface* tempSurface = IMG_Load(filename);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(WrldLoop::renderer,tempSurface);
    SDL_FreeSurface(tempSurface);


    return tex;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src ,SDL_Rect dest)
{
    SDL_RenderCopy(WrldLoop::renderer, tex, &src,  &dest);
}
