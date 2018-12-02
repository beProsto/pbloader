//
// Created by devildefu on 02.12.2018.
//

#ifndef PBLOADER_RENDER_HPP
#define PBLOADER_RENDER_HPP

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace Render {
    SDL_Texture* LoadTexture(const std::string& path);

    void Draw(SDL_Texture* texture, const SDL_Rect* pos);
}

#endif //PBLOADER_RENDER_HPP
