#pragma once
#include"CTRUCK.h"
#include"CCAR.h"
#include"CBIRD.h"
#include"CDINOSAUR.h"
#include"CPEOPLE.h"
#include"CTRAFFICLIGHT.h"
#include<math.h>
#include<vector>
#include<thread>
#pragma pack(push, 1)

class CGAME
{
private:
	// List of Objects
	vector<CTRUCK*> list_trucks;
	vector<CCAR*> list_cars;
	vector<CBIRD*>list_birds;
	vector<CDINOSAUR*>list_dinosaurs;
	vector<CPEOPLE> list_people;
	CPEOPLE cn;
	// Traffic light
	CTRAFFICLIGHT<CTRUCK> tl_trucks;
	CTRAFFICLIGHT<CCAR> tl_cars;
	bool IS_RUNNING; // check game is running or not
	int level; // level game
	int score; // score game
public:
	CGAME(); // Constructor
	~CGAME(); // Destructor

	void runGame(); // Run Game

	// Initialize Game Graphics
	void initGameGraphics();
	void initListOfPeople();

	// Update position of people
	void updatePosOfPeople();

	// Update position of objects
	void updatePosOfVehicle();
	void updatePosOfAnimal();
	template<class T>
	void updatePosOfInstance(vector<T*>&);
	// Check valid distance between 2 object
	template<class Obj>
	bool isValidDistance(Obj*&, Obj*&);

	// Update game score
	void updateGameScore();

	// Game over
	void gameOver();
	void deadEffect();

	// Game winning
	void gameWinning();
	void victoryEffect();

	bool isRunning(); // check running state

	void resetGame(); // Reset game
	void pauseGame(); // Pause game
	void resumeGame();// Resume Game
	void loadGame(string); // Load game
	void saveGame(string); // Save game
	void exitGame(thread& t); // Exit game

	void setLevelGame(int); // Set level game
	CPEOPLE getPeople(); // Get people
};
#pragma comment(lib, "winmm.lib")
#pragma pack(pop) 