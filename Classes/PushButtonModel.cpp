#include "PushButtonModel.h"

PushButtonModel::PushButtonModel(b2World& world, b2Vec2 position, int reactID)
	: GameElementModel(GameElementType::PushButton)
	, m_interactionEnabled(false)
	, m_isActivated(false)
	, m_reactID(reactID)
{
	b2BodyDef		pushButtonBodyDef;
	b2FixtureDef	pushButtonFixtureDef;
	b2CircleShape	circleShape;

	pushButtonBodyDef.type = b2_staticBody;
	pushButtonBodyDef.position.Set(position.x, position.y);

	//const float offsetX = 1.0f;						// doubt, For what is circleShape.m_p is used ?
	//const float offsetY = 1.0f;
	circleShape.m_radius = 0.718;
	//circleShape.m_p.Set(offsetX, offsetY);

	pushButtonFixtureDef.shape = &circleShape;
	pushButtonFixtureDef.isSensor = true;

	m_physicsObject = world.CreateBody(&pushButtonBodyDef);
	m_physicsObject->CreateFixture(&pushButtonFixtureDef);
}

bool PushButtonModel::getInteractionStatus()
{
	return m_interactionEnabled;
}

void PushButtonModel::setInteractionStatus(bool status)
{
	m_interactionEnabled = status;
}

void PushButtonModel::setUserData(PushButton* pushButton)
{
    m_physicsObject->SetUserData(pushButton);
}

PushButtonStates PushButtonModel::getPushButtonState()
{
	return m_state;
}

void PushButtonModel::setPushButtonState(PushButtonStates state)
{
    m_state = state;
}

void PushButtonModel::dispatchEvent()
{
    if (m_state == PushButtonStates::ON)
	{
		EventDispatcher* _eventDispatcher = Director::getInstance()->getEventDispatcher();
		_eventDispatcher->dispatchCustomEvent(PUSH_BUTTON_PRESSED_EVENT, &m_reactID);
	}
	else
	{
		EventDispatcher* _eventDispatcher = Director::getInstance()->getEventDispatcher();
		_eventDispatcher->dispatchCustomEvent(PUSH_BUTTON_RELEASED_EVENT, &m_reactID);
	}
}
