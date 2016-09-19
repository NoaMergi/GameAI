#pragma once
#include "Trackable.h"
#include <iostream>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro.h>
#include "EventSystem.h"
#include "Event.h"
#include "Vector2D.h"
#include "GraphicsSystem.h"

class InputSystem : public Trackable
{
public:
	InputSystem();
	~InputSystem();

	void init();
	void cleanup();
	void update();

	bool isEscapeUp(){ return mEscape; }
	bool isFUp(){ return mF; }
	bool isSUp(){ return mS; }
	bool isLMouseUp(){ return mLMouseClick; }

	int getMouseX(){ return mEvent.mouse.x; }
	int getMouseY(){ return mEvent.mouse.y; }
	
private:

	const static enum KEYBOARD_KEYS
	{ // https://www.allegro.cc/manual/5/keyboard.html
		A = 1,
		B = 2,
		C = 3,
		D = 4,
		E = 5,
		F = 6,
		G = 7,
		H = 8,
		I = 9,
		J = 10,
		K = 11,
		L = 12,
		M = 13,
		N = 14,
		O = 15,
		P = 16,
		Q = 17,
		R = 18,
		S = 19,
		T = 20,
		U = 21,
		V = 22,
		W = 23,
		X = 24,
		Y = 25,
		Z = 26,
		N0 = 27,
		N1 = 28,
		N2 = 29,
		N3 = 30,
		N4 = 31,
		N5 = 32,
		N6 = 33,
		N7 = 34,
		N8 = 35,
		N9 = 36,
		ESCAPE = 59,
		TILDE = 60,
		MINUS = 61,
		EQUALS = 62,
		BACKSPACE = 63,
		TAB = 64,
		OPENBRACE = 65,
		CLOSEBRACE = 66,
		ENTER = 67,
		SEMICOLON = 68,
		QUOTE = 69,
		BACKSLASH = 70,
		BACKSLASH2 = 71,
		COMMA = 72,
		FULLSTOP = 73,
		SLASH = 74,
		SPACE = 75,
		LEFT = 82,
		RIGHT = 83,
		UP = 84,
		DOWN = 85,
		MY_MAX_KEY = 86
	};

	const static enum MOUSE_KEYS
	{
		LEFT_CLICK = 1, RIGHT_CLICK = 2
	};

	ALLEGRO_EVENT mEvent;
	ALLEGRO_EVENT_QUEUE *mpEventQueue;
	ALLEGRO_EVENT_TYPE mCurrentType;
	
	bool pressed_keys[ALLEGRO_KEY_MAX];
	bool mEscape;
	bool mF;
	bool mS;
	bool mLMouseClick;
};

