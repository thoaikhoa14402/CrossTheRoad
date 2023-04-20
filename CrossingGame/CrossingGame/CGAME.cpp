#include"CGAME.h"

// Constructor
CGAME::CGAME()
{
	IS_RUNNING = true;
	level = 1;
	score = 0;
	// object
	cn = CPEOPLE(55, 32);
	for (int i = 1; i <= 5; i++)
	{
		list_cars.push_back(new CCAR(2, 22));
		list_trucks.push_back(new CTRUCK(104, 27));
		list_birds.push_back(new CBIRD(2, 12));
		list_dinosaurs.push_back(new CDINOSAUR(2, 16));
	}
	// traffic light
	tl_trucks = CTRAFFICLIGHT<CTRUCK>(20, 15);
	tl_cars = CTRAFFICLIGHT<CCAR>(30, 15);
}

// Destructor
CGAME::~CGAME()
{
	for (int i = 0; i < 5; i++)
	{
		delete list_cars[i];
		list_cars[i] = nullptr;
		delete list_trucks[i];
		list_trucks[i] = nullptr;
		delete list_birds[i];
		list_birds[i] = nullptr;
		delete list_dinosaurs[i];
		list_dinosaurs[i] = nullptr;
	}
	list_cars.clear();
	list_trucks.clear();
	list_birds.clear();
	list_dinosaurs.clear();
}



// Initialize game graphics
void CGAME::initGameGraphics()
{
	// handle console
	CCONSOLE::fixCur(false);
	system("cls");
	CCONSOLE::setColor(0);
	CCONSOLE::sizeEdit(1400, 800);
	CCONSOLE::initLoadingBar(1); //Init loading bar
	// Draw graphics
	CCONSOLE::drawGraphics("gameboard/gameboard.txt", POINT{ 1, 5 }, white, 30); // gameboard
	CCONSOLE::drawGraphics("gameboard/game_option.txt", POINT{ 128,12}, lightaqua); // option
	CCONSOLE::drawGraphics("gameboard/start.txt", POINT{ 2,31 }, aqua); // start
	CCONSOLE::drawGraphics("gameboard/finish.txt", POINT{ 2,6 }, aqua); // finish
	CCONSOLE::drawGraphics("gameboard/uCanDoIt.txt", POINT{ 15,38 }, aqua);
	// SCORE
	if (score == 0) CCONSOLE::drawGraphics("gameboard/score_0.txt", POINT{ 142,1 }, yellow);
	else if (score == 100) CCONSOLE::drawGraphics("gameboard/score_100.txt", POINT{ 132,1 }, yellow);
	else if (score == 200) CCONSOLE::drawGraphics("gameboard/score_200.txt", POINT{ 132,1 }, yellow);
	else if (score == 300) CCONSOLE::drawGraphics("gameboard/score_300.txt", POINT{ 132,1 }, yellow);
	else if (score == 400) CCONSOLE::drawGraphics("gameboard/score_400.txt", POINT{ 132,1 }, yellow);
	// LEVEL
	if (level == 1) CCONSOLE::drawGraphics("gameboard/lv1.txt", POINT{ 45,1 }, aqua); // lv1
	else if (level == 2) CCONSOLE::drawGraphics("gameboard/lv2.txt", POINT{ 45,1 }, aqua); // lv2 
	else if (level == 3) CCONSOLE::drawGraphics("gameboard/lv3.txt", POINT{ 45,1 }, aqua); // lv3
	else if (level == 4) CCONSOLE::drawGraphics("gameboard/lv4.txt", POINT{ 45,1 }, aqua); // lv4 
	else if (level == 5) CCONSOLE::drawGraphics("gameboard/lv5.txt", POINT{ 45,1 }, aqua); // lv5
}

// Init list of people
void CGAME::initListOfPeople()
{
	int n = list_people.size();
	if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			CCONSOLE::drawGraphics("cgame/cpeople.txt", POINT{ list_people[i].getX(),list_people[i].getY() }, lightred);
		}
	}
}

