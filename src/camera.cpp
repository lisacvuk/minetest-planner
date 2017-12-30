#include "camera.h"

CCamera::CCamera(){
	pos.x = 0;
	pos.y = 0;
	viewport.x = 800;
	viewport.y = 600;
	update_rect();
}
bool CCamera::inside_camera(SDL_Rect rect){
	return SDL_HasIntersection(&rect, &camera_rect);
}
void CCamera::move(int x, int y){
	pos.x = x;
	pos.y = y;
	update_rect();
}

SDL_Point CCamera::get_pos(){
	return pos;
}

SDL_Rect CCamera::get_rect(){
	return camera_rect;
}
SDL_Point CCamera::get_offset(){
	SDL_Point temp;
	temp.x = camera_rect.x;
	temp.y = camera_rect.y;
	return SDL_Point(temp);
}
void CCamera::update_rect(){
	camera_rect.x = pos.x - (viewport.x / 2);
	camera_rect.y = pos.y - (viewport.y / 2);
	camera_rect.w = viewport.x;
	camera_rect.h = viewport.y;
}
