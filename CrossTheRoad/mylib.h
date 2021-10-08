#pragma once
#pragma execution_character_set("utf-8")

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

#include<iostream>
#include <conio.h>
#include<string>
#include<Windows.h>
#include<thread>
using namespace std;

SHORT GetKeyState(int nVirtKey);

class initialDesign
{
public:
	void FixConsoleWindow();
	void GotoXY(int x, int y);
	void fixCur(bool CursorVisibility);
	void disableSelection();
	void sizeEdit(short weight, short height);
	void editFontSizeConsole(); // responsive
	void SetBufferSize();
public:
	// CONSTRUCTOR & DESTRUCTOR
	initialDesign();
	~initialDesign();
};

class GameMenu : public initialDesign
{
public:
	void drawTitle(); // draw title "cross the road"
	void drawMenu(); // draw menu form
	void drawOption(const char*str, POINT point, int color); // draw elements in menu
	void checkKey(); // check key pressed by player
public:
	GameMenu();
};