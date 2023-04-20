#pragma once
#pragma execution_character_set("utf-8")
#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>
#include<Windows.h>

#define W  0x57
#define A  0x41
#define	S  0x53
#define	D  0x44
#define	P  0x50
#define	L  0x4C
#define	E  0x45
#define B  0x42
#define _Y  0x59
#define	O  0x4F
#define	Q  0x51
#define	_T  0x54
#define M 0x4d
using namespace std;

extern int game_sound_state;

const int MAX_LEVEL = 5;

// Color
enum
{
	black,
	blue,
	green,
	aqua,
	red,
	purple,
	yellow,
	white,
	gray,
	lightblue,
	lightgreen,
	lightaqua,
	lightred,
	lightpurple,
	lightyellow,
	brightwhite
};


class CCONSOLE
{
public:
	CCONSOLE();
	static SHORT GetKeyState(int nVirtKey);
	static void FixConsoleWindow();
	static void GotoXY(int x, int y);
	static void fixCur(bool CursorVisibility);
	static void disableSelection();
	static void sizeEdit(short width, short height);
	static void editFontSizeConsole(); // responsive
	static void SetBufferSize();
	static void GetSize();
	// clean area
	static void removeSpace(POINT, POINT);
	static void setColor(int color);
	static void drawGraphics(const char* filename, POINT coord, int color, int sleep = 0);
	// CONSOLE HANDLING
	void ConsoleHandle();
	// loading bar
	static void initLoadingBar(int);
	// music
	static void playMusic(string);
	static void turnOffMusic(string);
	// clean key-press
	static void cleanKeyPress();
};



