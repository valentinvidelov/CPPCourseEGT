#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "TextureManager.h"

class Game {
public:
	Game();
	~Game();
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool isRunning();
    bool isClickableTextureClicked(SDL_Texture *t, SDL_Rect *r, int xDown, int yDown, int xUp, int yUp);

private:
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	bool running;
	int currentFrame;
	int msdx, msdy;

	SDL_Rect sRect, dRect;
	SDL_Texture *q1Texture, *q2Texture, *q3Texture, *q4Texture;
    SDL_Texture *q1, *q2, *q3, *q4;
    SDL_Texture *clickableTexture;
    SDL_Rect q1Rect, q2Rect, q3Rect, q4Rect;
};