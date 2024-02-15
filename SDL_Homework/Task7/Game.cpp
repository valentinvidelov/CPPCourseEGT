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
				SDL_SetRenderDrawColor(renderer, 0xAA, 0xAA, 0xAA, 0xFF);

				SDL_Surface *tempSurface = SDL_LoadBMP("assets/bmp2.bmp");

				imTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
				SDL_FreeSurface(tempSurface); //removes temp surface from memory
				SDL_QueryTexture(imTexture, NULL, NULL, &sRect.w, &sRect.h);

				int ww, wh;
				SDL_GetWindowSize(window, &ww, &wh);

				sRect.x = sRect.y = dRect.x = dRect.y = 0;
				sRect.w = dRect.w = 184;
				sRect.h = dRect.h = 158;
				dRect.y = (wh - dRect.h)/2;
	// for (int xPosition = 0; xPosition <= (ww - 184); xPosition++){
	
				dRect.x = ww/2;
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
	// SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 255); // sets the window bg color needs to sit before SDL_RenderClear()
	SDL_RenderClear(renderer);  // clears renderer for new image
    // TextureManager::Instance()->drawTexture("bmp", 0, (wh/2)-79 , 184, 158, renderer, SDL_FLIP_NONE);
	SDL_RenderCopy(renderer, imTexture, &sRect, &dRect);
	
	// SDL_RenderPresent(renderer); // displays renderer
    // SDL_Rect fillRect = {ww / 4, wh / 4, ww / 2, wh / 2};
	// SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	// SDL_RenderFillRect(renderer, &fillRect);

	// SDL_Rect outlineRect = { ww / 6, wh / 6, ww * 2 / 3, wh * 2 / 3 };
	// SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
	// SDL_RenderDrawRect(renderer, &outlineRect);

	// // animates the sprite sheet with the help of the update() function
	// TextureManager::Instance()->drawOneFrameFromTexture("sprite_sheet", 0, 0, 60, 70, 1, currentFrame, renderer);

	// // NOTICE: the textures rendered later overlap the previosly rendered textures

	SDL_RenderPresent(renderer);
}

void Game::handleEvents() {

    int ww, wh;
    SDL_GetWindowSize(window, &ww, &wh); 
    int xVelocity = 1;
    int xPosition = 0;
    int yPosition = (wh/2)-79;

    SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT: running = false; break;
            case SDL_KEYDOWN:{

				if (event.key.keysym.sym == SDLK_RIGHT){
					dRect.x+=4;
					if (dRect.x + dRect.w>= ww){
						dRect.x = ww - dRect.w;
					}
				}
				if (event.key.keysym.sym == SDLK_LEFT){
					dRect.x-=4;
					if (dRect.x <=0 ){
						dRect.x = 0;
					}
				}
				if (event.key.keysym.sym == SDLK_UP){
					dRect.y-=4;
					if (dRect.y <= 0){
						dRect.y = 0;
					}
				}
				if (event.key.keysym.sym == SDLK_DOWN){
					dRect.y+=4;
					if (dRect.y + dRect.h >= wh){
						dRect.y = wh-dRect.h;
					}
				}
                if(event.key.keysym.sym == SDLK_SPACE){
                    std::cout << "spacebar detected\n";
        //             for (xPosition = 0; xPosition <= (ww - 184); xPosition+=xVelocity){
        //                dRect.x += xVelocity;
		// 			//    SDL_Delay(200);
        // // SDL_Delay(200);
        //             }
                }
                break;}

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
	
	int ww, wh;
    SDL_GetWindowSize(window, &ww, &wh); 
	

	// dRect.x += xVelocity;
	// if (dRect.x + dRect.w>= ww){
	// 	step+=0.5;
	// 	// BONUS speeding up once it hits edges
	// 	xVelocity *= -step;
		
	// }
	// if (dRect.x <=0 ){
	// 	step+=0.5;
	// 	xVelocity *= -step;
		
	// }
		// SDL_Delay(200);
		// std::cout << xPosition << std::endl;
	//    SDL_Delay(200);
// SDL_Delay(200);
	// }
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