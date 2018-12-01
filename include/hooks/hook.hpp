//
// Created by devildefu on 01.12.2018.
//

#ifndef PBLOADER_HOOK_HPP
#define PBLOADER_HOOK_HPP

#include <detours/detours.h>
#include <SDL2/SDL.h>

typedef SDL_Window *(*tCreateWindow)(const char *, int, int, int, int, Uint32);
typedef int (*tRenderPresent)(SDL_Renderer *renderer);

namespace Hooks {
    bool Init();
    void Clear();

    SDL_Window *SDL_CreateWindow(const char *title, int x, int y, int w, int h, Uint32 flags);
    int SDL_RenderPresent(SDL_Renderer *renderer);
}

#endif //PBLOADER_HOOK_HPP
