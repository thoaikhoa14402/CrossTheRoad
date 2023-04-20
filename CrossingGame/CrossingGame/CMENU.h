#pragma once
#include"CCONSOLE.h"
#include"COPTION.h"
#include"windows.h"
#include<iostream>
#include<fstream>
using namespace std;
class CMENU
{
private:
	COPTION *option;
public:
	CMENU();
	CMENU(COPTION*);
	~CMENU();
	void drawTitle(); // draw title "cross the road"
	void drawMenu(); // draw menu form
	void drawOption(const char* str, POINT point, int color); // draw elements in menu
	void checkKey(); // check key pressed by player

	void runMenu(); // run menu game

	void AboutHandle(); // handle about option
	void LoadHandle(bool); // handle load option
	void SettingHandle(); // handle setting option
	void soundSetting(); // setting music
	void levelSetting(); // setting level
	void resetOption();
};

