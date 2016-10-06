#pragma once
#include "Steering.h"
#include "Trackable.h"
#include "UnitManager.h"
#include "KinematicUnit.h"

static class BehaviorManager : public Trackable
{
public:
	BehaviorManager();
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

