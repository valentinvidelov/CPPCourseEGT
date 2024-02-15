//Game.cpp
#include "Game.h"
#include <iostream>

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) {

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL init success\n";

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window != 0) //window init success
		{
			std::cout << "window creation success\n";
			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer != 0) //renderer init success
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

				// use the TextureManager to load textures
				TextureManager::Instance()->loadTexture("assets/bmp2.bmp", "bmp", renderer);
				// TextureManager::Instance()->loadTexture("assets/sprite_sheet_mm_tp.png", "sprite_sheet", renderer);
				TextureManager::Instance()->loadTexture("assets/sprite_sheet_mm.png", "sprite_sheet", renderer);

			}
			else {
				std::cout << "renderer init failed\n";
				return false;
			}
		}
		else {
			std::cout << "window init failed\n";
			return false;
		}
	}
	else {
		std::cout << "SDL init fail\n";
		return false;
	}
	std::cout << "init success\n";
	running = true;
	return true;
}

void Game::render() {
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 255); // sets the window bg color needs to sit before SDL_RenderClear()
	SDL_RenderClear(renderer);
	// TextureManager::Instance()->drawTexture("bmp", 0, 0, 184, 158, renderer, SDL_FLIP_VERTICAL);

	int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh); // assigns the window's width and height to ww and wh

	// animates the sprite sheet with the help of the update() function
	// if ((currentFrame == 4) && (currentRow == 1)){
	// 	currentRow++;
	// } else if ((currentFrame == 4) && (currentRow == 2)){
	// 	currentRow--;
	// }
	currentRow = 1;
	TextureManager::Instance()->drawOneFrameFromTexture("sprite_sheet", ww/2, wh/2, 60, 70, currentRow, currentFrame, renderer);
	std::cout << "frame: "<<currentFrame << std::endl;
	std::cout << "row: " << currentRow << std::endl;
	// NOTICE: the textures rendered later overlap the previosly rendered textures

	SDL_RenderPresent(renderer);
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT: running = false; break;
			default: break;
		}
	}
}

void Game::update() {
	
	//Logs the different stages of 'currentFrame' formula,
	//if you have trouble understanding how it works try uncommenting the couts and study the output 
	//std::cout << "SDL_TICKS           :" << SDL_GetTicks() << "\n";
	//std::cout << "SDL_TICKS / 100     :" << int(SDL_GetTicks() / 100) << "\n";
	//std::cout << "SDL_TICKS / 100 % 10:" << int(((SDL_GetTicks() / 100) % 10)) << "\n\n";
	

	int numberOfFramesInSpriteSheet = 5;
	int numberOfRows = 2;
	int animationSpeed = 100; // lower is faster, min = 1
	currentFrame = int(((SDL_GetTicks() / animationSpeed) % numberOfFramesInSpriteSheet));
	// currentRow = int(((SDL_GetTicks() / animationSpeed) % numberOfRows))+1;
}

void Game::clean() {
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool Game::isRunning() {
	return Game::running;
}

Game::Game() {
	Game::window = NULL;
	Game::renderer = NULL;
	Game::running = true;
	Game::currentFrame = 0;
}

Game::~Game() {

}