#include "SlidingDoorModel.h"

SlidingDoorModel::SlidingDoorModel(b2World& world, b2Vec2 position,int ID)
	: GameElementModel(GameElementType::SlidingDoor)
	, m_linearVelocityWhileOpening(b2Vec2(0.0f, 1.0f))
	, m_linearVelocityWhileClosing(b2Vec2(0.0f, -1.0f))
	, m_startingPosition(position)
{
	b2BodyDef slidingDoorBodyDef;
	b2FixtureDef slidingDoorFixtureDef, slidingDoorSensorFixtureDef;
	b2PolygonShape slidingDoorPolygon, slidingDoorSensorPolygon;

	slidingDoorBodyDef.type = b2_kinematicBody;
	slidingDoorBodyDef.position.Set(position.x, position.y);

	slidingDoorPolygon.SetAsBox(m_halfDoorWidth, m_halfDoorHeight);

	b2Vec2 sensorHalfVec(m_halfDoorWidth - 1, 0.05f);
	b2Vec2 offset(0.0f, -m_halfDoorHeight);

	slidingDoorSensorPolygon.SetAsBox(sensorHalfVec.x, sensorHalfVec.y, offset, 0);

	slidingDoorFixtureDef.shape = &slidingDoorPolygon;
	slidingDoorSensorFixtureDef.shape = &slidingDoorSensorPolygon;
	slidingDoorSensorFixtureDef.isSensor = true;

	m_physicsObject = world.CreateBody(&slidingDoorBodyDef);
	m_physicsObject->CreateFixture(&slidingDoorFixtureDef);
	m_physicsObject->CreateFixture(&slidingDoorSensorFixtureDef);
}

void SlidingDoorModel::setUserData(SlidingDoor* slidingDoor)
{
    m_physicsObject->SetUserData(slidingDoor);
}

void SlidingDoorModel::beginOpeningDoor()
{
	m_physicsObject->SetLinearVelocity(m_linearVelocityWhileOpening);
}

void SlidingDoorModel::endOpeningDoor()
{
	m_physicsObject->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
}

b2Vec2 SlidingDoorModel::getLinearVelocity()
{
	return m_linearVelocityWhileOpening;
}

float SlidingDoorModel::getDoorHeight()
{
	return (m_halfDoorHeight * 2);
}

void SlidingDoorModel::beginClosingDoor()
{
	m_physicsObject->SetLinearVelocity(m_linearVelocityWhileClosing);
}

void SlidingDoorModel::endClosingDoor()
{
	m_physicsObject->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
}

void SlidingDoorModel::setLinearVelocity(b2Vec2 velocity)
{
	m_physicsObject->SetLinearVelocity(velocity);
}

b2Vec2 SlidingDoorModel::getCurrentPosition()
{
	return m_physicsObject->GetPosition();
}

b2Vec2 SlidingDoorModel::getHighestPosition()
{
	return b2Vec2(m_startingPosition.x , ((m_startingPosition.y) + (m_halfDoorHeight * 2)));
}

b2Vec2 SlidingDoorModel::getStartingPosition()
{
	return m_startingPosition;
}