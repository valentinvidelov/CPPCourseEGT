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

    double initialX = centerX - sideLength/2; //needs fixing to center
    double initialY = centerY + sideLength/2;

//pentagon 2,  centered vertically, but an irregular pentagon..

    SDL_RenderDrawLine(renderer, centerX, 
                        centerY-sideLength*sin(108),
                        centerX-sideLength*sin(108),
                        centerY-sideLength*cos(108) 
                        );
    SDL_RenderDrawLine(renderer, centerX, 
                        centerY-sideLength*sin(108),
                        centerX+sideLength*sin(108),
                        centerY-sideLength*cos(108) 
                        );

    SDL_RenderDrawLine(renderer, centerX-sideLength*sin(108),
                        centerY-sideLength*cos(108),
                        centerX-sideLength/2,
                        centerY+sideLength*sin(108) 
                        );
    SDL_RenderDrawLine(renderer, centerX+sideLength*sin(108),
                        centerY-sideLength*cos(108),
                        centerX+sideLength/2,
                        centerY+sideLength*sin(108) 
                        );
    SDL_RenderDrawLine(renderer, 
                        centerX+sideLength/2,
                        centerY+sideLength*sin(108),
                        centerX-sideLength/2,
                        centerY+sideLength*sin(108)
                        );
    



    // SDL_GetWindowSurface();
    // SDL_CreateTextureFromSurface();   //combine these two.. see if we can take/ set screenshots
    //points discovery
    // SDL_RenderDrawLine(renderer, centerX, centerY, 
    //                     centerX, 
    //                     centerY-sideLength*sin(108));
    // SDL_RenderDrawLine(renderer, centerX, centerY, 
    //                     centerX-sideLength*sin(108),
    //                     centerY-sideLength*cos(108));
    // SDL_RenderDrawLine(renderer, centerX, centerY, 
    //                     centerX+sideLength*sin(108),
    //                     centerY-sideLength*cos(108));

    // SDL_RenderDrawLine(renderer, centerX, centerY,  //dont use these last two, others look fineish
    //                     centerX-sideLength*cos(198),
    //                     centerY+sideLength*sin(198));
    // SDL_RenderDrawLine(renderer, centerX, centerY, 
    //                     centerX+sideLength*cos(198),
    //                     centerY+sideLength*sin(198));

//pentagon 1, not centered vertically
    // SDL_RenderDrawLine(renderer, initialX, initialY, initialX + sideLength, 
    //                     initialY);
    // SDL_RenderDrawLine(renderer, initialX + sideLength, initialY, 
    //                     initialX + sideLength+ sideLength*cos(108),
    //                     initialY - sideLength*sin(108));
    // SDL_RenderDrawLine(renderer, initialX + sideLength+ sideLength*cos(108),
    //                     initialY - sideLength*sin(108),
    //                     centerX,
    //                     initialY - 2* sideLength*sin(108));
    // SDL_RenderDrawLine(renderer, centerX,
    //                     initialY - sideLength*sin(108) - sideLength*sin(108),
    //                     initialX - sideLength*cos(108),
    //                     initialY - sideLength*sin(108));    
    // SDL_RenderDrawLine(renderer, initialX - sideLength*cos(108),
    //                     initialY - sideLength*sin(108),
    //                     initialX, initialY);    
}

void Shapes::drawHexagon(SDL_Renderer *renderer, int centerX, int centerY, int sideLength)
{
    double initialX = centerX+ cos(60)*sideLength/2;
    double initialY = centerY - sideLength * sin(60)*2;

    SDL_RenderDrawLine(renderer, initialX, initialY, initialX+sideLength, initialY);
    SDL_RenderDrawLine(renderer, initialX+sideLength, initialY, centerX+sideLength, centerY);
    SDL_RenderDrawLine(renderer, centerX+sideLength, centerY, initialX+sideLength, centerY+sideLength*sin(60)*2);
    SDL_RenderDrawLine(renderer, initialX+sideLength, centerY+sideLength*sin(60)*2, 
                                initialX, centerY+sideLength*sin(60)*2);
    SDL_RenderDrawLine(renderer, initialX, centerY+sideLength*sin(60)*2, 
                                centerX-sideLength, centerY);
    SDL_RenderDrawLine(renderer, centerX-sideLength, centerY, 
                                initialX, initialY);
}

void Shapes::drawEllipse(SDL_Renderer *renderer, int centerX, int centerY, double eccentricity)
{
}