// Update position of people
void CGAME::updatePosOfPeople()
{

	if (CCONSOLE::GetKeyState(W))
	{
		if (game_sound_state == 1) CCONSOLE::playMusic("move");
		cn.goUp();
	}
	else if (CCONSOLE::GetKeyState(A))
	{
		if (game_sound_state == 1) CCONSOLE::playMusic("move");
		cn.goLeft();
	}
	else if (CCONSOLE::GetKeyState(S))
	{
		if (game_sound_state == 1) CCONSOLE::playMusic("move");
		cn.goDown();
	}
	else if (CCONSOLE::GetKeyState(D))
	{
		if (game_sound_state == 1) CCONSOLE::playMusic("move");
		cn.goRight();
	}
}

// Update position Vehicle (car, truck)
void CGAME::updatePosOfVehicle()
{
	updatePosOfInstance(list_cars); // update pos of cars
	updatePosOfInstance(list_trucks); // update pos of trucks
}

// Update position Animal (bird,dino)
void CGAME::updatePosOfAnimal()
{
	updatePosOfInstance(list_birds); // update pos of birds
	Sleep(20);
	updatePosOfInstance(list_dinosaurs); // update pos of dinosaurs
}


// Update moving of Objects
template<class Obj>
void CGAME::updatePosOfInstance(vector<Obj*>& ins)
{
	for (int i = 0; i < ins.size(); i++)
	{
		if (ins[i]->getState())  // moving state is true ==> execute
		{
			ins[i]->Move();
			if (cn.isImpact(ins[i]))
			{
				if (game_sound_state == 1) ins[i]->Tell();
				cn.setState(false);
			}
		}
		else
		{
			for (int j = 0; j < ins.size(); j++)
			{
				if (i != j)
				{
					if (ins[j]->getState())
					{
						if (!isValidDistance(ins[i], ins[j]))
						{
							ins[i]->setState(false);
							break;
						}
					}
					else
					{
						if (rand() % (30 / level))
						{
							ins[i]->setState(true);
						}
					}
				}
			}
		}
	}
}

// Check valid distance between 2 objects
template<class Obj>
bool CGAME::isValidDistance(Obj*& ins1, Obj*& ins2)
{
	if (abs(ins2->getX() - ins1->getX()) < 25) return false;
	return true;
}


// Check running state
bool CGAME::isRunning()
{
	return IS_RUNNING;
}



// Game over
void CGAME::gameOver()
{
	// reaper
	if (game_sound_state == 1) CCONSOLE::playMusic("gameOver"); // sound
	system("cls");
	int x = 10, y = 15;
	int i = 1;
	CCONSOLE::drawGraphics("gameboard/uDied.txt", POINT{ 50,2 }, red);
	CCONSOLE::drawGraphics("gameboard/deadpeople.txt", POINT{ 100, 28 }, white); // dead people
	while (x <= 140)
	{
		CCONSOLE::removeSpace(POINT{ x - 10,y }, POINT{ x,y + 16 });
		CCONSOLE::drawGraphics("gameboard/reaper.txt", POINT{ x, y }, i++);
		x += 10;
		Sleep(300);
	}
	// game over
	system("cls");
	CCONSOLE::drawGraphics("gameboard/gameover.txt", POINT{ 42,12 }, lightaqua);
	IS_RUNNING = false;
}

// Game winning
void CGAME::gameWinning()
{
	system("cls");
	CCONSOLE::drawGraphics("gameboard/win.txt", POINT{ 52,12 }, lightyellow);
}

// Effect when people is impacted
void CGAME::deadEffect()
{
	for (int i = 0; i < 5; i++)
	{
		CCONSOLE::drawGraphics("cgame/cpeople.txt", POINT{ cn.getX(), cn.getY() }, lightred); // old people
		Sleep(300);
		CCONSOLE::removeSpace(POINT{ cn.getX(), cn.getY() }, POINT{ cn.getX() + cn.getWidth(), cn.getY() + cn.getHeight() });
		CCONSOLE::drawGraphics("gameboard/dizzypeople.txt", POINT{ cn.getX(), cn.getY() - 1 }, lightyellow); // dizzy people
		Sleep(300);
	}
}
// Effect when people finish the challenge
void CGAME::victoryEffect()
{
	for (int i = 0; i < 5; i++)
	{
		CCONSOLE::drawGraphics("gameboard/happypeople.txt", POINT{ cn.getX(), cn.getY() - 1 }, lightyellow); // dizzy people
		Sleep(300);
		CCONSOLE::removeSpace(POINT{ cn.getX(), cn.getY() }, POINT{ cn.getX() + cn.getWidth(), cn.getY() + cn.getHeight() });
		CCONSOLE::drawGraphics("cgame/cpeople.txt", POINT{ cn.getX(), cn.getY() }, lightred); // old people
		Sleep(300);
	}
}

