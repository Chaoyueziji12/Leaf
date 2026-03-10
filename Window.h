#pragma once
#include<SDL.h>

typedef SDL_Window* LeafWindow;
const int LF_WINDOWPOS_CENTERED = SDL_WINDOWPOS_CENTERED;
int windowDelay = 10;

namespace Leaf {
	LeafWindow CreateWindow(const char* title, int width, int height, int posx, int posy, const int delay=10)
	{
		SDL_Init(SDL_INIT_VIDEO);
		SDL_Window* window = SDL_CreateWindow(title, posx, posy, width, height, SDL_WINDOW_SHOWN);
		windowDelay = delay;
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
