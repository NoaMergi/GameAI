#pragma once

#include <string>
#include <trackable.h>
#include "Vector2D.h"

using namespace std;

enum EventType
{
	INVALID_EVENT_TYPE = -1,
	ADD_UNIT, DELETE_UNIT, QUIT_GAME, FREEZE_ANIMATION,
	/*
	A, B, C, D,	E,	F,	G,	H,	I,	J,	K,	L,	M,	N,	O,	P,	Q,	R,	S,	T,	U,	V,	W,	X,	Y,	Z,	
	N0, N1, N2, N3, N4, N5, N6, N7, N8, N9,
	ESCAPE, TILDE, MINUS, EQUALS, BACKSPACE, TAB, OPENBRACE, CLOSEBRACE, ENTER, SEMICOLON, QUOTE, BACKSLASH,
	BACKSLASH2, COMMA, FULLSTOP, SLASH, SPACE, LEFT, RIGHT, UP, DOWN, LEFT_MOUSE_CLICK, RIGHT_MOUSE_CLICK,*/
	NUM_EVENT_TYPES
};

const string EVENT_NAMES[NUM_EVENT_TYPES] = 
{ "add unit", "delete unit", "quit game", "freeze animation"
	/*"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
"0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
"escape", "left click", "right click"*/
											};

class Event:public Trackable
{
public:
	Event( EventType type );
	virtual ~Event();

	EventType getType() const { return mType; };
	const string& getEventName() const;

private:
	EventType mType;

};

class MousePosEvent : public Event
{
public:
	MousePosEvent(EventType aType, Vector2D aMousePos) : Event(aType){ mousePos = aMousePos; }
	~MousePosEvent(){}

	const Vector2D& getPos() const { return mousePos; } 

private:

	Vector2D mousePos; 
};