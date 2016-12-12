#include "PushableBlock.h"

PushableBlock::PushableBlock(b2World& world, int ID, Vec2 position, Node* parent)
: GameElement(new PushableBlockModel(world, Utils::pixelPositionToMeter(position), ID), PushableBlockView::create())
{
    m_pushableBlockModel = static_cast<PushableBlockModel*>(m_model);
    m_pushableBlockView = static_cast<PushableBlockView*>(m_view);
    parent->addChild(m_pushableBlockView);
    m_pushableBlockModel->setUserData(this);
}