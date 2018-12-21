#pragma once

#include <iostream>
#include <windows.h>

#ifndef LOGGER_OFF
#define logInfo(x...)  setConsoleColor(15);_logger_raw("[INFO]" , x, " at", __FILE__ , "\b:", __LINE__);setConsoleColor(15)
#define logError(x...) setConsoleColor(12);_logger_raw("[ERROR]", x, " at", __FILE__ , "\b:", __LINE__);setConsoleColor(15)
#define logWarn(x...)  setConsoleColor(14);_logger_raw("[WARN]" , x, " at", __FILE__ , "\b:", __LINE__);setConsoleColor(15)
#else
#define logInfo(x...);
#define logError(x...);
#define logWarn(x...);
#endif

static void setConsoleColor(unsigned char a) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, a);
}

template<typename T>
static void _logger_raw(const T& arg) {
    std::cout << arg << '\n';
}

template<typename T, typename ... T2>
static void _logger_raw(const T& arg, const T2& ... args) {
    std::cout << arg << ' ';
	_logger_raw(args...);
}