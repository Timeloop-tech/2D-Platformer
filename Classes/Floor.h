#ifndef _FLOOR_H_
#define _FLOOR_H_

#include "cocos2d.h"
#include "GameElement.h"
#include "FloorView.h"
#include "FloorModel.h"
#include "Utils.h"
#include "LevelDef.h"

class FloorModel;

class Floor : public GameElement 
{
    FloorModel*     m_floorModel;
    FloorView*      m_floorView;
    
public:
	Floor(b2World& world, FloorPoints startPoint, FloorPoints endPoint);
	Vec2 unpackPoints(FloorPoints currentPoint);
};
#endif
