#ifndef _IN_SPACE_PORTAL_H_
#define _IN_SPACE_PORTAL_H_

#include "cocos2d.h"
#include "GameElement.h"
#include "InSpacePortalView.h"
#include "InSpacePortalModel.h"
#include "Utils.h"

class InSpacePortalModel;

USING_NS_CC;

class InSpacePortal : public GameElement
{
private:
    InSpacePortalModel*     m_inSpacePortalModel;
    InSpacePortalView*      m_inSpacePortalView;
    
public:
	InSpacePortal(b2World& world, Vec2 inPosition, Vec2 outPosition, int ID, int reactID, Node* parent);
    b2Vec2 getInPosition();
    b2Vec2 getOutPosition();
};
#endif // !_IN_SPACE_PORTAL_H_