// Update game score
void CGAME::updateGameScore()
{
	CCONSOLE::drawGraphics("cgame/cpeople.txt", POINT{ 55,32 }, lightred);
	if (level == 1)
	{
		score += 100;
		level++;
		CCONSOLE::drawGraphics("gameboard/lv2.txt", POINT{ 45,1 }, aqua);
        CCONSOLE::drawGraphics("gameboard/score_100.txt", POINT{ 132,1 }, yellow);
	}
	else if (level == 2)
	{
		score += 100;
		level++;
		CCONSOLE::drawGraphics("gameboard/lv3.txt", POINT{ 45,1 }, aqua);
		CCONSOLE::drawGraphics("gameboard/score_200.txt", POINT{ 132,1 }, yellow);
	}
	else if (level == 3)
	{
		score += 100;
		level++;
		CCONSOLE::drawGraphics("gameboard/lv4.txt", POINT{ 45,1 }, aqua);
		CCONSOLE::drawGraphics("gameboard/score_300.txt", POINT{ 132,1 }, yellow);
	}
	else if (level == 4)
	{
		score += 100;
		level++;
		CCONSOLE::drawGraphics("gameboard/lv5.txt", POINT{ 45,1 }, aqua);
		CCONSOLE::drawGraphics("gameboard/score_400.txt", POINT{ 132,1 }, yellow);
	}
	else if (level == 5)
	{
		score += 100;
		CCONSOLE::drawGraphics("gameboard/score_500.txt", POINT{ 132,1 }, yellow);
		if (game_sound_state == 1) CCONSOLE::playMusic("clap");
		cn.setState(false);
		victoryEffect();
		gameWinning();
		IS_RUNNING = false;
	}
}
// Set level game
void CGAME::setLevelGame(int level_game)
{
	this->level = level_game;
}




// Pause game
void CGAME::pauseGame()
{
	IS_RUNNING = false;
}
// Resume game
void CGAME::resumeGame()
{
	IS_RUNNING = true;
}


// Reset game
void CGAME::resetGame()
{
	system("cls");
	// delete object
	for (int i = 0; i < 5; i++)
	{
		delete list_cars[i];
		delete list_trucks[i];
		delete list_birds[i];
		delete  list_dinosaurs[i];
	}
	list_people.clear(); // clear list people
	// object
	for (int i = 0; i < 5; i++)
	{
		list_cars[i] = new CCAR(2, 22);
		list_trucks[i] = new CTRUCK(104, 27);
		list_birds[i] = new CBIRD(2, 12);
		list_dinosaurs[i] = new CDINOSAUR(2, 16);
	}

	// Draw graphics
	CCONSOLE::drawGraphics("gameboard/gameboard.txt", POINT{ 1, 5 }, white, 30); // gameboard
	CCONSOLE::drawGraphics("gameboard/game_option.txt", POINT{ 128,12 }, lightaqua); // option
	CCONSOLE::drawGraphics("gameboard/start.txt", POINT{ 2,31 }, aqua); // start
	CCONSOLE::drawGraphics("gameboard/finish.txt", POINT{ 2,6 }, aqua); // finish
	CCONSOLE::drawGraphics("gameboard/uCanDoIt.txt", POINT{ 15,38 }, aqua);
	CCONSOLE::drawGraphics("gameboard/score_0.txt", POINT{ 142,1 }, yellow);

	cn = CPEOPLE(55, 32);
	CCONSOLE::drawGraphics("cgame/cpeople.txt", POINT{ 55,32 }, lightred);
	CCONSOLE::drawGraphics("gameboard/lv1.txt", POINT{ 45,1 }, 3);

	level = 1;
	score = 0;
	IS_RUNNING = true;
}

// Exit game
void CGAME::exitGame(thread& t)
{
	system("cls");
	IS_RUNNING = false;
	t.join();
}


