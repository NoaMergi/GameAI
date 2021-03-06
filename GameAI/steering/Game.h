#pragma once

#include "Trackable.h"
#include "PerformanceTracker.h"
#include "EventSystem.h"
#include "EventListener.h"
#include "Defines.h"
#include <allegro5/allegro.h>

#include <allegro5/allegro_audio.h>
#include <string>

class GraphicsSystem;
class GraphicsBuffer;
class GraphicsBufferManager;
class SpriteManager;
class KinematicUnit;
class GameMessageManager;
class Timer;
class InputSystem;
class UnitManager;
class Ui;
class Text;

const IDType BACKGROUND_SPRITE_ID = 0;
const IDType PLAYER_ICON_SPRITE_ID = 1;
const IDType AI_ICON_SPRITE_ID = 2;

const float LOOP_TARGET_TIME = 33.3f;//how long should each frame of execution take? 30fps = 33.3ms/frame

class Game:public EventListener
{
public:
	Game();
	~Game();

	bool init();//returns true if no errors, false otherwise
	void cleanup();

	//game loop
	void beginLoop();
	void processLoop();
	void draw();
	bool endLoop();

	inline GraphicsSystem* getGraphicsSystem() const { return mpGraphicsSystem; };
	inline GraphicsBufferManager* getGraphicsBufferManager() const { return mpGraphicsBufferManager; };
	inline SpriteManager* getSpriteManager() const { return mpSpriteManager; };
	inline GameMessageManager* getMessageManager() { return mpMessageManager; };
	inline UnitManager* getUnitManager() { return mpUnitManager; };
	inline Timer* getMasterTimer() const { return mpMasterTimer; };
	inline InputSystem* getInputSystem() const { return mpInputSystem; };
	inline double getCurrentTime() const { return mpMasterTimer->getElapsedTime(); };
	//inline ALLEGRO_FONT* getFont() const { return mpFont; };


	//inline KinematicUnit* getAIUnit() { return mpAIUnit; };//should be someplace else
	//inline KinematicUnit* getAIUnit2() { return mpAIUnit2; };//should be someplace else

	void handleEvent(const Event& theEvent);

private:
	GraphicsSystem* mpGraphicsSystem;
	GraphicsBufferManager* mpGraphicsBufferManager;
	SpriteManager* mpSpriteManager;
	GameMessageManager* mpMessageManager;
	InputSystem* mpInputSystem;
	Timer* mpLoopTimer;
	Timer* mpMasterTimer;
	UnitManager* mpUnitManager;
	Ui* mpUi;
	
	bool mShouldExit;
	//Font* mpFont;
	//Text* mpText;

	//should be somewhere else
	//ALLEGRO_FONT* mpFont;
	ALLEGRO_SAMPLE* mpSample;
	IDType mBackgroundBufferID;
	IDType mPlayerIconBufferID;
	IDType mEnemyIconBufferID;

};

float genRandomBinomial();//range -1:1 from "Artificial Intelligence for Games", Millington and Funge
float genRandomFloat();//range 0:1 from "Artificial Intelligence for Games", Millington and Funge

extern Game* gpGame;
extern PerformanceTracker* gpPerformanceTracker;

