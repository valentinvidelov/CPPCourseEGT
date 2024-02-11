//Game.h
#pragma once

#include "SDL2/SDL.h"



class Game {
public:
	Game();
	~Game();
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	bool im_init();
	void render();
	void update();
	void handleEvents();
	void clean();
	bool isRunning();
private:
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	bool running;
	int currentFrame;
	double step = 1; // for speeding up
	int xVelocity = 1;
	SDL_Rect sRect, dRect;
	SDL_Texture *imTexture;
};