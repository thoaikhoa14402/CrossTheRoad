#include"CMENU.h"
#include "CCONSOLE.h"
// CLASS GAME MENU

CMENU::CMENU()
{

}

CMENU::CMENU(COPTION* option)
{
	this->option = option;
}

CMENU::~CMENU()
{
	option = nullptr;
}
void CMENU::runMenu()
{
	drawTitle(); // draw title "cross the road"
	drawMenu(); // draw menu form
	checkKey(); // check key pressed by player
}



void CMENU::drawTitle()
{
	SetConsoleOutputCP(65001); // utf-8
	SetConsoleTitleA("UNIVERSITY OF SCIENCE - 20CLC08 - TEAM 5");
	CCONSOLE::drawGraphics("menu/cross.txt", POINT{ 8, 2 }, red);
	CCONSOLE::drawGraphics("menu/the.txt", POINT{ 58, 2 }, lightgreen);
	CCONSOLE::drawGraphics("menu/road.txt", POINT{ 93, 2 }, lightblue);
}

void CMENU::drawMenu()
{
	SetConsoleOutputCP(65001);  // utf-8
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	CCONSOLE::drawGraphics("menu/set_menu.txt", POINT{ 18, 10 }, lightaqua);
	CCONSOLE::drawGraphics("menu/toanha.txt", POINT{ 13, 38 }, lightyellow);
	CCONSOLE::drawGraphics("menu/toanha.txt", POINT{ 66, 38 }, lightyellow);
	CCONSOLE::drawGraphics("menu/xe.txt", POINT{ 119, 29 }, red);
	CCONSOLE::drawGraphics("menu/xe.txt", POINT{ 1, 29 }, red);
}

void CMENU::drawOption(const char* str, POINT point, int color)
{
	CCONSOLE::GotoXY(point.x, point.y);
	CCONSOLE::setColor(color);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	cerr << str;
}

void CMENU::checkKey()
{
	CCONSOLE::fixCur(false);
	short y_axis = 24;
	drawOption("NEW GAME ", POINT{ 62,24 }, 113);
	int temp = 0;
	while (1)
	{
		temp = toupper(_getch());
		// go down
		if (temp == 80) // down arrow
		{
			drawOption("NEW GAME ", POINT{ 62,24 }, lightaqua);
			drawOption("LOAD GAME ", POINT{ 62,26 }, lightaqua);
			drawOption("SETTINGS ", POINT{ 62,28 }, lightaqua);
			drawOption("ABOUT ", POINT{ 62,30 }, lightaqua);
			drawOption("EXIT ", POINT{ 62,32 }, lightaqua);
			if (y_axis < 32) y_axis += 2;
			else y_axis = 24;
			// draw effect
			if (y_axis == 24) { drawOption("NEW GAME ", POINT{ 62,24 }, 113); }
			if (y_axis == 26) { drawOption("LOAD GAME ", POINT{ 62,26 }, 113); }
			if (y_axis == 28) { drawOption("SETTINGS ", POINT{ 62,28 }, 113); }
			if (y_axis == 30) { drawOption("ABOUT ", POINT{ 62,30 }, 113); }
			if (y_axis == 32) { drawOption("EXIT ", POINT{ 62,32 }, 113); }

		}
		// go up
		if (temp == 72) // up arrow
		{
			drawOption("NEW GAME ", POINT{ 62,24 }, lightaqua);
			drawOption("LOAD GAME ", POINT{ 62,26 }, lightaqua);
			drawOption("SETTINGS ", POINT{ 62,28 }, lightaqua);
			drawOption("ABOUT ", POINT{ 62,30 }, lightaqua);
			drawOption("EXIT ", POINT{ 62,32 }, lightaqua);
			if (y_axis > 24) y_axis -= 2;
			else y_axis = 32;
			if (y_axis == 24) { drawOption("NEW GAME ", POINT{ 62,24 }, 113); }
			if (y_axis == 26) { drawOption("LOAD GAME ", POINT{ 62,26 }, 113); }
			if (y_axis == 28) { drawOption("SETTINGS ", POINT{ 62,28 }, 113); }
			if (y_axis == 30) { drawOption("ABOUT ", POINT{ 62,30 }, 113); }
			if (y_axis == 32) { drawOption("EXIT ", POINT{ 62,32 }, 113); }
		}
		// NEW GAME
		if (y_axis == 24)
		{
			if (temp == 13) // Enter
			{
				option->setGameState(1);
				return;
			}
		}
		// LOAD GAME
		if (y_axis == 26)
		{
			if (temp == 13) // Enter
			{
				option->setLoadState(1);
				return;
			}
		}
		// SETTINGS
		if (y_axis == 28)
		{
			if (temp == 13) // Enter
			{
				option->setSettingMenu(1);
				return;
			}
		}
		// ABOUT
		if (y_axis == 30)
		{
			if (temp == 13) // Enter
			{
				option->setAboutMenu(1);
				return;
			}
		}

		//EXIT
		if (y_axis == 32)
		{
			if (temp == 13) // Enter
			{
				option->setExitState(1);
				return;
			}
		}
	}
}

