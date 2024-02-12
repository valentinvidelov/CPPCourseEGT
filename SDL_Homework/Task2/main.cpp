#include <iostream>
#include "Game.h"

Game* game = NULL;
const int WINDOW_WIDTH = 1260;
const int WINDOW_HEIGHT = 900;

const int FPS = 30; //60
void limitFPS(Uint32 startingTick) {
	if ((1000 / FPS) > SDL_GetTicks() - startingTick)
		SDL_Delay((1000 / FPS) - (SDL_GetTicks() - startingTick));
}

int main () {
    std::cout << cos(108) << " " << sin(108) << std::endl;
    game = new Game();
    game->init("Task 2 Draw a Pentagon",
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                WINDOW_WIDTH,
                WINDOW_HEIGHT,
                SDL_WINDOW_RESIZABLE);

    Uint32 startingTick;
    while(game->isRunning()){

        startingTick = SDL_GetTicks();
        game->handleEvents();
        game->update();
        game->render();
        limitFPS(startingTick);
    }

    game->clean();
    return 0;
}