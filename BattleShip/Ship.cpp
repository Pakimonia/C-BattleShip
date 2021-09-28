#include "Ship.h"

void SetForegroundColor(ConsoleColors color)
{
		HANDLE consoleWndHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(consoleWndHandle, color);
}