// Save Game
void CGAME::saveGame(string file_name)
{
	string str;
	int n = 5, x = 0, y = 0;
	bool state = 0;
	fstream outfile;
	outfile.open("saved_game/" + file_name + ".bin", ios::out | ios::binary);
	// level & score
	outfile.write((const char*)&level, sizeof(level));
	outfile.write((const char*)&score, sizeof(score));
	outfile.write((const char*)&n, sizeof(n));

	// trucks
	for (int i = 0; i < n; i++)
	{
		x = list_trucks[i]->getX();
		y = list_trucks[i]->getY();
		state = list_trucks[i]->getState();
		outfile.write((const char*)&x, sizeof(x));
		outfile.write((const char*)&y, sizeof(y));
		outfile.write((const char*)&state, sizeof(state));
	}

	// cars
	for (int i = 0; i < n; i++)
	{
		x = list_cars[i]->getX();
		y = list_cars[i]->getY();
		state = list_cars[i]->getState();
		outfile.write((const char*)&x, sizeof(x));
		outfile.write((const char*)&y, sizeof(y));
		outfile.write((const char*)&state, sizeof(state));
	}

	// birds
	for (int i = 0; i < n; i++)
	{
		x = list_birds[i]->getX();
		y = list_birds[i]->getY();
		state = list_birds[i]->getState();
		outfile.write((const char*)&x, sizeof(x));
		outfile.write((const char*)&y, sizeof(y));
		outfile.write((const char*)&state, sizeof(state));
	}

	// dinosaurs
	for (int i = 0; i < n; i++)
	{
		x = list_dinosaurs[i]->getX();
		y = list_dinosaurs[i]->getY();
		state = list_dinosaurs[i]->getState();
		outfile.write((const char*)&x, sizeof(x));
		outfile.write((const char*)&y, sizeof(y));
		outfile.write((const char*)&state, sizeof(state));
	}
	// current people
	x = cn.getX();
	y = cn.getY();
	state = cn.getState();
	outfile.write((const char*)&x, sizeof(x));
	outfile.write((const char*)&y, sizeof(y));
	outfile.write((const char*)&state, sizeof(state));
	// list people
	n = list_people.size();
	outfile.write((const char*)&n, sizeof(n));
	if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			x = list_people[i].getX();
			y = list_people[i].getY();
			outfile.write((const char*)&x, sizeof(x));
			outfile.write((const char*)&y, sizeof(y));
		}
	}
	// traffic light
	bool tl_state = 0; int cnt_time = 0, red_time = 0, green_time = 0;
	// list of trucks
	tl_state = tl_trucks.getTLState();
	cnt_time = tl_trucks.getTime();
	red_time = tl_trucks.getRedTime();
	green_time = tl_trucks.getGreenTime();
	outfile.write((const char*)&tl_state, sizeof(tl_state));
	outfile.write((const char*)&cnt_time, sizeof(cnt_time));
	outfile.write((const char*)&red_time, sizeof(red_time));
	outfile.write((const char*)&green_time, sizeof(green_time));
	// list of cars
	tl_state = tl_cars.getTLState();
	cnt_time = tl_cars.getTime();
	red_time = tl_cars.getRedTime();
	green_time = tl_cars.getGreenTime();
	outfile.write((const char*)&tl_state, sizeof(tl_state));
	outfile.write((const char*)&cnt_time, sizeof(cnt_time));
	outfile.write((const char*)&red_time, sizeof(red_time));
	outfile.write((const char*)&green_time, sizeof(green_time));
	outfile.close();
}

