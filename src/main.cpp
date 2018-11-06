#include <windows.h>
#include <stdint.h>
#include <fcntl.h>

#include <SDL2/SDL.h>

DWORD WINAPI Main(LPVOID);
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

bool* quit;
HANDLE thread;

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID reserved) {
	switch(reason) {
		case DLL_PROCESS_ATTACH:
			thread = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)&Main, NULL, NULL, NULL);
			//MessageBoxA(0, "DLL_PROCESS_ATTACH", "DLL_PROCESS_ATTACH", MB_ICONINFORMATION | MB_OKCANCEL);
			break;
		case DLL_PROCESS_DETACH:
			//MessageBoxA(0, "DLL_PROCESS_DETACH", "DLL_PROCESS_DETACH", MB_ICONINFORMATION | MB_OKCANCEL);
			break;
	}
	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch(msg) {
		case WM_CLOSE:
		case WM_DESTROY:
			*quit = true;
			break;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

DWORD WINAPI Main(LPVOID) {
	/*
	uint16_t* ptr = (uint16_t*)0x00541DC0;
	while(ptr<(uint16_t*)0x0054223E) {
		*ptr = 0x01;
		ptr += 0x00000001;
	}
	return 0;
	*/

	// I cyk otwieramy konsolke
	AllocConsole();

	HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
	int hCrt = _open_osfhandle((long)handle_out, _O_TEXT);
	FILE* hf_out = _fdopen(hCrt, "w");
	setvbuf(hf_out, NULL, _IONBF, 1);
	*stdout = *hf_out;

	HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);
	hCrt = _open_osfhandle((long)handle_in, _O_TEXT);
	FILE* hf_in = _fdopen(hCrt, "r");
	setvbuf(hf_in, NULL, _IONBF, 128);
	*stdin = *hf_in;

	HWND game = FindWindow(NULL, "Perypetie Boba");
	SetWindowLong(game, GWL_WNDPROC, (LONG)&WndProc);

	/* Psuje okno, bez sensu używać
	HMENU menu = CreateMenu();
	MENUITEMINFO menuInfo;
	ZeroMemory(&menuInfo, sizeof(menuInfo));
	menuInfo.cbSize = sizeof(menuInfo);
	menuInfo.fMask = MIIM_ID | MIIM_TYPE;
	menuInfo.fType = MFT_STRING;
	menuInfo.wID = 110;
	menuInfo.dwTypeData = "Hello!";
	InsertMenuItem(menu, 106, FALSE, &menuInfo);
	SetMenu(game, menu);
	*/

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindowFrom(game);
	SDL_SetWindowTitle(window, "Perypetie Boba (with PB Mod Loader v1.0)");
	SDL_Surface* surface = SDL_GetWindowSurface(window);

	while(!*quit) {
		SDL_FillRect(surface, &surface->clip_rect, 0x0000ffff);
		SDL_UpdateWindowSurface(window);
		printf("cyk\n");
	}

	SDL_FreeSurface(surface);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
