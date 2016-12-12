#include "GameScene.h"

GameScene* GameScene::create(const int levelNumber)
{
	GameScene *pRet = new(std::nothrow) GameScene();
	if (pRet && pRet->init(levelNumber))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

GameScene::GameScene() 
	: m_layer(nullptr)
	, m_HUDLayer(nullptr)
	, m_recordTime(nullptr)
{
}

bool GameScene::init(const int levelNumber)
{
	if (Scene::init() == false)
	{
		return false;
	}
	
	m_recordTime = new RecordTime();
	m_layer = GameLayer::create(levelNumber);
	addChild(m_layer, 0);
	m_HUDLayer = HUDLayer::create(m_layer, *m_recordTime);
	addChild(m_HUDLayer, 1);
    m_character = m_layer->getCharacter();
	scheduleUpdate();
	return true;
}

void GameScene::update(float dt)
{
	m_layer->update(dt);
	m_HUDLayer->update(dt, m_layer);
    m_character->update();
}