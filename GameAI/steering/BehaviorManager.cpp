#include "BehaviorManager.h"

BehaviorManager::BehaviorManager()
{

}

BehaviorManager::~BehaviorManager()
{

}

void BehaviorManager::setBehavior()
{
	/*
	if (getDistance(mUnit->getPosition(), mTarget->getPosition()) <= mChangeRad && mCurrentBehavior != mChangedBehavior)
		getBehavior(mChangedBehavior);
	else if (getDistance(mUnit->getPosition(), mTarget->getPosition()) > mChangeRad && mCurrentBehavior != mDefaultBehavior)
		getBehavior(mDefaultBehavior);*/
}

void BehaviorManager::getBehavior(Ai behavior)
{
	if (behavior = SEEK)
	{
		mUnit->dynamicSeek(mTarget);
	}
	else if (behavior = FLEE)
	{
		mUnit->dynamicFlee(mTarget);
	}
	else
	{
		mUnit->wander();
	}
}

float getDistance(Vector2D v1, Vector2D v2)
{
	return 0.0f;
}

