#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include "cocos2d.h"
#include "GameLayer.h"
#include "HUDLayer.h"
#include "RecordTime.h"

USING_NS_CC;

class GameScene : public Scene
{
private:
	GameLayer*						m_layer;
	HUDLayer*						m_HUDLayer;
	RecordTime*						m_recordTime;
    Character*      m_character;
    
public:
	GameScene();
	void update(float dt);
	static GameScene* create(const int levelNumber);
	bool init(const int levelNumber);
};
#endif