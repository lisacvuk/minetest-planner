#include "app.h"
#include <vector>
#include "tile.h"
#include <SDL2/SDL.h>
#include <iostream>

#define VIEWPORT_SIZE_X 200
#define VIEWPORT_SIZE_Y 200

CApp::CApp(){
	camera_rect.x = 0;
	camera_rect.y = 0;
	camera_rect.w = VIEWPORT_SIZE_X;
	camera_rect.h = VIEWPORT_SIZE_Y;

	start_drag_point.x = 0;
	start_drag_point.y = 0;

	camera = new CCamera();

	std::cout << "Starting..." << std::endl;
	running = true;
	dragging = false;
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Minetest planner", 0, 0, 800, 600, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	for(int i = 0; i < 10; i++){
	        CTile temp(i*32,0, renderer);
        	tiles.push_back(temp);
        }
	std::cout << SDL_GetError() << std::endl;
	while(running){
		SDL_Event event;
		input(event);
		loop();
		draw();
	}
}

void CApp::input(SDL_Event& event){
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:
				running = false;
				break;
			case SDL_MOUSEMOTION:
				mouse_pos.x = event.motion.x + camera->get_offset().x;
				mouse_pos.y = event.motion.y + camera->get_offset().y;
				//camera->set_pos(mouse_pos.x, mouse_pos.y);
				break;
			case SDL_MOUSEBUTTONDOWN:
				switch(event.button.button){
					case SDL_BUTTON_LEFT:
						std::cout << "Button down" << std::endl;
						break;
					case SDL_BUTTON_RIGHT:
						std::cout << "Other button down" << std::endl;
						start_drag_point.x = event.button.x + camera->get_offset().x;
						start_drag_point.y = event.button.y + camera->get_offset().y;
						dragging = true;
						break;
				}
				break;
			case SDL_MOUSEBUTTONUP:
				switch(event.button.button){
					case SDL_BUTTON_LEFT:
						break;
					case SDL_BUTTON_RIGHT:
						dragging = false;
						break;
				}
				break;
		}
	}
}

void CApp::draw(){
	SDL_RenderClear(renderer);
        for(int i = 0; i < tiles.size(); i++){
		SDL_Rect temp = tiles[i].get_rect();
		temp.x -= camera->get_rect().x;
		temp.y -= camera->get_rect().y;
		//std::cout << "temp.x=" << temp.x << "temp.y=" << temp.y << "tiles.x=" << tiles[i].get_rect()->x << "tiles.y=" << tiles[i].get_rect()->y << std::endl;
		//std::cout << "camera.x=" << camera->get_rect().x << "camera.y=" << camera->get_rect().y << std::endl;
		SDL_RenderCopy(renderer, tiles[i].get_texture(), NULL, &temp);
	}
	SDL_RenderPresent(renderer);
}
void CApp::loop(){
	SDL_Delay(20);
	if(dragging){
		int move_x = camera->get_pos().x + (start_drag_point.x - mouse_pos.x);
		int move_y = camera->get_pos().y + (start_drag_point.y - mouse_pos.y);
		std::cout << "STARTXDRAG=" << start_drag_point.x << " STARTYDRAG=" << start_drag_point.y << std::endl;
		std::cout << "MOUSEPOSX=" << mouse_pos.x << " MOUSEPOSY=" << mouse_pos.y << std::endl;
		std::cout << "MOVEX=" << move_x << " MOVEY=" << move_y << std::endl;
		std::cout << "STARTXDRAG-MOUSEPOSX=" << start_drag_point.x - mouse_pos.x << "STARTYDRAG-MOUSEPOSY=" << start_drag_point.y - mouse_pos.y << std::endl;
//                start_drag_point.x+= 0;
//                start_drag_point.y+= 0;
		if(move_x - camera->get_pos().x != 1 && move_y - camera->get_pos().y != 1){
			camera->move(move_x, move_y);
		}
	}
}
CApp::~CApp(){
}