// Load Game
void CGAME::loadGame(string filename)
{
	string str;
	int n = 0, x = 0, y = 0;
	bool state = 0;
	fstream infile;
	infile.open("saved_game/" + filename + ".bin", ios::in | ios::binary);
	// level & score
	infile.read((char*)&level, sizeof(level));
	infile.read((char*)&score, sizeof(score));
	infile.read((char*)&n, sizeof(n));

	// trucks
	for (int i = 0; i < n; i++)
	{
		infile.read((char*)&x, sizeof(x));
		infile.read((char*)&y, sizeof(y));
		infile.read((char*)&state, sizeof(state));
		list_trucks[i]->setX(x);
		list_trucks[i]->setY(y);
		list_trucks[i]->setState(state);
	}

	// cars
	for (int i = 0; i < n; i++)
	{
		infile.read((char*)&x, sizeof(x));
		infile.read((char*)&y, sizeof(y));
		infile.read((char*)&state, sizeof(state));

		list_cars[i]->setX(x);
		list_cars[i]->setY(y);
		list_cars[i]->setState(state);

	}

	// birds
	for (int i = 0; i < n; i++)
	{
		infile.read((char*)&x, sizeof(x));
		infile.read((char*)&y, sizeof(y));
		infile.read((char*)&state, sizeof(state));

		list_birds[i]->setX(x);
		list_birds[i]->setY(y);
		list_birds[i]->setState(state);

	}

	// dinosaurs
	for (int i = 0; i < n; i++)
	{
		infile.read((char*)&x, sizeof(x));
		infile.read((char*)&y, sizeof(y));
		infile.read((char*)&state, sizeof(state));
		list_dinosaurs[i]->setX(x);
		list_dinosaurs[i]->setY(y);
		list_dinosaurs[i]->setState(state);
	}
	// current people
	infile.read((char*)&x, sizeof(x));
	infile.read((char*)&y, sizeof(y));
	infile.read((char*)&state, sizeof(state));
	cn.setX(x);
	cn.setY(y);
	cn.setState(state);
	// list people
	infile.read((char*)&n, sizeof(n)); // size of list people
	list_people.resize(n);
	if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			infile.read((char*)&x, sizeof(x));
			infile.read((char*)&y, sizeof(y));
			list_people[i].setX(x);
			list_people[i].setY(y);
		}
	}

	// traffic light
	bool tl_state = 0; int cnt_time = 0, red_time = 0, green_time = 0;
	// list of trucks
	infile.read((char*)&tl_state, sizeof(tl_state));
	infile.read((char*)&cnt_time, sizeof(cnt_time));
	infile.read((char*)&red_time, sizeof(red_time));
	infile.read((char*)&green_time, sizeof(green_time));
	tl_trucks.setTLState(tl_state);
	tl_trucks.setTime(cnt_time);
	tl_trucks.setRedTime(red_time);
	tl_trucks.setGreenTime(green_time);
	// list of cars
	infile.read((char*)&tl_state, sizeof(tl_state));
	infile.read((char*)&cnt_time, sizeof(cnt_time));
	infile.read((char*)&red_time, sizeof(red_time));
	infile.read((char*)&green_time, sizeof(green_time));
	tl_cars.setTLState(tl_state);
	tl_cars.setTime(cnt_time);
	tl_cars.setRedTime(red_time);
	tl_cars.setGreenTime(green_time);
	infile.close();

	initGameGraphics();
	initListOfPeople();
}



// Run game
void CGAME::runGame()
{
	// traffic light state
	srand(time(NULL));

	while (IS_RUNNING)
	{
		// update traffic light state
		tl_trucks.updateTLState(list_trucks, 0);
		tl_cars.updateTLState(list_cars, 1);
		// people
		if (!cn.isDead())
		{
			CCONSOLE::drawGraphics("cgame/cpeople.txt", POINT{ cn.getX(),cn.getY() }, 12);
			updatePosOfPeople();
		}
		//update pos of object
		updatePosOfAnimal();
		updatePosOfVehicle();
		// Checking impact
		if (cn.isDead())
		{
			deadEffect();
			gameOver();
			return;
		}
		//Finish
		else if (cn.isFinish())
		{
			if (game_sound_state == 1) CCONSOLE::playMusic("ring");
			// checking impact other people
			if (list_people.size() == 0)
			{
				list_people.push_back(cn);
			}
			else
			{
				for (int i = 0; i < list_people.size(); i++)
				{
					if (cn.isImpact(list_people[i]))
					{
						cn.setState(false);
						cn.setY(cn.getY() + 5);
						deadEffect();
						gameOver();
						return;
					}
				}
				list_people.push_back(cn);
			}
			// update game score
			updateGameScore();
			// reset people
			cn.setX(55); cn.setY(32);
		}
		Sleep(300 - (30 * level));
	}
}

// Get people
CPEOPLE CGAME::getPeople()
{
	return this->cn;
}