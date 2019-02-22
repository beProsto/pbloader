#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include <SDL2/SDL.h>

#include <logger.hpp>

#include <hooks/typedefs.hpp>
#include <detours/detours.h>

class GameManager {
private:
    GameManager() { }
public:
    static void Init() {  }
    static void HandleEvents();
    static void Render();
};

#endif