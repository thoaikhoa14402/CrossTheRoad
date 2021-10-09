#pragma once
#include"console.h"
#include"windows.h"
#include<iostream>
using namespace std;
class GameMenu
{
public:
	static void drawTitle(); // draw title "cross the road"
	static void drawMenu(); // draw menu form
	static void drawOption(const char* str, POINT point, int color); // draw elements in menu
	static void checkKey(); // check key pressed by player
public:
	GameMenu();
};