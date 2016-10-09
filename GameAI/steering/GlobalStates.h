#pragma once
#include "EventListener.h"

enum ControlState
{
	NULL_STATE = -1,
	ENEMY_VELOCITY_CONTROL,
	REACTION_RADIUS,
	ANGULAR_VELOCITY
};



class GlobalStates : public EventListener
{
public:
	GlobalStates(float enemyVel = 1.0f, float reactionRad = 1.0f, float angularVal = 1.0f);
	~GlobalStates();

	void handleEvent(const Event& theEvent) override;

	inline float getGlobalEnemyVelocity() { return mGlobalEnemyVelocity; }
	inline float getGlobalReactionRadius() { return mGlobalReactionRadius; }
	inline float getGlobalAngularVelocity() { return mGlobalAngularVelocity; }
	inline ControlState getCurrentState() { return mCurrentState; }

	inline void setGlobalEnemyVelocity(float val) { mGlobalEnemyVelocity = val; }
	inline void setGlobalReactionRadius(float val) { mGlobalReactionRadius = val; }
	inline void setGlobalAngularVelocity(float val) { mGlobalAngularVelocity = val; }
	inline ControlState getCurrentState(ControlState state) { mCurrentState = state; }

private:

	void changeStateValue(float change);

	float mGlobalEnemyVelocity;
	float mGlobalReactionRadius;
	float mGlobalAngularVelocity;
	ControlState mCurrentState;

	const int ENEMY_VEL_CHANGE = 3;
	const int REACTION_RAD_CHANGE = 20;
	const int ANGULAR_VEL_CHANGE = 3;
};

extern GlobalStates* gpGlobalStates;

