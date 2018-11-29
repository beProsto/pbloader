#include "../include/api.hpp"

int API::GetXLoc() {
	int* ptr = (int*)0x00541118;
	return *ptr;
}

int API::GetYLoc() {
	int* ptr = (int*)0x00541114;
	return *ptr;
}

void API::SetXLoc(int val) {
	int* ptr = (int*)0x00541118;
	*ptr = val;
}

void API::SetYLoc(int val) {
	int* ptr = (int*)0x00541114;
	*ptr = val;
}

////////////////////////////////////////////////////////////////////////////////

float API::GetXPos() {
	float* ptr = (float*)0x005411E0;
	return floor(*ptr);
}

float API::GetYPos() {
	float* ptr = (float*)0x005411E4;
	return floor(*ptr);
}

void API::SetXPos(float val) {
	float* ptr = (float*)0x005411E0;
	*ptr = val;
}

void API::SetYPos(float val) {
	float* ptr = (float*)0x005411E4;
	*ptr = val;
}

////////////////////////////////////////////////////////////////////////////////

void API::Shoot() {
	uint8_t* ptr = (uint8_t*)0x00542460;
	*ptr = 1;
}

void API::Jump(int height) {
	// TODO: Sprawdzić w jaki sposób skskać wyżej
	uint8_t* ptr = (uint8_t*)0x00542461;
	*ptr = 1;
}

void API::Respawn() {
	uint8_t* ptr = (uint8_t*)0x005411F0;
	*ptr = 1;
}

////////////////////////////////////////////////////////////////////////////////

int API::GetDeathCount() {
	int* ptr = (int*)0x005410F8;
	return *ptr;
}

void API::SetDeathCount(int val) {
	int* ptr = (int*)0x005410F8;
	*ptr = val;
}

////////////////////////////////////////////////////////////////////////////////

void API::PlaceBlock(int x, int y, uint16_t ID, bool solid) {
	SetBlock(x, y, ID);
	if(solid) AddCollision(x, y);	
	AddShadow(x, y);
}

// x*MAP_HEIGHT+y
void API::SetBlock(int x, int y, uint16_t ID) {
	uint16_t* ptr = (uint16_t*)MAP_START;

	// Set X
	for(int i = 0; i < x * MAP_HEIGHT; i++) {
		ptr += 0x00000001;
	}

	// Set Y
	for(int i = 0; i < y; i++) {
		ptr += 0x00000001;
	}

	*ptr = ID;
}

////////////////////////////////////////////////////////////////////////////////

void API::AddCollision(int x, int y) {
	SetCollision(x, y, true);
}

void API::RemoveCollision(int x, int y) {
	SetCollision(x, y, false);
}

void API::SetCollision(int x, int y, bool state) {
	bool* ptr = (bool*)COLLISION_START;

	for(int i = 0; i < x * MAP_HEIGHT; i++) {
		ptr += 0x00000001;
	}

	for(int i = 0; i < y; i++) {
		ptr += 0x00000001;
	}

	*ptr = state;
}

////////////////////////////////////////////////////////////////////////////////

void API::AddShadow(int x, int y) {
	SetShadow(x, y, true);
}

void API::RemoveShadow(int x, int y) {
	SetShadow(x, y, false);
}

void API::SetShadow(int x, int y, bool state) {
	bool* ptr = (bool*)SHADOWS_START;

	for(int i = 0; i < x * MAP_HEIGHT; i++) {
		ptr += 0x00000001;
	}

	for(int i = 0; i < y; i++) {
		ptr += 0x00000001;
	}

	*ptr = state;
}

////////////////////////////////////////////////////////////////////////////////

void API::OpenConsole() {
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
}

void API::CloseConsole() {
	FreeConsole();

	FILE* nulf = NULL;
	*stdout = *nulf;
	*stdin = *nulf;
}

void API::SetTitle(const wchar_t* title) {
	HWND handle = Internal::GetHWND();
	SetWindowTextW(handle, title);
}

int API::MsgBox(const wchar_t* title, const wchar_t* content, uint32_t flags) {
	HWND handle = Internal::GetHWND();
	return MessageBoxW(handle, content, title, flags);
}
