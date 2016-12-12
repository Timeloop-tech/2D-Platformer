#include "StepButton.h"

int StepButton::m_countTotal = 0;

StepButton::StepButton(b2World& world, Vec2 position, int ID, int reactID, Node* parent)
: GameElement(new StepButtonModel(world, b2Vec2(position.x/PTM_RATIO, position.y/PTM_RATIO), m_reactID = reactID), StepButtonView::create())
	, m_stepButtonID(ID)
{
    m_stepButtonModel = static_cast<StepButtonModel*>(m_model);
    m_stepButtonView = static_cast<StepButtonView*>(m_view);
    parent->addChild(m_stepButtonView);
    m_stepButtonModel->setUserData(this);
}

StepButtonStates StepButton::getSteppedStatus()
{
    return static_cast<StepButtonModel*>(m_model)->getSteppedStatus();
}

void StepButton::steppedOut()
{
    m_stepButtonModel->steppedOut();
}

void StepButton::steppedOn()
{
    m_stepButtonModel->steppedOn();
}

void StepButton::dispatchEvent()
{
    m_stepButtonModel->dispatchEvent();
}