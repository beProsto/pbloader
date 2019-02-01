#ifndef PBLOADER_PLAYER_HPP
#define PBLOADER_PLAYER_HPP

#include <cmath>

#include <engine/vector/vector.hpp>

#define Player_posX       ((float*)0x005411E0)
#define Player_posY       ((float*)0x005411E0)
#define Player_deathCount ((int*)0x005410F8)

namespace Player {

    Vector2f getPosition();

    void setPosition(float x, float y);
    void setPosition(const Vector2f& vec);

    void move(float x, float y);

    int getDeathCount();
    void setDeathCount(int count);

}

#endif //PBLOADER_PLAYER_HPP