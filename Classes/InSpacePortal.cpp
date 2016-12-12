#include "InSpacePortal.h"

InSpacePortal::InSpacePortal(b2World& world, Vec2 inPosition, Vec2 outPosition, int ID, int reactID, Node* parent)
: GameElement(new InSpacePortalModel(world, Utils::pixelPositionToMeter(inPosition), Utils::pixelPositionToMeter(outPosition), ID, reactID), InSpacePortalView::create())
{
    m_inSpacePortalModel = static_cast<InSpacePortalModel*>(m_model);
    m_inSpacePortalView = static_cast<InSpacePortalView*>(m_view);
    parent->addChild(m_inSpacePortalView);
    m_inSpacePortalModel->setUserData(this);
}

b2Vec2 InSpacePortal::getInPosition()
{
    return m_inSpacePortalModel->getInPosition();
}

b2Vec2 InSpacePortal::getOutPosition()
{
    return m_inSpacePortalModel->getOutPosition();
}