/* y-axis
24: NEW GAME
26: LOAD GAME
28: SETTINGS
30: ABOUT
32: EXIT*/


// Handle about menu
void CMENU::AboutHandle()
{
	CCONSOLE::GotoXY(60, 33);
	CCONSOLE::setColor(10);
	cout << "<-- BACK(Q)";
	CCONSOLE::drawGraphics("menu/about.txt", POINT{ 50,24 }, white);
	while (true)
	{
		if (CCONSOLE::GetKeyState(Q))
		{
			option->setAboutMenu(0);
			break;
		}
	}
}

// Handle load option
void CMENU::LoadHandle(bool flag)
{
	if (flag)
	{
		CCONSOLE::drawGraphics("menu/khungFile.txt", POINT{ 48,24 }, brightwhite);
		CCONSOLE::GotoXY(50, 28);
		CCONSOLE::fixCur(true);
	}
	else
	{
		CCONSOLE::drawGraphics("gameboard/khungFile.txt", POINT{ 128, 37 }, yellow);
		CCONSOLE::GotoXY(130, 41);
		CCONSOLE::fixCur(true);
	}
}

// Handle setting option
void CMENU::SettingHandle()
{
	CCONSOLE::drawGraphics("menu/settingMenu.txt", POINT{ 48,24 }, brightwhite);
	short y_axis = 26; int temp = 0;
	drawOption("1. Level game", POINT{ 58,26 }, lightgreen);
	while (1)
	{
		temp = toupper(_getch());
		// go down
		if (temp == 80) // down arrow
		{
			drawOption("1. Level game", POINT{ 58,26 }, white);
			drawOption("2. Music setting", POINT{ 58,28 }, white);
			drawOption("3. Back", POINT{ 58,30 }, white);
			if (y_axis < 30) y_axis += 2;
			else y_axis = 26;
			// draw effect
		    if (y_axis == 26) { drawOption("1. Level game", POINT{ 58,26 }, lightgreen); }
		    if (y_axis == 28) { drawOption("2. Music setting", POINT{ 58,28 }, lightgreen); }
		    if (y_axis == 30) { drawOption("3. Back", POINT{ 58,30 }, lightgreen); }
		}
		// go up
		if (temp == 72) // up arrow
		{
			drawOption("1. Level game", POINT{ 58,26 }, white);
			drawOption("2. Music setting", POINT{ 58,28 }, white);
			drawOption("3. Back", POINT{ 58,30 }, white);
			if (y_axis > 26) y_axis -= 2;
			else y_axis = 30;
			if (y_axis == 26) { drawOption("1. Level game", POINT{ 58,26 }, lightgreen); }
			if (y_axis == 28) { drawOption("2. Music setting", POINT{ 58,28 }, lightgreen); }
			if (y_axis == 30) { drawOption("3. Back", POINT{ 58,30 }, lightgreen); }
		}
		// handle keypress
		if (y_axis == 26)
		{
			if (temp == 13)
			{
				levelSetting();
			}
		}
		else if (y_axis == 28) // Setting music
		{
			if (temp == 13)
			{
				soundSetting();
			}
		}
		else if (y_axis == 30) // Back to menu
		{
			if (temp == 13) // Enter
			{
				option->setSettingMenu(0);
				break;
			}
		}
		
	}
}


