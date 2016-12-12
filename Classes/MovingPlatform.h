#ifndef _MOVING_PLATFORMS_H_
#define _MOVING_PLATFORMS_H_

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "GameElement.h"
#include "MovingPlatformModel.h"
#include "MovingPlatformView.h"
#include "Utils.h"
#include "LevelDef.h"										

class MovingPlatformModel;

USING_NS_CC;

class MovingPlatform : public GameElement
{
private:
    MovingPlatformModel*    m_movingPlatformModel;
    MovingPlatformView*     m_movingPlatformView;
	int						m_movingPlatformID;
public:
	MovingPlatform(b2World& world, int ID, Vec2 startPoint, Vec2 endPoint, float velocity, Type type, Node* parent);
	void updatePlatform(float dt);
};
#endif // !_MOVING_PLATFORMS_H_

