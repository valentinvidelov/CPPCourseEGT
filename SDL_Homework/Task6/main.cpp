/* 
Напишете функция която рисува празен правоъгълник с подадена дебелина 
на линиите. (ПОЯСНЕНИЕ: може да стане с помощта 2 запълнени правоъгълника);
*/

#include <iostream>
#include "SDL2/SDL.h"
using namespace std;


bool init();
void handleEvents();
void close();
void drawRectangle(int width, int height, int thickness);
bool isRunning;

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;

int main(){
    int ww, wh, rw, rh;
    
    SDL_Rect rectangle= {ww/2, wh/2, rw, rh};
    isRunning = true;
    init();
    SDL_GetWindowSize(gWindow, &ww, &wh);
    while (isRunning){
        handleEvents();
        
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
            //get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }
    return success;
}
void handleEvents()
{
    SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT: isRunning = false; break;
			default: break;
		}
	}
}

void drawRectangle(int width, int height, int thickness)
{

}

void close()
{
    
    SDL_FreeSurface(gHelloWorld); // frees surface / deallocates
    gHelloWorld = NULL;
    SDL_DestroyWindow( gWindow );  //destroys window
    gWindow = NULL;  //GET in habit of always NULLing pointers. you avoid undefined behavior
    SDL_Quit();
}