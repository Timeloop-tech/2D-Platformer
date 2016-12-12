#include "Floor.h"

Floor::Floor(b2World& world, FloorPoints startPoint, FloorPoints endPoint)
	: GameElement(new FloorModel(world, Utils::pixelPositionToMeter(unpackPoints(startPoint)), Utils::pixelPositionToMeter(unpackPoints(endPoint))), new FloorView())
{
    m_floorModel = static_cast<FloorModel*>(m_model);
    m_floorView = static_cast<FloorView*>(m_view);
    m_floorModel->setUserData(this);
}

Vec2 Floor::unpackPoints(FloorPoints currentPoint)
{
	const float x = currentPoint.x;
	const float y = currentPoint.y;
	return Vec2(x, y);
}

