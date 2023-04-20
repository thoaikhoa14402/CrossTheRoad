#include "COPTION.h"
// Constructor
COPTION::COPTION()
{
	game_state = 0;
	load_state = 0;
	level_game = 1;
	about_mn = 0;
	play_music = 0;
	setting_mn = 0;
	exit_game = 0;
}
// Destructor
COPTION::~COPTION()
{

}

// getter
bool COPTION::newGame()
{
	return game_state;
}

bool COPTION::loadGame()
{
	return load_state;
}

int  COPTION::levelGame()
{
	return level_game;
}
bool COPTION::exitGame()
{
	return exit_game;
}

bool COPTION::aboutMenu()
{
	return about_mn;
}

bool COPTION::settingMenu()
{
	return setting_mn;
}
// setter
void COPTION::setGameState(bool game_state)
{
	this->game_state = game_state;
}
void COPTION::setLevelGame(int level_game)
{
	this->level_game = level_game;
}
void COPTION::setLoadState(bool load_state)
{
	this->load_state = load_state;
}
void COPTION::setExitState(bool exit_game)
{
	this->exit_game = exit_game;
}
void COPTION::setAboutMenu(bool about_mn)
{
	this->about_mn = about_mn;
}

void COPTION::setSettingMenu(bool setting_mn)
{
	this->setting_mn = setting_mn;
}

// get Level Game Setting
int COPTION::getLevelGameSetting()
{
	return level_game;
}