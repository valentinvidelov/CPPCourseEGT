/*
Харесайте си sprite sheetс няколко реда и анимирайте последователно редовете;
*/
#include "Game.h"
#include <iostream>

const int FPS = 30; //60
void limitFPS(Uint32 startingTick) {
	if ((1000 / FPS) > SDL_GetTicks() - startingTick)
		SDL_Delay((1000 / FPS) - (SDL_GetTicks() - startingTick));
}

Game* game = NULL;
const int WINDOW_WIDTH = 1200;
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
		startingTick = SDL_GetTicks();
		game->handleEvents();
		game->update();
		game->render();
		limitFPS(startingTick);
	}
	game->clean();
	return 0;
}