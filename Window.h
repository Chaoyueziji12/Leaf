#pragma once
#include<SDL.h>

typedef SDL_Window* LeafWindow;
const int LF_WINDOWPOS_CENTERED = SDL_WINDOWPOS_CENTERED;

namespace Leaf {
	LeafWindow CreateWindow(const char* title, int width, int height, int posx, int posy)
	{
		SDL_Init(SDL_INIT_VIDEO);
		SDL_Window* window = SDL_CreateWindow(title, posx, posy, width, height, SDL_WINDOW_SHOWN);
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
			SDL_Delay(10);
		}
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
}
