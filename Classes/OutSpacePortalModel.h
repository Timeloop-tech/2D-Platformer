#ifndef _OUT_SPACE_PORTAL_MODEL_H_
#define _OUT_SPACE_PORTAL_MODEL_H_

#include "GameElementModel.h"
#include "cocos2d.h"
#include "LevelDef.h"
#include "OutSpacePortal.h"

class OutSpacePortal;

USING_NS_CC;

class OutSpacePortalModel : public GameElementModel
{
private:
	b2Vec2				m_outPosition;
	b2Vec2				m_inPosition;
public:
	OutSpacePortalModel(b2World& world, b2Vec2 inPosition, b2Vec2 outPosition, int ID, int reactID);
	b2Vec2 getInPosition();
	b2Vec2 getOutPosition();
    void setUserData(OutSpacePortal* outSpacePortal);
};


#endif // !_OUT_SPACE_PORTAL_MODEL_H_

