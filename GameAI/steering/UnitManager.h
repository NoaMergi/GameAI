#pragma once

#include <vector>
#include <random>
#include "KinematicUnit.h"
#include "EventListener.h"
#include "GraphicsBuffer.h"
#include "Vector2D.h"
#include "Event.h"
#include "EventSystem.h"
#include "Game.h"



using namespace std;



class UnitManager : public EventListener
{
public:
	UnitManager();
	~UnitManager();


	KinematicUnit* getUnit(int akey);
	void addPlayer(KinematicUnit* aUnit);
	void addPlayer(Sprite *pSprite, const Vector2D &position, float orientation, const Vector2D &velocity, float rotationVel);
	void addUnit(KinematicUnit* aUnit, Ai behavior, KinematicUnit* target = nullptr);
	void addUnit(Sprite *pSprite, const Vector2D &position, float orientation, const Vector2D &velocity, float rotationVel, Ai behavior, KinematicUnit* target = nullptr);
	void deleteUnit(int akey);

	KinematicUnit* getPlayerUnit();
	inline int getUnitNum() { return mUnitList.size(); }

	void clear();

	void update(float time);
	void draw(GraphicsBuffer* pBuffer);

	void handleEvent(const Event& theEvent);

private:
	vector<KinematicUnit*> mUnitList;
	bool doesPlayerExist;
	random_device mRandom;
	

};

/*new Unit(mpsInstance->mGraphicsBufferManager.getGraphicBuffer("dardas"), dardasSheetRow, dardasSheetCollom, dardasSheetWidth, dardasSheetHeight,
Vector2D((mpsInstance->mpGraphicSystem->getWidth() / 2) - (dardasSheetWidth / 2.0), mpsInstance->mpGraphicSystem->getHeight() / 2 - (dardasSheetHeight / 2.0)), 24)*/