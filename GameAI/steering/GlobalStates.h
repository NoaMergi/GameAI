#pragma once
#include "EventListener.h"

enum ControlState
{
	ENEMY_VELOCITY_CONTROL,
	REACTION_RADIUS,
	ANGULAR_VELOCITY
};



class GlobalStates : public EventListener
{
public:
	GlobalStates(float enemyVel = 1.0f, float reactionRad = 1.0f, float angularVal = 1.0f, float change = 0.2f, ControlState state = ENEMY_VELOCITY_CONTROL);
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
	float mChange;
	ControlState mCurrentState;

	
};

extern GlobalStates* gpGlobalStates;

