//
// Created by devildefu on 01.12.2018.
//

#include <hooks/hook.hpp>

MologieDetours::Detour<tCreateWindow> *detour_CreateWindow = NULL;
MologieDetours::Detour<tRenderPresent> *detour_RenderPresent = NULL;

bool Hooks::Init() {
    try {
        detour_CreateWindow = new MologieDetours::Detour<tCreateWindow>("SDL2.dll", "SDL_CreateWindow",
                                                                        Hooks::SDL_CreateWindow);

        detour_RenderPresent = new MologieDetours::Detour<tRenderPresent>("SDL2.dll", "SDL_RenderPresent",
                                                                          Hooks::SDL_RenderPresent);
    } catch(MologieDetours::DetourException& e) {
        return FALSE;
    }
}

void Hooks::Clear() {
    delete detour_CreateWindow;
    delete detour_RenderPresent;
}


SDL_Window* Hooks::SDL_CreateWindow(const char *title, int x, int y, int w, int h, Uint32 flags) {
    SDL_Window* window = detour_CreateWindow->GetOriginalFunction()(title, x, y, w, h, flags);
    return window;
}

int Hooks::SDL_RenderPresent(SDL_Renderer *renderer) {
    printf("SDL_RenderPresent\n");
    SDL_Rect fillRect = { 10, 10, 32, 32 };
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &fillRect);

    return detour_RenderPresent->GetOriginalFunction()(renderer);
}