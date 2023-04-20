#pragma once
#include"CCONSOLE.h"
int game_sound_state = 1;

// Get Key State (Capture event)
SHORT CCONSOLE::GetKeyState(int nVirtKey)
{
	return GetAsyncKeyState(nVirtKey) & 0x01;
}

// constructor
CCONSOLE::CCONSOLE()
{

}

// Handle Console 
void CCONSOLE::ConsoleHandle()
{
	// console initializing
	CCONSOLE::FixConsoleWindow();
	CCONSOLE::disableSelection();
	CCONSOLE::sizeEdit(1100, 800);
	CCONSOLE::editFontSizeConsole(); // responsive
	CCONSOLE::SetBufferSize();
	CCONSOLE::fixCur(false);
	CCONSOLE::initLoadingBar(0);
	CCONSOLE::playMusic("background");
}


// Fix Screen
void CCONSOLE::FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

// GO TO COORDINATION
void CCONSOLE::GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Fix Cursor
void CCONSOLE::fixCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConCurInf;
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = CursorVisibility;
	SetConsoleCursorInfo(handle, &ConCurInf);
}

// Disable Selection
void CCONSOLE::disableSelection()
{
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleMode(hStdin, ~ENABLE_QUICK_EDIT_MODE);
}

// Edit Size
void CCONSOLE::sizeEdit(short width, short height)
{
	RECT r;
	GetWindowRect(GetConsoleWindow(), &r);
	MoveWindow(GetConsoleWindow(), r.left, r.top, width, height, true);
}

// Edit Size Of Console
void CCONSOLE::editFontSizeConsole()
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

// Set Buffer Size
void CCONSOLE::SetBufferSize()
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

// Get Size Of Console
void CCONSOLE::GetSize()
{
	CONSOLE_SCREEN_BUFFER_INFO scrBufferInfo;
	::GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &scrBufferInfo);
	std::cerr << "Screen Buffer Size : " << scrBufferInfo.dwSize.X << " x " << scrBufferInfo.dwSize.Y << std::endl;
}

// setColor
void CCONSOLE::setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// draw graphics
void CCONSOLE::drawGraphics(const char* filename, POINT coord, int color, int sleep)
{
	setColor(color);
	ifstream infile;
	string str;
	infile.open(filename);
	while (!infile.eof())
	{
		Sleep(sleep);
		getline(infile, str);
		GotoXY(coord.x, coord.y);
		cout << str;
		coord.y++;
	}
	infile.close();
}

// remove space
void CCONSOLE::removeSpace(POINT coord_1, POINT coord_2)
{
	for (int i = coord_1.x; i < coord_2.x; i++)
	{
		for (int j = coord_1.y; j < coord_2.y; j++)
		{
			GotoXY(i, j);
			cout << " ";
		}
		cout << "\n";
	}
}

// loading bar game
void CCONSOLE::initLoadingBar(int flag)
{
	if (flag) // loading bar for game
	{
		SetConsoleOutputCP(65001); // utf-8
		CCONSOLE::fixCur(false);
		CCONSOLE::setColor(10);
		CCONSOLE::GotoXY(86, 19);
		cout << "LOADING......";
		CCONSOLE::drawGraphics("gameboard/rectangleBox.txt", POINT{ 64,21 }, lightyellow);
		CCONSOLE::setColor(lightaqua);
		CCONSOLE::GotoXY(80, 20);
		for (int i = 0; i <= 50; i++)
		{
			Sleep(20);
			CCONSOLE::GotoXY(65 + i, 22);
			cout << "█";
			CCONSOLE::GotoXY(65 + 25, 24);
			cout << i * 2 << "%";
		}
		system("cls");
	}
	else // loading bar for console
	{
		SetConsoleOutputCP(65001); // utf-8
		CCONSOLE::fixCur(false);
		CCONSOLE::setColor(10);
		CCONSOLE::GotoXY(65, 19);
		cout << "LOADING......";
		CCONSOLE::drawGraphics("gameboard/rectangleBox.txt", POINT{ 44,21 }, lightyellow);
		CCONSOLE::setColor(lightaqua);
		CCONSOLE::GotoXY(80, 20);
		for (int i = 0; i <= 50; i++)
		{
			Sleep(20);
			CCONSOLE::GotoXY(45 + i, 22);
			cout << "█";
			CCONSOLE::GotoXY(45 + 25, 24);
			cout << i * 2 << "%";
		}
		system("cls");
	}
}

// music
void CCONSOLE::playMusic(string music_name)
{
	string file_name = "sound/" + music_name + ".wav";
	PlaySoundA(file_name.c_str(), NULL, SND_ASYNC); // turn on sound
}

void CCONSOLE::turnOffMusic(string music_name)
{
	string file_name = "sound/" + music_name + ".wav";
	PlaySound(NULL(file_name.c_str()), NULL, SND_ASYNC); // turn off sound
}

// clean key press
void CCONSOLE::cleanKeyPress()
{
	CCONSOLE::GetKeyState(W);
	CCONSOLE::GetKeyState(A);
	CCONSOLE::GetKeyState(S);
	CCONSOLE::GetKeyState(D);
}