#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include <SDL2/SDL.h>

class Obstacle {
private:
    /* If obstacle is custom, id must be -1 (may change)*/
    int id = -1;

    /* It doesn't have to be set if obstacle is built into the game. */
    SDL_Surface* texture = NULL;
public:
    Obstacle() { }
    Obstacle(Obstacle& obstacle) {
        /* Copy all values */
        this->id = obstacle.getId();
        this->texture = obstacle.getTexture();
    }

    ~Obstacle() { 
        if(texture)
            SDL_FreeSurface(texture);
    }

    inline int getId() { return id; }
    inline SDL_Surface* getTexture() { return texture; }
};

#endif

