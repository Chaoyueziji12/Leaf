#pragma once
#include"Leaf.h"

typedef SDL_Rect* LeafRectangle;

namespace Leaf {
	LeafRectangle CreateRectangle(int width, int height, int x, int y, int colorR=0, int colorG=255, int colorB=0, int colorA=255, LeafWindow window=nullptr)
	{
		SDL_Renderer* renderer = SDL_GetRenderer((SDL_Window*)window);

		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

		SDL_Rect* rect = new SDL_Rect{x, y, width, height};
		
		SDL_RenderFillRect(renderer, rect);

		SDL_RenderPresent(renderer);
		return (LeafRectangle)rect;
	}
}
