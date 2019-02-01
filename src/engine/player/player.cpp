#include <engine/player/player.hpp>

Vector2f Player::getPosition() {
    float x = floor(*Player_posX);
    float y = floor(*Player_posY);

    return {x,y};
}

void Player::setPosition(float x, float y) {
    *Player_posX = x;
    *Player_posY = y;
}

void Player::setPosition(const Vector2f& vec) {
    *Player_posX = vec.x;
    *Player_posY = vec.y;
}

void Player::move(float x, float y) {
    *Player_posX += x;
    *Player_posY += y;
}

int Player::getDeathCount() {
    return *Player_deathCount;
}

void Player::setDeathCount(int count) {
    *Player_deathCount = count;
}