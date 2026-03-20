#pragma once
#include<SDL.h>
#include"Window.h"

//typedef SDL_Rect* LeafRectangle;

class LeafRect
{
	private:
		SDL_Renderer* renderer;
		SDL_Rect rect;
	public:
		SDL_Window* window;
		int x;
		int y;
		int width;
		int height;
		int colorR = 0;
		int colorG = 255;
		int colorB = 0;
		int colorA = 255;
	void Draw()
	{
		renderer = SDL_GetRenderer(window);
		rect = SDL_Rect{ x, y, width, height };
		SDL_SetRenderDrawColor(renderer, colorR, colorG, colorB, colorA);
		SDL_RenderFillRect(renderer, &rect);
		SDL_RenderPresent(renderer);
	}

};

//LeafRectangle CreateRectangle(int width, int height, int x, int y, int colorR=0, int colorG=255, int colorB=0, int colorA=255, LeafWindow window=nullptr)
//{
	//SDL_Renderer* renderer = SDL_GetRenderer((SDL_Window*)window);

	//SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

	//SDL_Rect* rect = new SDL_Rect{x, y, width, height};
		
	//SDL_RenderFillRect(renderer, rect);

	//SDL_RenderPresent(renderer);
	//return (LeafRectangle)rect;

//}
