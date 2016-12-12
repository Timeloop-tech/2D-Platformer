#ifndef _PUSHABLE_BLOCK_MODEL_H_
#define _PUSHABLE_BLOCK_MODEL_H_

#include "GameElementModel.h"
#include "cocos2d.h"
#include "PushableBlock.h"

class PushableBlock;

USING_NS_CC;

class PushableBlockModel : public GameElementModel
{
private:
public:
	PushableBlockModel(b2World& world, b2Vec2 position, int ID);
    void setUserData(PushableBlock* pushableBlock);
};
#endif 
