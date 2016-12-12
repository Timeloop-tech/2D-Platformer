#ifndef _IN_SPACE_PORTAL_MODEL_H_
#define _IN_SPACE_PORTAL_MODEL_H_

#include "GameElementModel.h"
#include "cocos2d.h"
#include "InSpacePortal.h"

class InSpacePortal;

USING_NS_CC;

class InSpacePortalModel : public GameElementModel
{
private:
	b2Vec2				m_inPosition;
	b2Vec2				m_outPosition;
public:
	InSpacePortalModel(b2World& world, b2Vec2 inPosition, b2Vec2 outPosition, int ID, int reactID);
	b2Vec2 getInPosition();
	b2Vec2 getOutPosition();
    void setUserData(InSpacePortal* inSpacePortal);
};


#endif // !_IN_SPACE_PORTAL_MODEL_H_

