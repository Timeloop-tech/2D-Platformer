#ifndef _MOVING_PLATFORM_MODEL_H_
#define _MOVING_PLATFORM_MODEL_H_

#include "GameElementModel.h"
#include "MovingPlatform.h"
#include "LevelDef.h"

class MovingPlatform;

class MovingPlatformModel : public GameElementModel
{
private:
	b2Vec2					m_startPoint;
	b2Vec2					m_endPoint;
	b2Vec2					m_velocity;
	float					m_velocityValue;
	Type					m_PlatformType;
public:
	MovingPlatformModel(b2World& world, b2Vec2 startPoint, b2Vec2 endPOint, float velocityValue, Type type);
    void setUserData(MovingPlatform* movingPlatform);
	void updatePlatform(float dt);
};
#endif // !_MOVING_PLATFORMS_MODEL_H_
