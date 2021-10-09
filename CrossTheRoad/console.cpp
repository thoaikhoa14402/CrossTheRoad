#pragma once
#include"console.h"
#define W  0x57
#define A  0x41
#define	S  0x53
#define	D  0x44
#define	P  0x50
#define	T  0x54
#define	L  0x4C
#define	E  0x45

//#define B  0x42
//#define C  0x43
//#define	F  0x46
//#define	G  0x47
//#define	H  0x48
//#define	I  0x49
//#define	J  0x4A
//#define	K  0x4B
//#define	M  0x4D
//#define N  0x4E
//#define	O  0x4F
//#define	Q  0x51
//#define	R  0x52
//#define	U  0x55
//#define	V  0x56
//#define	Z  0x5A


// ConsoleDesign

SHORT ConsoleDesign::GetKeyState(int nVirtKey)
{
	return GetAsyncKeyState(nVirtKey) & 0x01;
}

ConsoleDesign::ConsoleDesign()
{

}

ConsoleDesign::~ConsoleDesign()
{

}
// fix screen
void ConsoleDesign::FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void ConsoleDesign::GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ConsoleDesign::fixCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConCurInf;
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = CursorVisibility;
	SetConsoleCursorInfo(handle, &ConCurInf);
}
void ConsoleDesign::disableSelection()
{
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleMode(hStdin, ~ENABLE_QUICK_EDIT_MODE);
}

void ConsoleDesign::sizeEdit(short weight, short height)
{
	RECT r;
	GetWindowRect(GetConsoleWindow(), &r);
	MoveWindow(GetConsoleWindow(), r.left, r.top, weight, height, true);
}

void ConsoleDesign::editFontSizeConsole()
{

	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	::GetWindowRect(hDesktop, &desktop);
	CONSOLE_FONT_INFOEX cfi
	{
		sizeof(cfi),0,0,(desktop.bottom < 700) ? 14 : 16,FF_DONTCARE,FW_NORMAL,L"Consolas"
	};
	::SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), false, &cfi);
}

void ConsoleDesign::SetBufferSize()
{
	CONSOLE_SCREEN_BUFFER_INFO scrBufferInfo;
	::GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &scrBufferInfo);
	short winWidth = scrBufferInfo.srWindow.Right - scrBufferInfo.srWindow.Left + 1;
	short winHeight = scrBufferInfo.srWindow.Bottom - scrBufferInfo.srWindow.Top + 1;

	short scrBufferWidth = scrBufferInfo.dwSize.X;
	short scrBufferHeight = scrBufferInfo.dwSize.Y;

	COORD newSize{ scrBufferWidth, winHeight };

	int Status = SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), newSize);
	if (Status == 0)
	{
		std::cerr << "SetConsoleScreenBufferSize() failed! Reason : " << GetLastError() << std::endl;
		exit(Status);
	}
}