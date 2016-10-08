#pragma once
#include "Steering.h"
#include "Trackable.h"
#include "UnitManager.h"
#include "KinematicUnit.h"

static class BehaviorManager : public Trackable
{
public:
	BehaviorManager(Ai defaultBehavior, Ai changeBehavior, KinematicUnit* pUnit, KinematicUnit* pTarget, float rad = 200);
	~BehaviorManager();

	void setBehavior();
	void getBehavior(Ai behavior);

private:

	Ai mDefaultBehavior;
	Ai mChangedBehavior;
	Ai mCurrentBehavior;

	float mChangeRad;

	KinematicUnit* mTarget;
	KinematicUnit* mUnit;

};


float getDistance(Vector2D v1, Vector2D v2);


