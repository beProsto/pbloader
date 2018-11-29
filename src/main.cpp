#include <windows.h>
#include <cstdio>

#include "../include/api.hpp"
#include "../include/internal.hpp"

DWORD WINAPI Main(LPVOID param);

bool quit;
HANDLE thread;

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID reserved) {
	switch(reason) {
		case DLL_PROCESS_ATTACH:
			thread = CreateThread(NULL, 0, Main, &quit, 0, NULL);
			break;
		case DLL_PROCESS_DETACH:
			quit = true;
			break;
	}
	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch(msg) {
		case WM_CLOSE:
		case WM_DESTROY:
			quit = true;
			break;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

DWORD WINAPI Main(LPVOID param) {
	bool* quit = (bool*)param;

	API::SetTitle(L"Perypetie Boba (with Mod Loader v1.0)");
	API::OpenConsole();

	HWND window = Internal::GetHWND();
	SetWindowLong(window, GWL_WNDPROC, (LONG)&WndProc);

	/* Psuje okno
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

	bool started = false;

	int lx, ly;
	int lxLast = 0;
	int lyLast = 0;

	float px, py;
	float pxLast = 0.0;
	float pyLast = 0.0;

	while(!*quit) {
		lx = API::GetXLoc();
		ly = API::GetYLoc();
		if(lx != lxLast || ly != lyLast) {
			if(!started) {
				API::SetDeathCount(2136);
				printf("Death Count: %i\n", API::GetDeathCount());

				Sleep(3000);
				API::Respawn();

				started = true;
			}

			lxLast = lx;
			lyLast = ly;
			printf("Location: %i, %i\n", lx, ly);

			API::PlaceBlock(2, 2, 1);

			Sleep(500);

			API::Jump();
			API::Shoot();
		}

		if(started) {
			px = API::GetXPos();
			py = API::GetYPos();
			if(px != pxLast || py != pyLast) {
				pxLast = px;
				pyLast = py;
				printf("Location: %i, %i | Position: %.2f, %.2f\n", lx, ly, px, py);
			}
		}
	}

	return 0;
}
