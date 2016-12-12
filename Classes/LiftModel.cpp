#include "LiftModel.h"

LiftModel::LiftModel(b2World& world, int ID, int reactID, b2Vec2 startPosition, b2Vec2 endPosition, float velocity, Type type)
	: GameElementModel(GameElementType::Lift)
	, m_liftID(ID)
	, m_liftType(type)
	, m_velocityValue(velocity)
	, m_velocity(b2Vec2_zero)
	, m_endPoint(endPosition)
	, m_startPoint(startPosition)
{
	b2BodyDef liftBodyDef;
	b2FixtureDef liftFixtureDef;
	b2EdgeShape liftEdge;

	liftBodyDef.type = b2_kinematicBody;
	liftBodyDef.position.Set(startPosition.x, startPosition.y);
	
	b2Vec2 endPointForEdge = b2Vec2(2, 0);
	liftEdge.Set(b2Vec2_zero, endPointForEdge);

	liftFixtureDef.shape = &liftEdge;

	m_physicsObject = world.CreateBody(&liftBodyDef);
	m_physicsObject->CreateFixture(&liftFixtureDef);
}

void LiftModel::setUserData(Lift* lift)
{
    m_physicsObject->SetUserData(lift);
}

void LiftModel::moveLiftUpwards()
{
	if (m_liftType == Type::horizontal)
	{
		m_velocity.Set(m_velocityValue, 0);
		m_physicsObject->SetLinearVelocity(m_velocity);
	}
	else
	{
		m_velocity.Set(0, m_velocityValue);
		m_physicsObject->SetLinearVelocity(m_velocity);
		if (m_physicsObject->GetPosition().y >= m_endPoint.y)
		{
			m_physicsObject->SetLinearVelocity(b2Vec2_zero);
		}
	}
}

void LiftModel::moveLiftDownwards()
{
	if (m_liftType == Type::horizontal)
	{
		m_velocity.Set(m_velocityValue * (-1), 0);
		m_physicsObject->SetLinearVelocity(m_velocity);
		if (m_physicsObject->GetPosition().x <= m_startPoint.x)
		{
			m_physicsObject->SetLinearVelocity(b2Vec2_zero);
		}
	}
	else
	{
		m_velocity.Set(0, m_velocityValue * (-1));
		m_physicsObject->SetLinearVelocity(m_velocity);
		if (m_physicsObject->GetPosition().y <= m_startPoint.y)
		{
			m_physicsObject->SetLinearVelocity(b2Vec2_zero);
		}
	}
}

void LiftModel::setVelocityToZero()
{
	m_physicsObject->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
}

