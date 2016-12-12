#ifndef _FLOOR_MODEL_H_
#define _FLOOR_MODEL_H_

#include "cocos2d.h"
#include "GameElementModel.h"
#include "Floor.h"

USING_NS_CC;

class Floor;

class FloorModel : public GameElementModel
{
public:
	FloorModel(b2World& world, b2Vec2 startPoint, b2Vec2 endPoint);
    void setUserData(Floor* floor);
};
#endif