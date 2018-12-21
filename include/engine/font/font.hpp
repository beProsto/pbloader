//
// Created by devildefu on 21.12.2018.
//

#ifndef PBLOADER_FONT_HPP
#define PBLOADER_FONT_HPP

#include <SDL2/SDL_ttf.h>

class Font {
private:
    TTF_Font* font;
public:
    Font();
    Font(const Font& other);
};

#endif //PBLOADER_FONT_HPP
