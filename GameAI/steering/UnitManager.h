#pragma once

#include <map>
#include "KinematicUnit.h"
#include "EventListener.h"
#include "GraphicsBuffer.h"
#include "Vector2D.h"
#include "Event.h"
#include "EventSystem.h"

using namespace std;

class UnitManager : EventListener
{
public:
	UnitManager();
	~UnitManager();
	//KinematicUnit( Sprite* pSprite, const Vector2D& position, float orientation, const Vector2D& velocity, float rotationVel, float maxVelocity = 1.0f, float maxAcceleration = 1.0f );
	KinematicUnit* getCurrentUnit(){ return mpPlayer; }
	void setCurrentUnit(KinematicUnit* aUnit){ mpPlayer = aUnit; }

	KinematicUnit* getUnit(int akey);
	void addUnit(KinematicUnit* aUnit);
	void addUnit(Sprite* pSprite, const Vector2D& position, float orientation, const Vector2D& velocity, float rotationVel, float maxVelocity = 1.0f, float maxAcceleration = 1.0f);
	void deleteUnit(int akey);

	void clear();

	void update();
	void draw(GraphicsBuffer* pBuffer);

	void handleEvent(const Event& theEvent);

private:
	map< int, KinematicUnit* > mUnitList;
	KinematicUnit* mpPlayer;
	static int mID;
};

/*new Unit(mpsInstance->mGraphicsBufferManager.getGraphicBuffer("dardas"), dardasSheetRow, dardasSheetCollom, dardasSheetWidth, dardasSheetHeight,
Vector2D((mpsInstance->mpGraphicSystem->getWidth() / 2) - (dardasSheetWidth / 2.0), mpsInstance->mpGraphicSystem->getHeight() / 2 - (dardasSheetHeight / 2.0)), 24)*/