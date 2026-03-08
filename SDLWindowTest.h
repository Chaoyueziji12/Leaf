#pragma once
#include <SDL.h>

namespace Leaf {
	void CreateSDLWindow()
	{
		SDL_Init(SDL_INIT_VIDEO);
		SDL_Window* window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
        
        SDL_Event event;
        while (1) {
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
