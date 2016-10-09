#include "GlobalStates.h"
#include "EventSystem.h"
#include "Event.h"
#include <iostream>

GlobalStates* gpGlobalStates = nullptr;


GlobalStates::GlobalStates(float enemyVel, float reactionRad, float angularVal)
{
	mGlobalEnemyVelocity = enemyVel;
	mGlobalReactionRadius = reactionRad;
	mGlobalAngularVelocity = angularVal;

	mCurrentState = NULL_STATE;

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
	}
	else if (theEvent.getType() == SELECT_REACTION_RAD)
	{
		mCurrentState = REACTION_RADIUS;
	}
	else if (theEvent.getType() == SELECT_ANGULAR_VELOCITY)
	{
		mCurrentState = ANGULAR_VELOCITY;
	}
	else if (theEvent.getType() == INCREASE_SELECTED_VALUE)
	{
		if (mCurrentState == ENEMY_VELOCITY_CONTROL)
		{
			mGlobalEnemyVelocity += ENEMY_VEL_CHANGE;
			StatChangeEvent event(ENEMY_VELOCITY_CHANGED, mGlobalEnemyVelocity);
			gpEventSystem->fireEvent(event);
		}
		else if (mCurrentState == REACTION_RADIUS)
		{
			mGlobalReactionRadius += REACTION_RAD_CHANGE;
			StatChangeEvent event(REACTION_RAD_CHANGED, mGlobalReactionRadius);
			gpEventSystem->fireEvent(event);
		}
		else if (mCurrentState == ANGULAR_VELOCITY)
		{
			mGlobalAngularVelocity += ANGULAR_VEL_CHANGE;
			StatChangeEvent event(ANGULAR_VELOCITY_CHANGED, mGlobalAngularVelocity);
			gpEventSystem->fireEvent(event);
		}
	}
	else if (theEvent.getType() == REDUCE_SELECTED_VAULUE)
	{
		if (mCurrentState == ENEMY_VELOCITY_CONTROL && mGlobalEnemyVelocity - ENEMY_VEL_CHANGE > 0)
		{
			mGlobalEnemyVelocity -= ENEMY_VEL_CHANGE;
			StatChangeEvent event(ENEMY_VELOCITY_CHANGED, mGlobalEnemyVelocity);
			gpEventSystem->fireEvent(event);
		}
		else if (mCurrentState == REACTION_RADIUS && mGlobalReactionRadius - REACTION_RAD_CHANGE > 0)
		{
			mGlobalReactionRadius -= REACTION_RAD_CHANGE;
			StatChangeEvent event(REACTION_RAD_CHANGED, mGlobalReactionRadius);
			gpEventSystem->fireEvent(event);
		}
		else if (mCurrentState == ANGULAR_VELOCITY && mGlobalAngularVelocity - ANGULAR_VEL_CHANGE > 0)
		{
			mGlobalAngularVelocity -= ANGULAR_VEL_CHANGE;
			StatChangeEvent event(ANGULAR_VELOCITY_CHANGED, mGlobalAngularVelocity);
			gpEventSystem->fireEvent(event);
		}
	}
}

