#include "CharacterModel.h"

USING_NS_CC;

CharacterModel::CharacterModel(b2World& world, b2Vec2 position)
	: GameElementModel(GameElementType::Character)
	, m_isTouchingFloor(false)
	, m_touchCount(0)
	, m_rightForce(7.0f, 0.0f)
	, m_leftForce(-7.0f, 0.0f)
	, m_jumpImpulse(0.0f, 6.5f)
	, m_inSpacePortalModel(nullptr)
	, m_outSpacePortalModel(nullptr)
{
	b2BodyDef characterDef;
	b2FixtureDef characterFixtureDef, sensorFixtureDef;
	b2PolygonShape characterPolygon, sensorPolygon;

	characterDef.type = b2_dynamicBody;
	characterDef.position.Set(position.x, position.y);

	const float halfBoxWidth = 0.37f;
	const float halfBoxHeight = 0.37f;
	characterPolygon.SetAsBox(halfBoxWidth, halfBoxHeight);

	const float halfSensorWidth = 0.38f;
	const float halfSensorHeight = 0.38f;
	//const b2Vec2 sensorOffset(0.0f, -0.42f);
	//const float sensorAngle = 0.0f;
	sensorPolygon.SetAsBox(halfSensorWidth, halfSensorHeight);// , sensorOffset, sensorAngle);

	characterFixtureDef.shape = &characterPolygon;
	characterFixtureDef.density = 1.5;
	characterFixtureDef.restitution = 0;
    characterFixtureDef.friction = 1;
	sensorFixtureDef.shape = &sensorPolygon;
	sensorFixtureDef.isSensor = true;
	
	m_physicsObject = world.CreateBody(&characterDef);
	m_physicsObject->CreateFixture(&characterFixtureDef);
	m_physicsObject->CreateFixture(&sensorFixtureDef);
}

void CharacterModel::setUserData(Character* character)
{
    m_physicsObject->SetUserData(character);
}

void CharacterModel::updateState(CharacterState state)
{
    m_characterState = state;
    switch (m_characterState)
    {
        case CharacterState::Stand:

            break;
        case CharacterState::MoveLeft:
            moveLeft();
            break;
        case CharacterState::MoveRight:
            moveRight();
            break;
        case CharacterState::Jump:
            jump();
            break;
    }
}

bool CharacterModel::canJump()
{
	return m_isTouchingFloor;
}

void CharacterModel::setCanJumpStatus()
{
	if (m_touchCount > 0)
	{
		m_isTouchingFloor = true;
		CCLOG("TOUCHING FLOOR!!!!!!!!!!!!!..., %d" , m_touchCount);
	}
	else
	{
		m_isTouchingFloor = false;
		CCLOG("NOT TOUCHING FLOOR!!!!!!... %d", m_touchCount);
	}
}

bool CharacterModel::getCanJumpStatus()
{
    return m_isTouchingFloor;
}

void CharacterModel::jump()
{
	if (m_isTouchingFloor == true)
		m_physicsObject->ApplyLinearImpulse(m_jumpImpulse, m_physicsObject->GetWorldCenter(), true);
}

void CharacterModel::moveLeft()
{
	m_physicsObject->ApplyForce(m_leftForce, m_physicsObject->GetWorldCenter(), true);
}

void CharacterModel::moveRight()
{
	m_physicsObject->ApplyForce(m_rightForce, m_physicsObject->GetWorldCenter(), true);
}

void CharacterModel::incrementTouchCount()
{
	m_touchCount++;
	setCanJumpStatus();
}

void CharacterModel::decrementTouchCount()
{
	if (m_touchCount > 0)
	{
		m_touchCount--;
	}
	setCanJumpStatus();
}

InSpacePortalModel* CharacterModel::getInSpacePortalModel()
{
	return m_inSpacePortalModel;
}

OutSpacePortalModel* CharacterModel::getOutSpacePortalModel()
{
	return m_outSpacePortalModel;
}

void CharacterModel::setInSpacePortalModelNull()
{
	m_inSpacePortalModel = nullptr;
}

void CharacterModel::setOutSpacePortalModelNull()
{
	m_outSpacePortalModel = nullptr;
}

void CharacterModel::changePositionDueToSpacePortal(InSpacePortalModel* inSpacePortalModel)
{
	m_inSpacePortalModel = inSpacePortalModel;
}