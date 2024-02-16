/* 
Напишете функция която рисува празен правоъгълник с подадена дебелина 
на линиите. (ПОЯСНЕНИЕ: може да стане с помощта 2 запълнени правоъгълника);
*/

#include <iostream>
#include "SDL2/SDL.h"
using namespace std;


int main();

bool init();
void handleEvents();
void render();
void close();
void drawRectangle(int width, int height, int thickness);
const SDL_Rect* drawInnerRectangle(int width, int height);
const SDL_Rect* drawOuterRectangle(int width, int height, int thickness);
bool isRunning;

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;
SDL_Rect rect1, rect2;
SDL_Renderer* renderer = NULL;

int main(){
    int ww, wh, rw, rh, thickness;
    drawRectangle(10,20,5);
    SDL_Rect rectangle= {ww/2, wh/2, rw, rh};
    isRunning = true;
    init();
    SDL_GetWindowSize(gWindow, &ww, &wh);
    while (isRunning){
        
        handleEvents();
        render();
        // SDL_UpdateWindowSurface(gWindow);
        
    }

    close();
    return 0;
}
bool init()
{
    bool success = true; //initialization flag
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0 ){
        cout << "SDL could not initialize!" << endl;
        success = false;
    } else {
        //create window
        gWindow = SDL_CreateWindow("SDL Task6", 
                                            SDL_WINDOWPOS_CENTERED,
                                            SDL_WINDOWPOS_CENTERED,
                                            1200, 600, 
                                            SDL_WINDOW_RESIZABLE);
        if (gWindow == NULL){
            cout << "Window could not be created!" << endl;
            success = false;
            
        } else {
            renderer = SDL_CreateRenderer(gWindow, -1, 0);
            if (renderer != 0) //renderer init success
            {
            
           
            SDL_SetRenderDrawColor(renderer, 0xAA, 0xAA, 0xAA, 0xFF);
            gScreenSurface = SDL_GetWindowSurface( gWindow );
            } else {
				std::cout << "renderer init failed\n";
				return false;
			}

            }
    }
    return success;
}
void render(){
    SDL_RenderClear(renderer);
    
    
    
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    drawRectangle(200, 100, 50);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_SetRenderDrawColor(renderer, 255,255, 0, 255);
    SDL_RenderDrawLine(renderer, 3 , 5 , 200, 5);
    SDL_SetRenderDrawColor(renderer, 0,0, 0, 255);
    SDL_RenderPresent(renderer);
    
}

void handleEvents()
{

    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
		switch (event.type) {
			case SDL_QUIT: isRunning = false; break;
			default: break;
		}
	}
}

void drawRectangle(int width, int height, int thickness)
{
    int ww, wh;
    SDL_GetWindowSize(gWindow, &ww, &wh);
    // SDL_Color col = {255,255,0,255};
    // Uint32 col= {};
    // const SDL_Rect *oRect, *iRect;
    // iRect = drawInnerRectangle(width, height);
    // oRect = drawOuterRectangle(width, height, thickness);
    // SDL_RenderDrawRect(renderer, oRect);
    // SDL_RenderDrawRect(renderer, iRect );
    // SDL_FillRect(NULL, iRect, col);
    SDL_Rect outlineRect = { ww / 6, wh / 6, ww * 2 / 3, wh * 2 / 3 };
	SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
	// SDL_RenderDrawRect(renderer, &outlineRect);
	SDL_RenderFillRect(renderer, &outlineRect);

	SDL_Rect fillRect = {ww / 4, wh / 4, ww / 2, wh / 2};
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(renderer, &fillRect);
    
}
const SDL_Rect* drawOuterRectangle(int width, int height, int thickness) 
{
    int ww, wh;
    SDL_GetWindowSize(gWindow, &ww, &wh);
    SDL_Rect* oRect;

    oRect->x = ww/2 - thickness/2;
    oRect->y = wh/2 - thickness/2;
    oRect->w = width + thickness;
    oRect->h = height + thickness;

    return oRect;
}

const SDL_Rect* drawInnerRectangle(int width, int height)
{
    int ww, wh;
    SDL_GetWindowSize(gWindow, &ww, &wh);
    SDL_Rect *iRect;
  
    //inner rect
    iRect->x = ww/2;  
    iRect->y = wh/2;
    iRect->w = width;
    iRect->h = height;

    return iRect;

}

void close()
{
    
    SDL_FreeSurface(gHelloWorld); // frees surface / deallocates
    gHelloWorld = NULL;
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow( gWindow );  //destroys window
    gWindow = NULL;  //GET in habit of always NULLing pointers. you avoid undefined behavior
    
 
    SDL_Quit();
}