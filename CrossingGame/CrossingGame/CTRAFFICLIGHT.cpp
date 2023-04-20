#include"CTRAFFICLIGHT.h"

// Constructor
template<class Obj>
CTRAFFICLIGHT<Obj>::CTRAFFICLIGHT()
{

}

template<class Obj>
CTRAFFICLIGHT<Obj>::CTRAFFICLIGHT(int green_time, int red_time)
{
	this->green_time = green_time;
	this->red_time = red_time;
	cnt_time = 0;
	tl_state = true;
}

// get set tl state
template<class Obj>
bool CTRAFFICLIGHT<Obj>::getTLState()
{
	return tl_state;
}

template<class Obj>
void CTRAFFICLIGHT<Obj>::setTLState(bool tl_state)
{
	this->tl_state = tl_state;
}




// update tl state
template<class Obj>
void CTRAFFICLIGHT<Obj>::updateTLState(vector<Obj*>& c_vehicle, bool flag)
{
	cnt_time += 1;
	if (tl_state) // true (able to drive)
	{
		if (cnt_time >= green_time) tl_state = false, cnt_time = 0;
		if (flag == 0)
		{
			CCONSOLE::GotoXY(2, 26);
			CCONSOLE::setColor(10); cout << "██";
			CCONSOLE::GotoXY(2, 27);
			CCONSOLE::setColor(8); cout << "██";
		}
		if (flag == 1)
		{
			CCONSOLE::GotoXY(116, 21);
			CCONSOLE::setColor(10); cout << "██";
			CCONSOLE::GotoXY(116, 22);
			CCONSOLE::setColor(8); cout << "██";
		}
	}
	else // false (unable to drive)
	{
		if (cnt_time >= red_time) tl_state = true, cnt_time = 0;
		if (flag == 0)
		{
			CCONSOLE::GotoXY(2, 26);
			CCONSOLE::setColor(8); cout << "██";
			CCONSOLE::GotoXY(2, 27);
			CCONSOLE::setColor(4); cout << "██";
		}

		if (flag == 1)
		{
			CCONSOLE::GotoXY(116, 21);
			CCONSOLE::setColor(8); cout << "██";
			CCONSOLE::GotoXY(116, 22);
			CCONSOLE::setColor(4); cout << "██";
		}
	}
	for (int i = 0; i < c_vehicle.size(); i++)
	{
		c_vehicle[i]->setTLState(tl_state);
	}
}

// get set cnt_time
template<class Obj>
int CTRAFFICLIGHT<Obj>::getTime()
{
	return cnt_time;
}


template<class Obj>
void CTRAFFICLIGHT<Obj>::setTime(int cnt_time)
{
	this->cnt_time = cnt_time;
}

// get traffic time
template<class Obj>
int  CTRAFFICLIGHT<Obj>::getRedTime()
{
	return this->red_time;
}

template<class Obj>
int  CTRAFFICLIGHT<Obj>::getGreenTime()
{
	return this->green_time;
}

// set traffic time
template<class Obj>
void CTRAFFICLIGHT<Obj>::setRedTime(int red_time)
{
	this->red_time = red_time;
}


template<class Obj>
void CTRAFFICLIGHT<Obj>::setGreenTime(int green_time)
{
	this->green_time = green_time;
}



template class CTRAFFICLIGHT<CCAR>;
template class CTRAFFICLIGHT<CTRUCK>;