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

                // SDL_Surface *tempSurface = IMG_Load("assets/1.jpg");
                // q1Texture = SDL_CreateTextureFromSurface(renderer, tempSurface);

                // SDL_FreeSurface(tempSurface);

                TextureManager::Instance()->loadTexture("assets/1.jpg","q1", renderer);  //needed pre-resizing unless you tweak texture manager
                TextureManager::Instance()->loadTexture("assets/2.jpg","q2", renderer); 
                TextureManager::Instance()->loadTexture("assets/3.jpg","q3", renderer); 
                TextureManager::Instance()->loadTexture("assets/4.jpeg","q4", renderer); 
                // int ww, wh;
	            // SDL_GetWindowSize(window, &ww, &wh); 

                // SDL_QueryTexture(q1Texture, NULL, NULL, &q1Rect.w, &q1Rect.h);

                // q1Rect.x = dRect.x = ww/2;
                // q1Rect.y = dRect.y = 0;
				// dRect.w = ww/2;
			    // dRect.h = wh/2;
                // SDL_QueryTexture(q1Texture, NULL, NULL, &sRect.w, &sRect.h);
                // sRect.x = q1Rect.x = ww/2;
                // sRect.y = q1Rect.y = 0;
                // q1Rect.w = ww/2;
                // q1Rect.h = wh/2;
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

bool Game::ttf_init()
{
    if (TTF_Init() == -1) {
        return false;
    }  

    TTF_Font *font1 = TTF_OpenFont("assets/fonts/Arcade.ttf", 48);
    TTF_Font *font2 = TTF_OpenFont("assets/fonts/segoepr.ttf", 72);

    if (font1 == NULL || font2 == NULL){
        return false;
    }

/*     SDL_Surface* tempSurfaceText = NULL;

    tempSurfaceText = TTF_RenderText_Blended(font1, "Hello TTF", {255,0,0,255});
    textTextureFont1 = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);
    tempSurfaceText = TTF_RenderText_Blended(font2, "Hello TTF2", {0,255,0,255});
    textTextureFont2 = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

    tempSurfaceText = TTF_RenderText_Blended_Wrapped(font1, "Hello TTF,\n this be a text wrapper mon", {255,0,0,255}, 300); // wrapped prevents text from leaving screen, goes to next line
    textTextureFont1Wrapped = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

    tempSurfaceText = TTF_RenderText_Blended_Wrapped(font2, "Hello TTF2\n this be another wrapper mon", {0,255,0,255}, 500); // 500 is pixel count something
    textTextureFont2Wrapped = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

    tempSurfaceText = TTF_RenderText_Blended(font1, "CLICK", {255,255,0,255});
    clickableTexture = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);


    int tw;
    int th;
    SDL_QueryTexture(textTextureFont1, 0, 0, &tw, &th);
    dRectFont1 = {10, 10, tw, th};
    SDL_QueryTexture(textTextureFont2, 0, 0, &tw, &th);
    dRectFont2 = {10, 320, tw, th};
    SDL_QueryTexture(textTextureFont1Wrapped, 0, 0, &tw, &th);
    dRectFont1Wrapped = {650, 10, tw, th};
    SDL_QueryTexture(textTextureFont2Wrapped, 0, 0, &tw, &th);
    dRectFont2Wrapped = {650, 320, tw, th};

    SDL_QueryTexture(clickableTexture, 0, 0, &tw, &th);
    int ww, wh;
    SDL_GetWindowSize(window, &ww, &wh);
    clickableRect = {(ww-tw)/2, (wh-th)/2, tw, th};

    SDL_FreeSurface(tempSurfaceText);
    TTF_CloseFont(font1);
    TTF_CloseFont(font2);
 */
    return true;
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //bg color
	SDL_RenderClear(renderer);
   //renders fonts
    int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh);   // set window width and height vars
    
    //draw these on click
    TextureManager::Instance()->drawTexture("q1", ww/2, 0, ww/2, wh/2, renderer, SDL_FLIP_NONE); //drawTexture, x, y, width, height
    TextureManager::Instance()->drawTexture("q2", 0, 0, ww/2, wh/2, renderer, SDL_FLIP_NONE);
    TextureManager::Instance()->drawTexture("q3", 0, wh/2, ww/2, wh/2, renderer, SDL_FLIP_NONE);
    TextureManager::Instance()->drawTexture("q4", ww/2, wh/2, ww/2, wh/2, renderer, SDL_FLIP_NONE);
    // SDL_RenderCopy(renderer, q1Texture, &q1Rect, &dRect);
    // SDL_RenderCopy(renderer, q1Texture, &sRect, &q1Rect);
 
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
            // std::cout << "Mouse button down detected \n";
            int msx, msy;
            if (event.button.button == SDL_BUTTON_LEFT){
                // std::cout << "left button down\n";
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
            // std::cout << "Mouse button released\n"; 
            if (event.button.button == SDL_BUTTON_LEFT){
                // std::cout << "left button down\n";
                SDL_GetMouseState(&msx, &msy);
                // std::cout << msx << ", " << msy << std::endl;
                // std::cout << (isClickableTextureClicked(clickableTexture, &sRect,
                //                                          msdx, msdy, msx, msy) ? "CLICKED\n" : "not clicked\n");
                quadrantClicked(msdx, msdy, msx, msy);  //on release, pass the click and release vars to func
            }
            if (event.button.button = SDL_BUTTON_RIGHT){
                // std::cout << "right button up\n";
                SDL_GetMouseState(&msx, &msy);
                // std::cout << msx << ", " << msy << std::endl;
            }
        }
        case SDL_KEYDOWN:{
            if (event.key.keysym.sym == SDLK_RIGHT){
                std::cout << "right arrow key down detected\n";
                TextureManager::Instance()->toggleVisibility("q1");
                TextureManager::Instance()->toggleVisibility("q4");

            }
            if (event.key.keysym.sym == SDLK_LEFT){
                std::cout << "left arrow key down detected\n";
                TextureManager::Instance()->toggleVisibility("q2");
                TextureManager::Instance()->toggleVisibility("q3");
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

// check which quadrant the mouse is clicked and released, return 
void Game::quadrantClicked(int xDown, int yDown, int xUp, int yUp)
{
    int ww, wh;
    SDL_GetWindowSize(window, &ww, &wh);
    if ((xDown > ww/2 && yDown < wh/2) && (xUp > ww/2 && yUp < wh/2)){
        TextureManager::Instance()->toggleVisibility("q1");
        cout << "q1" << endl;
    }
    if ((xDown < ww/2 && yDown < wh/2) && (xUp < ww/2 && yUp < wh/2)){
        TextureManager::Instance()->toggleVisibility("q2");
        cout << "q2" << endl;
    }
    if ((xDown < ww/2 && yDown > wh/2) && (xUp < ww/2 && yUp > wh/2)){
        TextureManager::Instance()->toggleVisibility("q3");
        cout << "q3" << endl;
    }
    if ((xDown > ww/2 && yDown > wh/2) && (xUp > ww/2 && yUp > wh/2)){
        TextureManager::Instance()->toggleVisibility("q4");
        cout << "q4" << endl;
    }
    
    
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