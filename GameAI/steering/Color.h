#pragma once
#include "allegro5\color.h"
#include "Trackable.h"


class Color : Trackable
{
public:
	Color();
	Color(int aR, int aG, int aB);
	~Color(){};

	int r(){ return mR; }
	int g(){ return mG; }
	int b(){ return mB; }
	int a(){ return mA; }

	void setColor(int aR, int aG, int aB);

private:

	int mR;
	int mG;
	int mB;
	int mA;
};
//al_map_rgba(0, 0, 0, 0)