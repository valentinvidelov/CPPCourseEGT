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
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //bg color
	SDL_RenderClear(renderer);
   //renders fonts
    int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh);   // set window width and height vars
    
    SDL_SetRenderDrawColor(renderer, 0, 204, 204, 255); //split screen into 4 quadrants as per task 5, use this blue
    SDL_RenderDrawLine(renderer, ww/2, 0, ww/2, wh);
    SDL_RenderDrawLine(renderer, 0, wh/2, ww, wh/2);


   

	SDL_RenderPresent(renderer);
}



void Game::handleEvents() {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT: running = false; break;
        case SDL_MOUSEBUTTONDOWN:{
            std::cout << "Mouse button down detected \n";
            int msx, msy;
            if (event.button.button == SDL_BUTTON_LEFT){
                std::cout << "left button down\n";
                // SDL_GetMouseState(&msdx, &msdy);
                SDL_GetMouseState(&msx, &msy);
                msdx = msx;
                msdy = msy;
                // std::cout << msx << ", " << msy << std::endl;
            }
            break;
        }
        case SDL_MOUSEBUTTONUP:{
            int msx, msy;
            std::cout << "Mouse button released\n"; 
            if (event.button.button == SDL_BUTTON_LEFT){
                // std::cout << "left button down\n";
                SDL_GetMouseState(&msx, &msy);
                std::cout << msx << ", " << msy << std::endl;
                std::cout << (isClickableTextureClicked(clickableTexture, &sRect,
                                                         msdx, msdy, msx, msy) ? "CLICKED\n" : "not clicked\n");
            }
            if (event.button.button = SDL_BUTTON_RIGHT){
                std::cout << "right button up\n";
                SDL_GetMouseState(&msx, &msy);
                std::cout << msx << ", " << msy << std::endl;
            }
        }
        case SDL_KEYDOWN:{
            if (event.key.keysym.sym == SDLK_RIGHT){
                std::cout << "right arrow key down detected\n";
                
            }
            if (event.key.keysym.sym == SDLK_LEFT){
                std::cout << "left arrow key down detected\n";
                
            }          
            if (event.key.keysym.sym == SDLK_UP){
                std::cout << "up arrow key down detected\n";
                
            }
            if (event.key.keysym.sym == SDLK_DOWN){
                std::cout << "down arrow key down detected\n";
                
            }
            if (event.key.keysym.sym == SDLK_ESCAPE){
                running = false;
            }
            break;
        }
        case SDL_KEYUP:{


            break;
        }
        case SDL_MOUSEMOTION:{
                // std::cout << event.motion.x << ", " << event.motion.y << std::endl;  //prints mouse coords x, y
                // dRectFont2.x = event.motion.x - dRectFont2.w/2;  //moves dRectfont2 following the mouse
                // dRectFont2.y = event.motion.y - dRectFont2.h/2;
            break;
        }
		default: break;
		}
	}
}

void Game::update() {

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

bool Game::isClickableTextureClicked(SDL_Texture *t, SDL_Rect *r, int xDown, int yDown, int xUp, int yUp)
{
    int tw, th;
    SDL_QueryTexture(t, 0, 0, &tw, &th);
    // (r->x) (r->x + tw)
    // (r->y) (r->y + th)

    if ((xDown > r->x && xDown < (r->x + tw)) && (xUp > r->x && xUp < (r->x + tw))&&  //clicking coords within textureRect?
    (yDown > r->y && yDown < (r->y + th)) && (yUp > r->y && yUp < (r->y + th))) {
        // std::cout << "Clicked\n" ;
        return true;
    }
    return false;
}

Game::Game() {
	Game::window = NULL;
	Game::renderer = NULL;
	Game::running = true;
}

Game::~Game() {
	delete window;
	delete renderer;
}