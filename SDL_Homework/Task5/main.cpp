#include <iostream>
#include "SDL2/SDL.h"

#include "Game.h"

using namespace std;
// tasks.json args          // sudo apt-get install libsdl2-ttf-dev  / libsdl2-dev / libsdl2-image-dev  //so far
/*                 "-fdiagnostics-color=always",
                "-g",
                // "${file}",
                "${fileDirname}/*.cpp",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}",
                "-lSDL2",
                "-lSDL2_ttf",
 */

const int FPS = 30; //60
void limitFPS(Uint32 startingTick) {
	if ((1000 / FPS) > SDL_GetTicks() - startingTick)
		SDL_Delay((1000 / FPS) - (SDL_GetTicks() - startingTick));
}

Game* game = NULL;
const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

int main(int argc, char* argv[]) {

	game = new Game();
	game->init("My new window",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_WINDOW_RESIZABLE);
    Uint32 startingTick;
	while (game->isRunning()) {
        
        startingTick = SDL_GetTicks();  //this kinda made it laggier here...
		game->handleEvents();
       
		game->update();
        
		game->render();
        limitFPS(startingTick);
	}
	game->clean();
	return 0;
}
