#include "FloorModel.h"

FloorModel::FloorModel(b2World& world, b2Vec2 startPoint, b2Vec2 endPoint) 
	: GameElementModel(GameElementType::Floor)
{
	b2BodyDef floorBodyDef;
	b2FixtureDef floorFixtureDef;
	b2EdgeShape floorEdge;

	floorBodyDef.type = b2_staticBody;
	floorBodyDef.position.Set(startPoint.x , startPoint.y);
	b2Vec2 floorEndPointRelative = endPoint - startPoint;
	floorEdge.Set(b2Vec2(0,0) , floorEndPointRelative);

	floorFixtureDef.shape = &floorEdge;

	m_physicsObject = world.CreateBody(&floorBodyDef);
	m_physicsObject->CreateFixture(&floorFixtureDef);
}

void FloorModel::setUserData(Floor* floor)
{
    m_physicsObject->SetUserData(floor);
}

