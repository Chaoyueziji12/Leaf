#pragma once
#include <SDL.h>
#include "Dependencies/imgui-docking/imgui-docking/imgui.h"
#include "Dependencies/imgui-docking/imgui-docking/backends/imgui_impl_sdl2.h"
#include "Dependencies/imgui-docking/imgui-docking/backends/imgui_impl_sdlrenderer2.h"

// 结构体定义
struct LeafImGuiWindowStruct {
    SDL_Window* win;
    SDL_Renderer* renderer;
};

// ✅ 这里修正好了，不会再报未定义标识符
typedef LeafImGuiWindowStruct* LeafImGuiWindow;

namespace Leaf {
    inline LeafImGuiWindow CreateImGuiWindow(const char* title, int w, int h) {
        SDL_Init(SDL_INIT_VIDEO);
        // ✅ 这里也修正好了，new对的结构体
        LeafImGuiWindow lw = new LeafImGuiWindowStruct();
        lw->win = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
        lw->renderer = SDL_CreateRenderer(lw->win, -1, SDL_RENDERER_ACCELERATED);
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui_ImplSDL2_InitForSDLRenderer(lw->win, lw->renderer);
        ImGui_ImplSDLRenderer2_Init(lw->renderer);
        ImGui::StyleColorsDark();
        return lw;
    }

    inline void RunImGuiWindow(LeafImGuiWindow lw, void(*draw)() = nullptr) {
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

            // 默认窗口
            ImGui::Begin("默认窗口");
            ImGui::Text("Hello World!");
            ImGui::End();

            // 你的自定义UI
            if (draw) draw();

            ImGui::Render();
            SDL_SetRenderDrawColor(lw->renderer, 0, 0, 0, 255);
            SDL_RenderClear(lw->renderer);
            ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), lw->renderer);
            SDL_RenderPresent(lw->renderer);
        }
        // 清理
        ImGui_ImplSDLRenderer2_Shutdown();
        ImGui_ImplSDL2_Shutdown();
        ImGui::DestroyContext();
        SDL_DestroyRenderer(lw->renderer);
        SDL_DestroyWindow(lw->win);
        delete lw;
        SDL_Quit();
    }
}