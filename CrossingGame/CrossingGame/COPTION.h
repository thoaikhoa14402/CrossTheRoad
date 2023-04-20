#pragma once

class COPTION
{
private:
	bool game_state;
	int level_game;
	bool load_state;
	bool play_music;
	bool exit_game;
	bool about_mn;
	bool setting_mn;
public:
	COPTION();
	~COPTION();
	// getter
	bool newGame();
	bool loadGame();
	int  levelGame();
	bool exitGame();
	bool aboutMenu();
	bool settingMenu();
	// setter
	void setGameState(bool);
	void setLevelGame(int);
	void setLoadState(bool);
	void setExitState(bool);
	void setAboutMenu(bool);
	void setSettingMenu(bool);
	// get level game
	int getLevelGameSetting();
};

