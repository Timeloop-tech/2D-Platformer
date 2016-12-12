#ifndef _GAME_LAYER_H_
#define _GAME_LAYER_H_

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "Floor.h"
#include "Character.h"
#include "StepButton.h"
#include "PushButton.h"
#include "SlidingDoor.h"
#include "MovingPlatform.h"
#include "Lift.h"
#include "InSpacePortal.h"
#include "OutSpacePortal.h"
#include "GLES-Render.h"
#include "CollisionHandler.h"
#include "Events.h"
#include "LevelManager.h"
#include "LevelDef.h"
#include "json/document.h"
#include "InSpacePortalModel.h"
#include "OutSpacePortalModel.h"
#include "PushableBlock.h"
#include "TerminatingDoor.h"
#include "Utils.h"

USING_NS_CC;

class GameLayer : public Layer 
{
private:
	const int						m_levelNumber;
	b2World							m_world;
	std::vector<PushButton*>		m_pushButton;
	std::vector<StepButton*>		m_stepButton;
	std::vector<SlidingDoor*>		m_slidingDoor;
	std::vector<MovingPlatform*>	m_movingPlatform;
	Character*						m_character;
	std::vector<Floor*>				m_floor;
	std::vector<Lift*>				m_lift;
	std::vector<InSpacePortal*>		m_inSpacePortal;
	std::vector<OutSpacePortal*>	m_outSpacePortal;
	std::vector<PushableBlock*>		m_pushableBlock;
	TerminatingDoor*				m_terminatingDoor;
	GLESDebugDraw					m_drawObj;
    CollisionHandler				m_collisionHandler;
	LevelManager					m_levelManager;
	LevelDef*						m_levelDef;
    
	GameLayer(const int levelNumber);
	void initializeDebugDraw();

public:
	static GameLayer* create(const int levelNumber);
    void addSearchPath();
	virtual bool init();
	Character* getCharacter();
	void update(float deltatime);
	void checkForSpacePortalEntrance(CharacterModel* characterModel);
	void checkForGameOver(CharacterModel* characterModel);
	void checkForInteraction();
	virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags);
};

#endif