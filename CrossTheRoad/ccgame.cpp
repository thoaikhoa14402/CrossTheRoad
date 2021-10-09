#pragma once
#include"ccgame.h"

CGAME::CGAME() {
	// console initializing
	ConsoleDesign::FixConsoleWindow();
	ConsoleDesign::disableSelection();
	ConsoleDesign::sizeEdit(1000, 700);
    ConsoleDesign::editFontSizeConsole(); // responsive
	ConsoleDesign::SetBufferSize();
	ConsoleDesign::fixCur(false);
	// menu
	GameMenu::drawTitle(); // draw title "cross the road"
	GameMenu::drawMenu(); // draw menu form
	GameMenu::checkKey(); // check key pressed by player
}

CGAME::~CGAME() {

}