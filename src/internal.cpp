#include "../include/internal.hpp"

HWND Internal::GetHWND() {
	return FindWindow(NULL, "Perypetie Boba");
}
