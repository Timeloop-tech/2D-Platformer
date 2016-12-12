#include "OutSpacePortalModel.h"

OutSpacePortalModel::OutSpacePortalModel(b2World& world, b2Vec2 inPosition, b2Vec2 outPosition, int ID, int reactID)
	: GameElementModel(GameElementType::OutSpacePortal)
	, m_outPosition(outPosition)
	, m_inPosition(inPosition)
{
	b2BodyDef outSpacePortalBodyDef;
	b2FixtureDef outSpacePortalFixtureDef;
	b2CircleShape outSpacePortalCircleShape;

	outSpacePortalBodyDef.type = b2_kinematicBody;
	outSpacePortalBodyDef.position.Set(m_outPosition.x, m_outPosition.y);

	outSpacePortalCircleShape.m_radius = 1.2f;
	outSpacePortalCircleShape.m_p.Set(0.0f, 0.0f);

	outSpacePortalFixtureDef.isSensor = true;
	outSpacePortalFixtureDef.shape = &outSpacePortalCircleShape;

	m_physicsObject = world.CreateBody(&outSpacePortalBodyDef);
	m_physicsObject->CreateFixture(&outSpacePortalFixtureDef);
}

b2Vec2 OutSpacePortalModel::getInPosition()
{
	return m_inPosition;
}

b2Vec2 OutSpacePortalModel::getOutPosition()
{
	return m_outPosition;
}

void OutSpacePortalModel::setUserData(OutSpacePortal* outSpacePortal)
{
    m_physicsObject->SetUserData(outSpacePortal);
}
