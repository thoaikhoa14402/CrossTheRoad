#pragma once
#include"CVEHICLE.h"
class CTRUCK : public CVEHICLE
{
public:
	virtual void Move();
	virtual void Tell();
	CTRUCK(int x, int y);
};