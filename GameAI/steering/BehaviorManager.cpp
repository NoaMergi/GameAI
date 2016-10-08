#include "BehaviorManager.h"
#include "GlobalStates.h"

BehaviorManager::BehaviorManager(Ai defaultBehavior, Ai changeBehavior, KinematicUnit* pUnit, KinematicUnit* pTarget, float rad)
{
	mDefaultBehavior = defaultBehavior;
	mChangedBehavior = changeBehavior;
	mTarget = pTarget;
	mUnit = pUnit;
	mChangeRad = rad;
	mUnit->wander();
}

BehaviorManager::~BehaviorManager()
{

}

void BehaviorManager::setBehavior()
{

	if (getDistance(mUnit->getPosition(), mTarget->getPosition()) <= mChangeRad /*&& mCurrentBehavior != mChangedBehavior*/)
		getBehavior(mChangedBehavior);
	else if (getDistance(mUnit->getPosition(), mTarget->getPosition()) > mChangeRad /*&& mCurrentBehavior != mDefaultBehavior*/)
		getBehavior(mDefaultBehavior);
}

void BehaviorManager::getBehavior(Ai behavior)
{
	mUnit->wander();
	
	if (behavior == SEEK)
	{
		mCurrentBehavior = SEEK;
		mUnit->dynamicSeek(mTarget);
	}
	else if (behavior == WONDER)
	{
		mCurrentBehavior = WONDER;
		mUnit->wander();
	}
	else if (behavior == FLEE)
	{
		mCurrentBehavior = FLEE;
		mUnit->dynamicFlee(mTarget);
	}
	
}



float getDistance(Vector2D v1, Vector2D v2)
{
	Vector2D vec = v1 - v2;
	return vec.getLength();
}