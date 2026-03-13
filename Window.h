#pragma once
#include<SDL.h>

typedef SDL_Window* LeafWindow;
const int LF_WINDOWPOS_CENTERED = SDL_WINDOWPOS_CENTERED;
int windowDelay = 10;

namespace Leaf {
	LeafWindow CreateWindow(const char* title, int width, int height, int x, int y, const int delay=10, int bgR=0, int bgG=0, int bgB=0, int bgA=255)
	{
		SDL_Init(SDL_INIT_VIDEO);
		SDL_Window* window = SDL_CreateWindow(title, x, y, width, height, SDL_WINDOW_SHOWN);
		SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		windowDelay = delay;
		SDL_SetRenderDrawColor(renderer, bgR, bgG, bgB, bgA);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
		return (LeafWindow)window;
	}
	void RunWindow(LeafWindow window)
	{
		SDL_Event event;
		while (1)
		{
			if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
			{
				break;
			}
			SDL_Delay(windowDelay);
			
		}
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
}