// sound setting
void CMENU::soundSetting()
{
	CCONSOLE::drawGraphics("menu/smallBox.txt", POINT{ 76,27 }, white);
	char c;
	do {
		if (game_sound_state == 1) {
			CCONSOLE::GotoXY(78, 28);
			cout << "«";
			CCONSOLE::setColor(lightaqua);
			cout << " O N ";
			CCONSOLE::setColor(white);
			cout << "»";
		}
		else {
			CCONSOLE::GotoXY(78, 28);
			cout << "«";
			CCONSOLE::setColor(red);
			cout << " OFF ";
			CCONSOLE::setColor(white);
			cout << "»";
		}

		c = _getch();
		if (c == -32) {
			c = _getch();
			if (c == 77 || c == 75) // 77: key right_arrow, 75: key left_arrow
			{
				game_sound_state *= (-1);
				if (game_sound_state == 1) CCONSOLE::playMusic("background");
				else CCONSOLE::turnOffMusic("background");
			}
			
		}
	} while (c != 13); // enter
	CCONSOLE::removeSpace(POINT{ 76,27 }, POINT{ 89,30 }); // remove sound setting box
}

// level setting
void CMENU::levelSetting()
{
	// initializing
	int level = 1;
	CCONSOLE::drawGraphics("menu/smallBox.txt", POINT{ 76,25 }, lightaqua);
	CCONSOLE::setColor(lightyellow);
	CCONSOLE::GotoXY(78, 26);
	cout << "«";
	CCONSOLE::setColor(lightred);
	cout << "  " << level << "  ";
	CCONSOLE::setColor(lightyellow);
	cout << "»";
	CCONSOLE::GotoXY(80, 28); CCONSOLE::setColor(gray); cout << "Choose this level? ";
	CCONSOLE::GotoXY(84, 29); CCONSOLE::setColor(gray); cout << "Yes";
	CCONSOLE::setColor(gray); cout << "/No";
	// capture key press
	char c;
	do
	{
		c = _getch();
		if (c == -32)
		{
			c = _getch();
			if (c == 77) // key right_arrow
			{
				level = level % MAX_LEVEL + 1;
				CCONSOLE::GotoXY(79, 26);
				CCONSOLE::setColor(lightred);
				cout << "  " << level << "  ";
			}
			else if (c == 75) // key left_arrow 
			{
				--level;
			   	level = level == 0 ? MAX_LEVEL : level;
				CCONSOLE::GotoXY(79, 26);
				CCONSOLE::setColor(lightred);
				cout << "  " << level << "  ";
			}
			else if (c == 80) //key down_arrow
			{
				CCONSOLE::GotoXY(80, 28); CCONSOLE::setColor(lightpurple); cout << "Choose this level? ";
				CCONSOLE::GotoXY(84, 29); CCONSOLE::setColor(lightgreen); cout << "Yes";
				CCONSOLE::setColor(brightwhite); cout << "/No";
				bool choice = 1;
				char tmp;
				do
				{
					tmp = _getch();
					if (tmp == -32)
					{
						tmp = _getch();
						if (tmp == 77) // key right_arrow  
						{
							CCONSOLE::GotoXY(84, 29); CCONSOLE::setColor(brightwhite); cout << "Yes/";
							CCONSOLE::setColor(lightred); cout << "No";
							choice = 0;
						}
						else if (tmp == 75) // key left_arrow
						{
							CCONSOLE::GotoXY(84, 29); CCONSOLE::setColor(lightgreen); cout << "Yes";
							CCONSOLE::setColor(brightwhite); cout << "/No";
							choice = 1;
						}
					}
				} while (tmp != 13);
				if (choice)
				{
					option->setLevelGame(level);
					CCONSOLE::GotoXY(79, 30); CCONSOLE::setColor(lightred); cout << "Set up successfully!";
					Sleep(1200);
					CCONSOLE::removeSpace(POINT{ 76,25 }, POINT{ 99,31});
					return;
				}
				else
				{
					CCONSOLE::GotoXY(80, 28); CCONSOLE::setColor(gray); cout << "Choose this level? ";
					CCONSOLE::GotoXY(84, 29); CCONSOLE::setColor(gray); cout << "Yes";
					CCONSOLE::setColor(gray); cout << "/No";
				}
				} 
			else if (c == 72) // key up_arrow
			{
				CCONSOLE::GotoXY(80, 28); CCONSOLE::setColor(gray); cout << "Choose this level? ";
				CCONSOLE::GotoXY(84, 29); CCONSOLE::setColor(gray); cout << "Yes";
				CCONSOLE::setColor(gray); cout << "/No";
			}
		}
	} while (c != 13); // enter
	CCONSOLE::removeSpace(POINT{ 76,25 }, POINT{ 98,30 });
}


// reset Option
void CMENU::resetOption()
{
	option->setGameState(0);
	option->setLevelGame(1);
	option->setLoadState(0);
	option->setExitState(0);
	option->setAboutMenu(0);
}