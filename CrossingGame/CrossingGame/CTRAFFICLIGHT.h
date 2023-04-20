#pragma once
#include"CCONSOLE.h"
#include"CCAR.h"
#include"CTRUCK.h"
#include<vector>

template <class Obj>
class CTRAFFICLIGHT
{
private:
	bool tl_state;
	int  cnt_time;
	int  red_time, green_time;
public:
	CTRAFFICLIGHT();
	CTRAFFICLIGHT(int green_time, int red_time);

	void updateTLState(vector<Obj*>& c_vehicle, bool flag);

	bool getTLState();
	void setTLState(bool);

	int getTime();
	void setTime(int);
	// get traffic time
	int  getRedTime();
	int  getGreenTime();
	// set traffic time
	void setRedTime(int);
	void setGreenTime(int);
};


