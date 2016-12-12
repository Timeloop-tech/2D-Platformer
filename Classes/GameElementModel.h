#ifndef _GAME_ELEMENT_MODEL_H_
#define _GAME_ELEMENT_MODEL_H_

#include "Box2D/Box2D.h"
#define PTM_RATIO 32

enum class GameElementType 
{
	None,
	Floor,
	Character,
	StepButton,
	PushButton,
	SlidingDoor,
	MovingPlatform,
	Lift,
	InSpacePortal,
	OutSpacePortal,
	PushableBlock,
	TerminatingDoor
};

class GameElementModel 
{
private:
	GameElementType		m_gameElementType;
public:
	GameElementModel(GameElementType gameElementType);
	GameElementType getGameElementType();
	b2Body* getPhysicsObject();
    void updateState();
  	b2Vec2 getPosition();
    
protected :
	b2Body*				m_physicsObject;
};

#endif