#include "OutSpacePortal.h"

OutSpacePortal::OutSpacePortal(b2World& world, Vec2 inPosition, Vec2 outPosition, int ID, int reactID, Node* parent)
: GameElement(new OutSpacePortalModel(world, Utils::pixelPositionToMeter(inPosition), Utils::pixelPositionToMeter(outPosition), ID, reactID), OutSpacePortalView::create())
{
    m_outSpacePortalModel = static_cast<OutSpacePortalModel*>(m_model);
    m_outSpacePortalView = static_cast<OutSpacePortalView*>(m_view);
    parent->addChild(m_outSpacePortalView);
    m_outSpacePortalModel->setUserData(this);
}

b2Vec2 OutSpacePortal::getInPosition()
{
    return m_outSpacePortalModel->getInPosition();
}

b2Vec2 OutSpacePortal::getOutPosition()
{
    return m_outSpacePortalModel->getOutPosition();
}