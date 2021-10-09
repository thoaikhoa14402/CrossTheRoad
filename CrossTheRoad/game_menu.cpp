#include"game_menu.h"

// CLASS GAME MENU


void GameMenu::drawTitle()
{
	SetConsoleOutputCP(65001);
	cout << "\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	ConsoleDesign::GotoXY(50, 1);
	cout << "University Of Science";
	ConsoleDesign::GotoXY(55, 3);
	cout << "---TEAM 5---";
	ConsoleDesign::GotoXY(0, 6);
		/*cout<< "	██████╗██████╗  ██████╗ ███████╗███████╗    ████████╗██╗  ██╗███████╗    ██████╗  ██████╗  █████╗ ██████╗      " << "\n"
			<< "	██╔════╝██╔══██╗██╔═══██╗██╔════╝██╔════╝    ╚══██╔══╝██║  ██║██╔════╝    ██╔══██╗██╔═══██╗██╔══██╗██╔══██╗    " << "\n"
			<< "	██║     ██████╔╝██║   ██║███████╗███████╗       ██║   ███████║█████╗      ██████╔╝██║   ██║███████║██║  ██║    " << "\n"
			<< "	██║     ██╔══██╗██║   ██║╚════██║╚════██║       ██║   ██╔══██║██╔══╝      ██╔══██╗██║   ██║██╔══██║██║  ██║    " << "\n"
			<< "        ╚██████╗██║  ██║╚██████╔╝███████║███████║       ██║   ██║  ██║███████╗    ██║  ██║╚██████╔╝██║  ██║██████╔╝    " << "\n"
			<< "	╚═════╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚══════╝        ╚═╝   ╚═╝  ╚═╝╚══════╝    ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝╚═════╝     " << "\n";*/
	// CROSS
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout<<"  ██████╗██████╗  ██████╗ ███████╗███████╗   " << "\n"
		<<"  ██╔════╝██╔══██╗██╔═══██╗██╔════╝██╔════╝  " << "\n"
		<<"  ██║     ██████╔╝██║   ██║███████╗███████╗  " << "\n"
		<<"  ██║     ██╔══██╗██║   ██║╚════██║╚════██║  " "\n"
		<<"  ╚██████╗██║  ██║╚██████╔╝███████║███████║  " "\n"
		<<"  ╚═════╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚══════╝  " "\n";
	
	// THE
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	ConsoleDesign::GotoXY(51, 6);
	cout << "████████╗██╗  ██╗███████╗ " << "\n";
	ConsoleDesign::GotoXY(51, 7);
	cout << "╚══██╔══╝██║  ██║██╔════╝ " << "\n";
	ConsoleDesign::GotoXY(54, 8);
	cout << "██║   ███████║█████╗   " << "\n";
	ConsoleDesign::GotoXY(54, 9);
	cout << "██║   ██╔══██║██╔══╝   " << "\n";
	ConsoleDesign::GotoXY(54, 10);
	cout << "██║   ██║  ██║███████╗ " << "\n";
	ConsoleDesign::GotoXY(54, 11);
	cout << "╚═╝   ╚═╝  ╚═╝╚══════╝ " << "\n";

	// ROAD
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	ConsoleDesign::GotoXY(85, 6);
	cout << "██████╗  ██████╗  █████╗ ██████╗" << "\n";
	ConsoleDesign::GotoXY(85, 7);
	cout << " ██╔══██╗██╔═══██╗██╔══██╗██╔══██╗" << "\n";
	ConsoleDesign::GotoXY(85, 8);
	cout << " ██████╔╝██║   ██║███████║██║  ██║" << "\n";
	ConsoleDesign::GotoXY(85, 9);
	cout << " ██╔══██╗██║   ██║██╔══██║██║  ██║" << "\n";
	ConsoleDesign::GotoXY(85, 10);
	cout << " ██║  ██║╚██████╔╝██║  ██║██████╔╝ " << "\n";
	ConsoleDesign::GotoXY(85, 11);
    cout <<" ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝╚═════╝" << "\n";
	// straight-line
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "------------------------------------------------------------------------------------------------------------------------\n";
}

