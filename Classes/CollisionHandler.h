#ifndef _COLLISION_HANDLER_H_
#define _COLLISION_HANDLER_H_

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "GameElementModel.h"
#include "FloorModel.h"
#include "Character.h"
#include "StepButtonModel.h"
#include "PushButtonModel.h"
#include "SlidingDoorModel.h"
#include "InSpacePortalModel.h"

USING_NS_CC;

class CollisionHandler : public b2ContactListener {
public:
	void BeginContact(b2Contact* c);
	void EndContact(b2Contact* c); 
};

#endif