#include "Game.h"
#include <iostream>

Game* game = NULL;
const int WINDOW_WIDTH = 1024;
const int WINDOW_HEIGHT = 720;

const int FPS = 30; //60
void limitFPS(Uint32 startingTick) {
	if ((1000 / FPS) > SDL_GetTicks() - startingTick)
		SDL_Delay((1000 / FPS) - (SDL_GetTicks() - startingTick));
}

int main(){
    std::cout << "Hello world\n";
    game = new Game();
    game->init("HW", 
                SDL_WINDOWPOS_CENTERED, 
                SDL_WINDOWPOS_CENTERED,
                WINDOW_WIDTH, WINDOW_HEIGHT,
                NULL  );
    Uint32 startingTick;
    while (game->isRunning()){
        
        startingTick = SDL_GetTicks();
        game->handleEvents();
        game->update();
        
        game->render();
        limitFPS(startingTick);
    }
    
    
    game->clean();
    return 0;
}