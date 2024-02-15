// TextureManager.h
#pragma once
#include "Game.h"
#include <iostream>
#include <map>

class TextureManager {
public:
	bool loadTexture(const char* fileName, std::string id, SDL_Renderer* ren);
	void drawTexture(std::string id,
		int x, int y,
		int width, int height,
		SDL_Renderer* ren,
		SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawOneFrameFromTexture(std::string id,
		int x, int y,
		int width, int height,
		int currentRow, int currentFrame,
		SDL_Renderer* ren,
		SDL_RendererFlip flip = SDL_FLIP_NONE);

    void toggleVisibility(std::string id);

	static TextureManager* Instance() { // TextureManager is a singleton, only one instance allowed
		if (instance == 0) {
			instance = new TextureManager();
			return instance;
		}
		return instance;
	}

private:
	std::map<std::string, SDL_Texture*> textureMap;
    std::map<std::string, bool> visible; //map to store instruction for displaying the loaded textures // copied from Rumen
	TextureManager() {} // TextureManager is a singleton, the constructor is a private field
	static TextureManager* instance;
};