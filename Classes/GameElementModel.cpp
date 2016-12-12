#include "GameElementModel.h"

GameElementModel::GameElementModel(GameElementType gameElementType) 
	: m_gameElementType(gameElementType)
	, m_physicsObject(nullptr)
{
}

GameElementType GameElementModel::getGameElementType()
{
	return m_gameElementType;
}

b2Body* GameElementModel::getPhysicsObject()
{
	return m_physicsObject;
}

b2Vec2 GameElementModel::getPosition()
{
    return m_physicsObject->GetPosition();
}