#ifndef _OUT_SPACE_PORTAL_H_
#define _OUT_SPACE_PORTAL_H_

#include "cocos2d.h"
#include "GameElement.h"
#include "OutSpacePortalView.h"
#include "OutSpacePortalModel.h"
#include "Utils.h"

class OutSpacePortalModel;

USING_NS_CC;

class OutSpacePortal : public GameElement
{
private:
    OutSpacePortalModel*        m_outSpacePortalModel;
    OutSpacePortalView*         m_outSpacePortalView;
    
public:
	OutSpacePortal(b2World& world, Vec2 inPosition, Vec2 outPosition, int ID, int reactID, Node* parent);
    b2Vec2 getInPosition();
    b2Vec2 getOutPosition();
};
#endif // !_OUT_SPACE_PORTAL_H_


