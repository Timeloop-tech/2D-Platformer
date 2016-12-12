#ifndef _LIFT_H_
#define _LIFT_H_

#include "cocos2d.h"
#include "GameElement.h"
#include "LiftModel.h"
#include "LiftView.h"
#include "Utils.h"
#include "LevelDef.h"
#include "Events.h"

class LiftModel;

USING_NS_CC;

class Lift : public GameElement
{
private:
    LiftModel*          m_liftModel;
    LiftView*           m_liftView;
	int					m_reactID;
	bool				m_movingUP;
	Vec2				m_startPoint;
	Vec2				m_endPoint;
	float				m_veloctiyValue;
	Type				m_liftType;
public:
	Lift(b2World& world, int ID, int reactID, Vec2 startPosition, Vec2 endPosition, float velocity, Type type, Node* parent);
	void onPushButtonActivation(int i);
	void onPushButtonDeactivation(int i);
	void moveLiftUpwards();
	void moveLiftDownwards();
	void setVelocityToZero(float dt);
};
#endif // !_LIFT_H_

