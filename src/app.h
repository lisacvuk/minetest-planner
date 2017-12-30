#ifndef CAPP_H_INCLUDED
#define CAPP_H_INCLUDED

#include "tile.h"
#include <vector>
#include <SDL2/SDL.h>
#include "camera.h"

class CApp{
public:
	CApp();
	~CApp();
	void draw();
	void loop();
	void input(SDL_Event &event);
private:
	bool running;
	bool dragging;
	SDL_Point start_drag_point;
	SDL_Point mouse_pos;
	CCamera* camera;
	SDL_Rect camera_rect;
	std::vector<CTile> tiles;
	SDL_Window* window;
	SDL_Renderer* renderer;
};

#endif
