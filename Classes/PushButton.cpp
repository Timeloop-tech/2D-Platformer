#include "PushButton.h"

PushButton::PushButton(b2World& world, Vec2 position, int ID, int reactID, Node* parent)
: GameElement(new PushButtonModel(world, b2Vec2(position.x / PTM_RATIO, position.y / PTM_RATIO), reactID), PushButtonView::create())
	, m_pushButtonID(ID)
{
    m_pushButtonModel = static_cast<PushButtonModel*>(m_model);
    m_pushButtonView = static_cast<PushButtonView*>(m_view);
    parent->addChild(m_pushButtonView);
    m_pushButtonModel->setUserData(this);
}

PushButtonStates PushButton::getPushButtonState()
{
	return m_pushButtonModel->getPushButtonState();
}

void PushButton::setPushButtonState(PushButtonStates state)
{
	m_pushButtonModel->setPushButtonState(state);
}

bool PushButton::getInteractionStatus()
{
	return m_pushButtonModel->getInteractionStatus();
}

void PushButton::setInteractionStatus(bool status)
{
	m_pushButtonModel->setInteractionStatus(status);
}

void PushButton::dispatchEvent()
{
    m_pushButtonModel->dispatchEvent();
}