//
// Created by devildefu on 02.12.2018.
//

#ifndef PBLOADER_SPRITE_HPP
#define PBLOADER_SPRITE_HPP

#include <engine/vector/vector.hpp>

class Sprite {
public:
    Sprite() { }
    Sprite(const Vector2f& pos);

private:
    Vector2f pos;
};

#endif //PBLOADER_SPRITE_HPP