void GameMenu::drawMenu()
{
	SetConsoleOutputCP(65001);  // utf-8
	cout
		<< R"(                                  _          _     _                   _                     )" << "\n"
		<< R"( 	                         | |   ___  | |_  ( )  ___     _ __   | |   __ _   _   _ 	 )" << "\n"
		<< R"(	                         | |  / _ \ | __| |/  / __|   | '_ \  | |  / _` | | | | |	)" << "\n"
		<< R"(	                         | | |  __/ | |_      \__ \   | |_) | | | | (_| | | |_| |	)" << "\n"
		<< R"(	                         |_|  \___|  \__|     |___/   | .__/  |_|  \__,_|  \__, |    )" << "\n"
		<< R"(                                                              |_|                  |___/     )" << "\n\n";
	cout
		<< "                                       .────────────────────────────────────.                                  \n"
		<< "                                       │                                    │                                  \n"
		<< "                                       │            NEW GAME   [P]          │                                  \n"
		<< "                                       │                                    │                                  \n"
		<< "                                       │            LOAD GAME  [T]          │                                  \n"
		<< "                                       │                                    │                                  \n"
		<< "                                       │            SETTINGS   [S]          │                                  \n"
		<< "                                       │                                    │                                  \n"
		<< "                                       │            ABOUT      [A]          │                                  \n"
		<< "                                       │                                    │                                  \n"
		<< "                                       │            EXIT       [E]          │                                  \n"
		<< "                                       │                                    │                                  \n"
		<< "                                       │____________________________________│                                  \n";
	//GotoXY(48, 23);
	//cout << "test";
	//drawOption("NEW GAME  [P]", POINT{ 45,22 }, 7);
	
}

void GameMenu::drawOption(const char*str, POINT point, int color)
{
	ConsoleDesign::GotoXY(point.x, point.y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	cerr << str;
}

void GameMenu::checkKey()
{
	ConsoleDesign::fixCur(false);
	short y_axis = 22;
	drawOption("NEW GAME ", POINT{ 52,22 }, 113);
	while (1)
	{
		// go down
		if (ConsoleDesign::GetKeyState(VK_DOWN))
		{
			drawOption("NEW GAME ", POINT{ 52,22 }, 7);
			drawOption("LOAD GAME ", POINT{ 52,24 }, 7);
			drawOption("SETTINGS ", POINT{ 52,26 }, 7);
			drawOption("ABOUT ", POINT{ 52,28 }, 7);
			drawOption("EXIT ", POINT{ 52,30 }, 7);
			if (y_axis < 30) y_axis += 2;
			else y_axis = 22;
			// draw effect
			if (y_axis == 22) { drawOption("NEW GAME ", POINT{ 52,22 }, 113); }
			if (y_axis == 24) { drawOption("LOAD GAME ", POINT{ 52,24 }, 113); }
			if (y_axis == 26) { drawOption("SETTINGS ", POINT{ 52,26 }, 113); }
			if (y_axis == 28) { drawOption("ABOUT ", POINT{ 52,28 }, 113); }
			if (y_axis == 30) { drawOption("EXIT ", POINT{ 52,30 }, 113); }
		}
		// go up
		if (ConsoleDesign::GetKeyState(VK_UP))
		{
			drawOption("NEW GAME ", POINT{ 52,22 }, 7);
			drawOption("LOAD GAME ", POINT{ 52,24 }, 7);
			drawOption("SETTINGS ", POINT{ 52,26 }, 7);
			drawOption("ABOUT ", POINT{ 52,28 }, 7);
			drawOption("EXIT ", POINT{ 52,30 }, 7);
			if (y_axis > 22) y_axis -= 2;
			else y_axis = 30;
			if (y_axis == 22) { drawOption("NEW GAME ", POINT{ 52,22 }, 113); }
			if (y_axis == 24) { drawOption("LOAD GAME ", POINT{ 52,24 }, 113); }
			if (y_axis == 26) { drawOption("SETTINGS ", POINT{ 52,26 }, 113); }
			if (y_axis == 28) { drawOption("ABOUT ", POINT{ 52,28 }, 113); }
			if (y_axis == 30) { drawOption("EXIT ", POINT{ 52,30 }, 113); }
		}
	}
	
	/*drawOption("SETTINGS ", POINT{ 52,27 }, 113);
	drawOption("ABOUT ", POINT{ 52,29 }, 113);
	drawOption("EXIT ", POINT{ 52,31 }, 113);*/
}

