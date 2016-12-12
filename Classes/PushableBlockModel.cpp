#include "PushableBlockModel.h"

PushableBlockModel::PushableBlockModel(b2World& world, b2Vec2 position, int ID)
	:GameElementModel(GameElementType::PushableBlock)
{
	b2BodyDef pushableBlockBodyDef;
	b2FixtureDef pushableBlockFixtureDef;
	b2PolygonShape pushableBlockShape;

	pushableBlockBodyDef.type = b2_dynamicBody;
	pushableBlockBodyDef.position.Set(position.x, position.y);
	
	pushableBlockShape.SetAsBox(1.0f, 1.0f);
	
	pushableBlockFixtureDef.density = 0.5;
	pushableBlockFixtureDef.shape = &pushableBlockShape;

	m_physicsObject = world.CreateBody(&pushableBlockBodyDef);
	m_physicsObject->CreateFixture(&pushableBlockFixtureDef);
}

void PushableBlockModel::setUserData(PushableBlock* pushableBlock)
{
    m_physicsObject->SetUserData(pushableBlock);
}
