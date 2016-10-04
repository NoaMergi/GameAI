#pragma once
#include "allegro5\color.h"
#include "Trackable.h"


class Color : Trackable
{
public:
	Color(int aR = 255, int aG = 255, int aB = 255, int aA = 255);
	~Color(){};

	int r(){ return mR; }
	int g(){ return mG; }
	int b(){ return mB; }
	int a(){ return mA; }

	void setColor(int aR = 255, int aG = 255, int aB = 255, int aA = 255);

private:

	int mR;
	int mG;
	int mB;
	int mA;
};
//al_map_rgba(0, 0, 0, 0)