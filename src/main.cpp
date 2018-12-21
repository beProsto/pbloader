#include <windows.h>
#include <cstdio>

#include <api/api.hpp>
#include <internal.hpp>
#include <detours/detours.h>
#include <hooks/hook.hpp>

#include <SDL2/SDL.h>

DWORD WINAPI Main(LPVOID);

HANDLE thread;
bool quit;

Sprite* sprite;

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID reserved) {
    switch(reason) {
        case DLL_PROCESS_ATTACH:
			    thread = CreateThread(NULL, 0, &Main, &quit, 0, NULL);
			break;
		case DLL_PROCESS_DETACH:
            Hooks::Clear();
            Internal::CloseConsole();
            if(sprite == NULL)
                delete sprite;
			break;
	}
	return TRUE;
}

DWORD WINAPI Main(LPVOID) {
    Internal::OpenConsole();
    if(!Hooks::Init()) {
        return FALSE;
    }
    sprite = new Sprite(Vector2f(0, 0), Vector2f(32, 32));
    sprite->loadTexture("dog.png");
    Render::addSprite(sprite);
    return 0;
}
