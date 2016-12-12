#include "GameElement.h"
#include "Utils.h"

GameElement::GameElement(GameElementModel* model, GameElementView* view)
	: m_model(model)
	, m_view(view)
{
    
}

GameElementModel* GameElement::getModel()
{
	return m_model;
}

GameElementType GameElement::getGameElementType()
{
    return m_model->getGameElementType();
}

void GameElement::updatePositionBasedOnPhysics()
{
    Vec2 physicsBodyPositionInPX = Utils::meterPositionToPX(getPosition());
    m_view->setPosition(physicsBodyPositionInPX);
}

b2Vec2 GameElement::getPosition()
{
    return m_model->getPosition();
}