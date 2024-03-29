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


	int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh); // assigns the window's width and height to ww and wh

	// SDL_Rect fillRect = {ww / 4, wh / 4, ww / 2, wh / 2};
	// SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	// SDL_RenderFillRect(renderer, &fillRect);

	// SDL_Rect outlineRect = { ww / 6, wh / 6, ww * 2 / 3, wh * 2 / 3 };
	// SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
	// SDL_RenderDrawRect(renderer, &outlineRect);

	// SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
	// SDL_RenderDrawLine(renderer, 0, wh / 2, ww, wh / 2);

	// SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF); // renders dashed line
	// for (int i = 0; i < wh; i += 4) {
	// 	SDL_RenderDrawPoint(renderer, ww / 2, i);
	// }



	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);
	Shapes::drawCircle(renderer, ww / 2, wh / 2, wh / 2 - 5);

    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);  //yellow
	SDL_RenderDrawLine(renderer, ww/2, 0, ww/2, wh); //vertical line
    SDL_RenderDrawLine(renderer, 0, wh/2, ww, wh/2); //horizontal line

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderDrawPoint(renderer, ww / 2, wh / 2);
    
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);
    Shapes::drawPentagon(renderer, ww / 2, wh / 2, 100);

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	Shapes::drawHexagon(renderer, ww/2, wh/2, 300);

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
	

	int numberOfFramesInSpriteSheet = 10;
	int animationSpeed = 100; // lower is faster, min = 1
	currentFrame = int(((SDL_GetTicks() / animationSpeed) % numberOfFramesInSpriteSheet));
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