#include <windows.h>
#include <cstdio>

#include <api/api.hpp>
#include <internal.hpp>

DWORD WINAPI Main(LPVOID);

HANDLE thread;
bool quit;

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID reserved) {
	switch(reason) {
		case DLL_PROCESS_ATTACH:
			thread = CreateThread(NULL, 0, &Main, &quit, 0, NULL);
			break;
		case DLL_PROCESS_DETACH:
			break;
	}
	return TRUE;
}

DWORD WINAPI Main(LPVOID) {
	return 0;
}