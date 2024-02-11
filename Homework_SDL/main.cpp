#include "Game.h"
#include <iostream>

Game* game = NULL;
const int WINDOW_WIDTH = 1024;
const int WINDOW_HEIGHT = 720;


int main(){
    std::cout << "Hello world\n";
    game = new Game();
    game->init("HW", 
                SDL_WINDOWPOS_CENTERED, 
                SDL_WINDOWPOS_CENTERED,
                WINDOW_WIDTH, WINDOW_HEIGHT,
                NULL  );
    game->im_init();
    while (game->isRunning()){
        game->handleEvents();
        game->update();
        game->render();
    }
    
    game->clean();
    return 0;
}