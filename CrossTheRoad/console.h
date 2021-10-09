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



class ConsoleDesign
{
public:
	static SHORT GetKeyState(int nVirtKey);
	static void FixConsoleWindow();
	static void GotoXY(int x, int y);
	static void fixCur(bool CursorVisibility);
	static void disableSelection();
	static void sizeEdit(short weight, short height);
	static void editFontSizeConsole(); // responsive
	static void SetBufferSize();
public:
	// CONSTRUCTOR & DESTRUCTOR
	ConsoleDesign();
	~ConsoleDesign();
};



