#include "StepButtonModel.h"

StepButtonModel::StepButtonModel(b2World& world, b2Vec2 position, int ID)
	: GameElementModel(GameElementType::StepButton)
	, m_stepCount(0)
	, m_reactID(ID)
{

	b2BodyDef stepButtonBodydef;
	b2FixtureDef stepButtonFixtureDef;
	b2PolygonShape shapeDef;
	b2Vec2 vertices[4];
	vertices[0].Set(0, 0);
	vertices[1].Set(0, 0.2f);
	vertices[2].Set(2, 0.2f);
	vertices[3].Set(2, 0);

	stepButtonBodydef.type = b2_staticBody;
	stepButtonBodydef.position.Set(position.x, position.y);

	shapeDef.Set(vertices, 4);

	stepButtonFixtureDef.isSensor = true;
	stepButtonFixtureDef.shape = &shapeDef;

	m_physicsObject = world.CreateBody(&stepButtonBodydef);
	m_physicsObject->CreateFixture(&stepButtonFixtureDef);
}

void StepButtonModel::setUserData(StepButton* stepButton)
{
    m_physicsObject->SetUserData(stepButton);
}

void StepButtonModel::steppedOn()
{
    m_stepCount++;
}

void StepButtonModel::steppedOut()
{
    m_stepCount--;
    if (m_stepCount < 0)
    {
        m_stepCount = 0;
    }
}

StepButtonStates StepButtonModel::getSteppedStatus()
{
    if (m_stepCount > 0)
    {
        return StepButtonStates::ON;
    }
    else
    {
        return StepButtonStates::OFF;
    }
}

void StepButtonModel::dispatchEvent()
{
	if (getSteppedStatus() == StepButtonStates::ON)
	{
		EventDispatcher* _eventDispatcher = Director::getInstance()->getEventDispatcher();
		_eventDispatcher->dispatchCustomEvent(STEP_BUTTON_PRESSED_EVENT, &m_reactID);
	}
	else
	{
		EventDispatcher* _eventDispatcher = Director::getInstance()->getEventDispatcher();
		_eventDispatcher->dispatchCustomEvent(STEP_BUTTON_RELEASED_EVENT, &m_reactID);
	}
}