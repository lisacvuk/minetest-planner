#include "tile.h"
#include <SDL2/SDL.h>

#define TILE_HEIGHT 32
#define TILE_WIDTH 32

CTile::CTile(int xpos, int ypos, SDL_Renderer* renderer){
	rect.x = xpos;
	rect.y = ypos;
	rect.w = TILE_WIDTH;
	rect.h = TILE_HEIGHT;
	SDL_Surface* temp = SDL_LoadBMP("test.bmp");
	texture = SDL_CreateTextureFromSurface(renderer, temp);
}
SDL_Rect CTile::get_rect(){
	return rect;
}

SDL_Texture* CTile::get_texture(){
	return texture;
}

CTile::~CTile(){
}
