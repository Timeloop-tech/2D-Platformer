#include "TerminatingDoor.h"

TerminatingDoor::TerminatingDoor(b2World& world, Vec2 position, Node* parent)
: GameElement(new TerminatingDoorModel(world, Utils::pixelPositionToMeter(position)), TerminatingDoorView::create())
{
    m_terminatingDoorModel = static_cast<TerminatingDoorModel*>(m_model);
    m_terminatingDoorView = static_cast<TerminatingDoorView*>(m_view);
    parent->addChild(m_terminatingDoorView);
    m_terminatingDoorModel->setUserData(this);
}

bool TerminatingDoor::getInteractionStatus()
{
    return m_terminatingDoorModel->getInteractionStatus();
}

void TerminatingDoor::setInteractionStatus(bool status)
{
    m_terminatingDoorModel->setInteractionStatus(status);
}
