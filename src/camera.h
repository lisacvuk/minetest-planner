#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include <SDL2/SDL.h>

class CCamera{
public:
	CCamera();
	SDL_Point get_pos();
	SDL_Point get_offset();
	SDL_Rect get_rect();
	void move(int x, int y);
	bool inside_camera(SDL_Rect rect);
private:
	void update_rect();
	SDL_Point pos;
	SDL_Point viewport;
	SDL_Rect camera_rect;
};

#endif
