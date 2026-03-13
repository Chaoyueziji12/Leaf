#pragma once
#include <SDL.h>
#include "imgui-docking/imgui.h"
#include "imgui-docking/backends/imgui_impl_sdl2.h"
#include "imgui-docking/backends/imgui_impl_sdlrenderer2.h"

// 结构体定义
struct LeafImGuiWindowStruct {
	SDL_Window* win;
	SDL_Renderer* renderer;
};

typedef LeafImGuiWindow* LeafImGuiWindow;

namespace Leaf {
	inline LeafImGuiWindow CreateImGuiWindow(const char* title, int w, int h) {
		SDL_Init(SDL_INIT_VIDEO);
		LeafImGuiWindow lw = new LeafImGuiWindow();
		lw->win = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
		lw->renderer = SDL_CreateRenderer(lw->win, -1, SDL_RENDERER_ACCELERATED);
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGui_ImplSDL2_InitForSDLRenderer(lw->win, lw->renderer);
		ImGui_ImplSDLRenderer2_Init(lw->renderer);
		ImGui::StyleColorsDark();
		return lw;
	}

	inline void RunImGuiWindow(LeafImGuiWindow lw) {
		bool run = true;
		while (run) {
			SDL_Event e;
			while (SDL_PollEvent(&e)) {
				ImGui_ImplSDL2_ProcessEvent(&e);
				if (e.type == SDL_QUIT) run = false;
			}
			ImGui_ImplSDLRenderer2_NewFrame();
			ImGui_ImplSDL2_NewFrame();
			ImGui::NewFrame();

			ImGui::Begin("默认窗口");
			ImGui::Text("Hello World!");
			ImGui::End();

			ImGui::Render();
			SDL_SetRenderDrawColor(lw->renderer, 0, 0, 0, 255);
			SDL_RenderClear(lw->renderer);
			ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), lw->renderer);
			SDL_RenderPresent(lw->renderer);
		}
		ImGui_ImplSDLRenderer2_Shutdown();
		ImGui_ImplSDL2_Shutdown();
		ImGui::DestroyContext();
		SDL_DestroyRenderer(lw->renderer);
		SDL_DestroyWindow(lw->win);
		delete lw;
		SDL_Quit();
	}
}