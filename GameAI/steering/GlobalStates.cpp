#include "GlobalStates.h"
#include "EventSystem.h"
#include "Event.h"
#include <iostream>

GlobalStates* gpGlobalStates = nullptr;

GlobalStates::GlobalStates(float enemyVel, float reactionRad, float angularVal, float change, ControlState state)
{
	mGlobalEnemyVelocity = enemyVel;
	mGlobalReactionRadius = reactionRad;
	mGlobalAngularVelocity = angularVal;
	mCurrentState = state;
	mChange = change;

	gpEventSystem->addListener(INCREASE_SELECTED_VALUE, this);
	gpEventSystem->addListener(REDUCE_SELECTED_VAULUE, this);
	gpEventSystem->addListener(SELECT_ENEMY_VELOCITY, this);
	gpEventSystem->addListener(SELECT_REACTION_RAD, this);
	gpEventSystem->addListener(SELECT_ANGULAR_VELOCITY, this);

}

GlobalStates::~GlobalStates()
{
	gpEventSystem->removeListenerFromAllEvents(this);
}

void GlobalStates::handleEvent(const Event& theEvent)
{
	if (theEvent.getType() == SELECT_ENEMY_VELOCITY)
	{
		mCurrentState = ENEMY_VELOCITY_CONTROL;
		std::cout << mCurrentState;
	}
	else if (theEvent.getType() == SELECT_REACTION_RAD)
	{
		mCurrentState = REACTION_RADIUS;
		std::cout << mCurrentState;
	}
	else if (theEvent.getType() == SELECT_ANGULAR_VELOCITY)
	{
		mCurrentState = ANGULAR_VELOCITY;
		std::cout << mCurrentState;
	}
	else if (theEvent.getType() == INCREASE_SELECTED_VALUE)
	{
		if (mCurrentState == ENEMY_VELOCITY_CONTROL)
			mGlobalEnemyVelocity += mChange;
		else if (mCurrentState == SELECT_REACTION_RAD)
			mGlobalReactionRadius += mChange;
		else if (mCurrentState == SELECT_ANGULAR_VELOCITY)
			mGlobalAngularVelocity += mChange;
	}
	else if (theEvent.getType() == REDUCE_SELECTED_VAULUE)
	{
		if (mCurrentState == ENEMY_VELOCITY_CONTROL && mGlobalEnemyVelocity > 0)
			mGlobalEnemyVelocity -= mChange;
		else if (mCurrentState == SELECT_REACTION_RAD && mGlobalReactionRadius > 0)
			mGlobalReactionRadius -= mChange;
		else if (mCurrentState == SELECT_ANGULAR_VELOCITY && mGlobalAngularVelocity > 0)
			mGlobalAngularVelocity -= mChange;
	}
}

