#ifndef _LIFT_MODEL_H_
#define _LIFT_MODEL_H_

#include "cocos2d.h"
#include "GameElementModel.h"
#include "Box2D/Box2D.h"
#include "LevelDef.h"
#include "Lift.h"

class Lift;

class LiftModel : public GameElementModel
{
private:
	int				m_liftID;
	Type			m_liftType;
	b2Vec2			m_startPoint;
	b2Vec2			m_endPoint;
	b2Vec2			m_velocity;
	float			m_velocityValue;
public:
	LiftModel(b2World& world, int ID, int reactID, b2Vec2 startPosition, b2Vec2 endPosition, float velocity, Type type);
	void moveLiftUpwards();
	void moveLiftDownwards();
	void setVelocityToZero();
    void setUserData(Lift* lift);
};
#endif // !_LIFT_MODEL_H_

