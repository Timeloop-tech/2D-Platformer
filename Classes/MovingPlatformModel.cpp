#include "MovingPlatformModel.h"

MovingPlatformModel::MovingPlatformModel(b2World& world, b2Vec2 startPoint, b2Vec2 endPoint, float velocityValue, Type type)
	: GameElementModel(GameElementType::MovingPlatform)
	, m_PlatformType(type)
	, m_velocity(b2Vec2_zero)
	, m_velocityValue(velocityValue)
	, m_startPoint(startPoint)
	, m_endPoint(endPoint)
{
	b2BodyDef movingPlatformBodyDef;
	b2FixtureDef movingPlatformFixtureDef;
	b2EdgeShape movingPlatformEdge;

	movingPlatformBodyDef.type = b2_kinematicBody;
	movingPlatformBodyDef.position.Set(startPoint.x, startPoint.y);

	b2Vec2 endOfEdge = b2Vec2(2, 0);
	movingPlatformEdge.Set(b2Vec2_zero, endOfEdge);
	
	movingPlatformFixtureDef.shape = &movingPlatformEdge;

	m_physicsObject = world.CreateBody(&movingPlatformBodyDef);
	m_physicsObject->CreateFixture(&movingPlatformFixtureDef);
}

void MovingPlatformModel::setUserData(MovingPlatform* movingPlatform)
{
    m_physicsObject->SetUserData(movingPlatform);
}

void MovingPlatformModel::updatePlatform(float dt)
{
	if (m_PlatformType == Type::horizontal)
	{
		m_velocity.Set(m_velocityValue, 0);
		if (m_physicsObject->GetPosition().x <= m_startPoint.x)
		{
			m_physicsObject->SetLinearVelocity(m_velocity);
		}
		if (m_physicsObject->GetPosition().x >= m_endPoint.x)
		{
			m_velocity.Set((m_velocity.x * (-1.0f)), 0);
			m_physicsObject->SetLinearVelocity(m_velocity);
		}
	}
	else
	{
		m_velocity.Set(0, m_velocityValue);
		if (m_physicsObject->GetPosition().y <= m_startPoint.y)
		{
			m_physicsObject->SetLinearVelocity(m_velocity);
		}
		if (m_physicsObject->GetPosition().y >= m_endPoint.y)
		{
			m_velocity.Set(0, (m_velocity.y * (-1.0f)));
			m_physicsObject->SetLinearVelocity(m_velocity);
		}
	}
}

