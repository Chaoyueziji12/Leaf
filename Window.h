#pragma once
#include<SDL.h>

const int LF_WINDOWPOS_CENTERED = SDL_WINDOWPOS_CENTERED;
int windowDelay = 10;

class LeafWindow
{
	private:
		SDL_Renderer* renderer;
		int windowDelay;
	public:
		SDL_Window* window;
		const char* title;
		int width; 
		int height; 
		int x; 
		int y; 
		const int delay = 10; 
		int bgR = 0; 
		int bgG = 0; 
		int bgB = 0; 
		int bgA = 255;

	void Initialize()
	{
		SDL_Init(SDL_INIT_VIDEO);
		window = SDL_CreateWindow(title, x, y, width, height, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		windowDelay = delay;

		SDL_SetRenderDrawColor(renderer, bgR, bgG, bgB, bgA);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}
	void Run()
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
		SDL_DestroyWindow(this->window);
		SDL_Quit();
	}

};
	
