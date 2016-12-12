#ifndef _UTILS_H_
#define _UTILS_H_

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "GameElementModel.h"
USING_NS_CC;

class Utils
{
public:
	static Vec2 meterPositionToPX(b2Vec2 meterPos);
	static b2Vec2 pixelPositionToMeter(Vec2 pixelPos);
};
#endif // !_UTILS_H_

