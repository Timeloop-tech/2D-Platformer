#include "TerminatingDoorModel.h"

TerminatingDoorModel::TerminatingDoorModel(b2World& world, b2Vec2 position)
	: GameElementModel(GameElementType::TerminatingDoor)
	, m_interactionEnabled(true)
{
	b2BodyDef terminatingDoorBodyDef;
	b2FixtureDef terminatingDoorFixtureDef;
	b2PolygonShape terminatingDoorShape;

	terminatingDoorBodyDef.type = b2_staticBody;
	terminatingDoorBodyDef.position.Set(position.x, position.y);
	
	terminatingDoorShape.SetAsBox(m_halfDoorWidth, m_halfDoorHeight);
	
	terminatingDoorFixtureDef.isSensor = true;
	terminatingDoorFixtureDef.shape = &terminatingDoorShape;
	
	m_physicsObject = world.CreateBody(&terminatingDoorBodyDef);
	m_physicsObject->CreateFixture(&terminatingDoorFixtureDef);
}

void TerminatingDoorModel::setInteractionStatus(bool status)
{
	m_interactionEnabled = status;
}

bool TerminatingDoorModel::getInteractionStatus()
{
	return m_interactionEnabled;
}

void TerminatingDoorModel::setUserData(TerminatingDoor* terminatingDoor)
{
    m_physicsObject->SetUserData(terminatingDoor);
}
