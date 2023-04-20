#include"CGAME.h"
#include"CCONSOLE.h"
#include"CMENU.h"
#include"COPTION.h"

int main()
{
	CCONSOLE console; // Init Object Console
	COPTION option; // Init Object Option
	CMENU menu(&option); // Init  Object menu
	CGAME* game = new CGAME; // Init pointer game to handle CGAME
	int temp = 0; // variable to capture keypress
	console.ConsoleHandle(); // Console Handle
	short start_game = 0; // Flag to start game
	while (1)
	{
		menu.runMenu(); // Menu Handle
		if (option.newGame()) // New Game
		{
			game->setLevelGame(option.getLevelGameSetting());
			game->initGameGraphics();
			start_game = 1; // flag to start new game
		}
		else if (option.loadGame()) // Load Game
		{
			menu.LoadHandle(1);
			string file_name;
			getline(cin, file_name);
			fstream infile;
			infile.open("saved_game/" + file_name + ".bin", ios::in | ios::binary);
			if (!infile)
			{
				CCONSOLE::GotoXY(50, 30); CCONSOLE::setColor(lightred); cout << "Cannot find this name! ";
				CCONSOLE::fixCur(0);
				Sleep(1500);
				infile.clear();
				// clean Key Press
				CCONSOLE::cleanKeyPress();
				option.setLoadState(0);
			}
			else 
			{
				infile.close();
				game->loadGame(file_name);
				// clean Key Press
				CCONSOLE::cleanKeyPress();
				start_game = 1; // flag to start load game
			}
			
		}
		else if (option.aboutMenu()) // About 
		{
			menu.AboutHandle();
			
		}
		else if (option.settingMenu()) // Setting 
		{
			menu.SettingHandle();
		}
		else if (option.exitGame()) // Exit game
		{
			delete game;
			game = nullptr;
			return 0;
		}

		if (start_game != 0) // New Game or Load Game
		{
			thread t1(&CGAME::runGame, game); // Run Thread Game
		    // Capture key-pressed from user
			while (1)
			{
				temp = toupper(_getch());
				if (!game->getPeople().isDead())
				{
					if (temp == 27) // ESC
					{
						game->exitGame(t1); // Exit game
						delete game;
						game = nullptr;
						return 0;
					}
					else if (temp == 'P') // Pause game
					{
						game->pauseGame();
					}
					else if (temp == 'E') // Resume game
					{
						if (!game->isRunning())
						{
							game->resumeGame();
							t1.join();
							t1 = thread(&CGAME::runGame, game);
						}

					}
					else if (temp == 'L') // Save game
					{
						game->pauseGame(); // pause game
						t1.join(); // Join thread
						// Handle Save Game
						CCONSOLE::drawGraphics("gameboard/khungFile.txt", POINT{ 128, 37 }, yellow); 
						CCONSOLE::GotoXY(130, 41);
						CCONSOLE::fixCur(true);
						CCONSOLE::setColor(brightwhite);
						string file_name; getline(cin, file_name);  // input file name
						game->saveGame(file_name); // save game
						CCONSOLE::GotoXY(130, 43); CCONSOLE::setColor(lightred); cout << "Successfully!";
						CCONSOLE::fixCur(0);
						Sleep(1500);
						CCONSOLE::removeSpace(POINT{ 128,37 }, POINT{ 166,46 });
						// Resume Game & Re-create thread
						game->resumeGame();
						t1 = thread(&CGAME::runGame, game);
					}
					else if (temp == 'T') // Load game
					{
						game->pauseGame(); // Pause game
						t1.join(); // Join thread
						// Handle Load game
						menu.LoadHandle(0); 
						CCONSOLE::setColor(brightwhite);
						string file_name;
						getline(cin, file_name);
						fstream infile;
						infile.open("saved_game/" + file_name + ".bin", ios::in | ios::binary);
						if (!infile)
						{
							CCONSOLE::GotoXY(130, 43); CCONSOLE::setColor(lightred); cout << "Cannot find this name! ";
							CCONSOLE::fixCur(0);
							Sleep(1500);
							CCONSOLE::removeSpace(POINT{ 128,37 }, POINT{ 166,46 });
							infile.clear();
							// clean key-pressed
							CCONSOLE::cleanKeyPress();
						}
						else
						{
							infile.close();
							game->loadGame(file_name);
							// clean key-pressed
							CCONSOLE::cleanKeyPress();
						}
						// Resume game & Re-create thread
						game->resumeGame(); 
						t1 = thread(&CGAME::runGame, game);
					}
					else if (temp == 'B') // Back to menu
					{
						game->exitGame(t1); // Exit game
						// Delete memory
						if (game != nullptr)
						{
							delete game;
							game = nullptr;
						}
						// Init new pointer game
						game = new CGAME;
						CCONSOLE::sizeEdit(1100, 800); // Set screen to old size (size of menu)
						system("cls");
						menu.resetOption(); // Reset option
						start_game = 0; // Turn off flag start game
						if (game_sound_state == 1) CCONSOLE::playMusic("background");
						break;
					}
					else if (temp == 'M') // Turn on/off game music
					{
						game_sound_state *= -1;
					}
				}
				else
				{
					if (temp == 'Y' && !game->isRunning()) // Renew game
					{
						game->resetGame(); // Reset game
						t1.join(); // Join thread
						t1 = thread(&CGAME::runGame, game); // Re-create thread
					}
					else if (temp == 'E' && !game->isRunning()) // Exit game
					{
						game->exitGame(t1); // Exit game
						// Delete memory
						delete game;
						game = nullptr;
						return 0;
					}
					else if (temp == 'B' && !game->isRunning()) // Back to menu
					{
						game->exitGame(t1); // Exit game
						// Delete memory
						if (game != nullptr)
						{
							delete game;
							game = nullptr;
						}
						// Init new pointer game
						game = new CGAME;
						CCONSOLE::sizeEdit(1100, 800); // Set screen to old size (size of menu)
						system("cls");
						menu.resetOption(); // Reset option
						start_game = 0; // Turn off flag start game
						if (game_sound_state == 1) CCONSOLE::playMusic("background");
						break;
					}
					else if (temp == 27) // ESC - Exit game
					{
						game->exitGame(t1); // Exit game
						delete game;
						game = nullptr;
						return 0;
					}
				}
			}
		}
	}
	system("pause > nul");
	return 0;
}
