#include "InSpacePortalModel.h"

InSpacePortalModel::InSpacePortalModel(b2World& world, b2Vec2 inPosition, b2Vec2 outPosition, int ID, int reactID)
	: GameElementModel(GameElementType::InSpacePortal)
	, m_inPosition(inPosition)
	, m_outPosition(outPosition)
{
	b2BodyDef inSpacePortalBodyDef;
	b2FixtureDef inSpacePortalFixtureDef;
	b2CircleShape inSpacePortalCircleShape;

	inSpacePortalBodyDef.type = b2_kinematicBody;
	inSpacePortalBodyDef.position.Set(m_inPosition.x, m_inPosition.y);
	
	inSpacePortalCircleShape.m_radius = 1.2;
	inSpacePortalCircleShape.m_p.Set(0.0f, 0.0f);
	
	inSpacePortalFixtureDef.isSensor = true;
	inSpacePortalFixtureDef.shape = &inSpacePortalCircleShape;

	m_physicsObject = world.CreateBody(&inSpacePortalBodyDef);
	m_physicsObject->CreateFixture(&inSpacePortalFixtureDef);
}

b2Vec2 InSpacePortalModel::getInPosition()
{
	return  m_inPosition;
}

b2Vec2 InSpacePortalModel::getOutPosition()
{
	return  m_outPosition;
}

void InSpacePortalModel::setUserData(InSpacePortal* inSpacePortal)
{
    m_physicsObject->SetUserData(inSpacePortal);
}

