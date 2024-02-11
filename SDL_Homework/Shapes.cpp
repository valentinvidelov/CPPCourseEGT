#include "Shapes.h"
#include <cmath>

void Shapes::drawCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius) { // Midpoint Circle Algorithm
	const int diameter = radius * 2;

	int x = (radius - 1);
	int y = 0;
	int tx = 1;
	int ty = 1;
	int error = tx - diameter;

	while (x >= y) {
		SDL_RenderDrawPoint(renderer, centerX + x, centerY - y);
		SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
		SDL_RenderDrawPoint(renderer, centerX - x, centerY - y);
		SDL_RenderDrawPoint(renderer, centerX - x, centerY + y);
		SDL_RenderDrawPoint(renderer, centerX + y, centerY - x);
		SDL_RenderDrawPoint(renderer, centerX + y, centerY + x);
		SDL_RenderDrawPoint(renderer, centerX - y, centerY - x);
		SDL_RenderDrawPoint(renderer, centerX - y, centerY + x);

		if (error <= 0) {
			y++;
			error += ty;
			ty += 2;
		}

		if (error > 0) {
			x--;
			tx += 2;
			error += tx - diameter;
		}
	}

}


//the initial x,y are off, rest is fine, fix initials
void Shapes::drawPentagon(SDL_Renderer *renderer, int centerX, int centerY, int sideLength)
{
    //to convert from polar(sidelength, angle(108 for reg pentagon)) to cartesion
    //cos(108) = x / sideLength  // x = cos(108) * sideLength
    //sin(108) = y / sideLength  // y = sin(108) * sideLength
    //hmm maybe its 72 instead of 108

    double initialX = centerX - sideLength/2;
    double initialY = centerY + sideLength/2;
    SDL_RenderDrawLine(renderer, initialX, initialY, initialX + sideLength, 
                        initialY);
    SDL_RenderDrawLine(renderer, initialX + sideLength, initialY, 
                        initialX + sideLength+ sideLength*cos(108),
                        initialY - sideLength*sin(108));
    SDL_RenderDrawLine(renderer, initialX + sideLength+ sideLength*cos(108),
                        initialY - sideLength*sin(108),
                        centerX,
                        initialY - 2* sideLength*sin(108));
    SDL_RenderDrawLine(renderer, centerX,
                        initialY - sideLength*sin(108) - sideLength*sin(108),
                        initialX - sideLength*cos(108),
                        initialY - sideLength*sin(108));    
    SDL_RenderDrawLine(renderer, initialX - sideLength*cos(108),
                        initialY - sideLength*sin(108),
                        initialX, initialY);    
}

void Shapes::drawHexagon(SDL_Renderer *renderer, int centerX, int centerY, int sideLength)
{
}

void Shapes::drawEllipse(SDL_Renderer *renderer, int centerX, int centerY, int radius, double eccentricity)
{
}
