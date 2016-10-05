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
	GlobalStates();
	~GlobalStates();

	void handleEvent(const Event& theEvent) override;

private:
	float mGlobalEnemyVelocityControl;
	float mGlobalReactionRadius;
	float mGlobalAngularVelocity;
	ControlState currentState;

	
};

extern GlobalStates* gpGlobalStates;

