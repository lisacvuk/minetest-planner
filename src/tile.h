#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

#include <SDL2/SDL.h>

class CTile{
public:
	CTile(int xpos, int ypos, SDL_Renderer* renderer);
	SDL_Rect get_rect();
	SDL_Texture* get_texture();
	~CTile();
private:
	SDL_Texture* texture;
	SDL_Rect rect;
};

#endif
