#include "GameLayer.h"
#include "GameOverScene.h"

GameLayer* GameLayer::create(const int levelNumber)
{
	GameLayer *pRet = new(std::nothrow) GameLayer(levelNumber);
	if (pRet && pRet->init())
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

GameLayer::GameLayer(const int levelNumber)
	: m_levelNumber(levelNumber)
	, m_world(b2Vec2(0.0f, -9.8f))
	, m_drawObj(PTM_RATIO)
	, m_character(nullptr)
	, m_terminatingDoor(nullptr)
	, m_levelDef(nullptr)
{
}

void GameLayer::addSearchPath()
{
    std::vector<std::string> searchPath = FileUtils::getInstance()->getSearchPaths();
    const char *format;
    format = "Levels/%d";
    char str[100];
    sprintf(str, format, m_levelNumber);
    const std::string searchPathForLevel(str);
    searchPath.push_back(searchPathForLevel);
    FileUtils::getInstance()->setSearchPaths(searchPath);
}

bool GameLayer::init()
{
	if (Layer::init() == false)
	{
		return false;
	}

    m_levelManager.load(m_levelNumber);
	m_levelDef = m_levelManager.getLevelDef();
    addSearchPath();
    
    //Background
    const char *format;
    format = "Levels/%d/Background.csb";
    char str[100];
    sprintf(str, format, m_levelNumber);
    const std::string backgroundCSB(str);
    Node* rootNode = static_cast<Node*>(CSLoader::createNode("Background.csb"));
    addChild(rootNode);
    
	//pushButtons
	for (auto& eachPushButtonDef : m_levelDef->pushButtons)
	{
		Vec2 positionOfPushButton(eachPushButtonDef.x, eachPushButtonDef.y);
		PushButton* pushButton = new PushButton(m_world, positionOfPushButton, eachPushButtonDef.id, eachPushButtonDef.reactID, this);
		m_pushButton.push_back(pushButton);
	}
	
	//stepButtons
	for (auto& eachStepButtonDef : m_levelDef->stepButtons)
	{
		Vec2 positionOfStepButton(eachStepButtonDef.x, eachStepButtonDef.y);
		StepButton* stepButton = new StepButton(m_world, positionOfStepButton, eachStepButtonDef.id, eachStepButtonDef.reactID, this);
		m_stepButton.push_back(stepButton);
	}

	//slidingDoors
	for (auto& eachSlidingDoorDef : m_levelDef->slidingDoors)
	{
		Vec2 positionOfSlidingDoor(eachSlidingDoorDef.x, eachSlidingDoorDef.y);
		SlidingDoor* slidingDoor = new SlidingDoor(m_world, positionOfSlidingDoor, eachSlidingDoorDef.id, eachSlidingDoorDef.reactID, this);
		m_slidingDoor.push_back(slidingDoor);
	}

	//movingPlatforms
	for (auto& eachMovingPlatformDef : m_levelDef->movingPlatforms)
	{
		Vec2 startPositionOfMovingPlatform(eachMovingPlatformDef.startX, eachMovingPlatformDef.startY);
		Vec2 endPositionOfMovingPlatform(eachMovingPlatformDef.endX, eachMovingPlatformDef.endY);
		MovingPlatform* movingPlatform = new MovingPlatform(m_world, eachMovingPlatformDef.id, startPositionOfMovingPlatform, endPositionOfMovingPlatform, eachMovingPlatformDef.velocityValue, eachMovingPlatformDef.type, this);
		m_movingPlatform.push_back(movingPlatform);
	}

	//lifts
	for (auto& eachLiftDef : m_levelDef->lifts)
	{
		Vec2 startPositionOfLift(eachLiftDef.startX, eachLiftDef.startY);
		Vec2 endPositionOfLift(eachLiftDef.endX, eachLiftDef.endY);
		Lift* lift = new Lift(m_world, eachLiftDef.id, eachLiftDef.reactID, startPositionOfLift, endPositionOfLift, eachLiftDef.velocityValue, eachLiftDef.type, this);
		m_lift.push_back(lift);
	}
    
    //terminatingDoor
    Vec2 positionOfTerminatingDoor(m_levelDef->terminatingDoor.x, m_levelDef->terminatingDoor.y);
    TerminatingDoor* terminatingDoor = new TerminatingDoor(m_world, positionOfTerminatingDoor, this);
    m_terminatingDoor = terminatingDoor;
    
    //Character
	b2Vec2 positionOfCharacter(m_levelDef->character.x, m_levelDef->character.y);
	Character* character = new Character(m_world, positionOfCharacter, this);
	m_character = character;

	//floor and floorsections
	for (rapidjson::SizeType i = 0; i < m_levelDef->floorSections.size(); ++i)
	{
		for (rapidjson::SizeType j = 0; j < m_levelDef->floorSections[i].floorPoints.size()-1; ++j)
		{
			Floor* floor = new Floor(m_world, m_levelDef->floorSections[i].floorPoints[j], m_levelDef->floorSections[i].floorPoints[j+1]);
			m_floor.push_back(floor);
		}
	}

	//inSpacePortals
	for (auto& eachInSpacePortal : m_levelDef->inSpacePortals)
	{
		Vec2 inPosition(eachInSpacePortal.inX, eachInSpacePortal.inY);
		Vec2 outPosition(eachInSpacePortal.outX, eachInSpacePortal.outY);
		InSpacePortal* inSpacePortal = new InSpacePortal(m_world, inPosition, outPosition, eachInSpacePortal.id, eachInSpacePortal.reactID, this);
		m_inSpacePortal.push_back(inSpacePortal);
	}
	
	//outSpacePortals
	for (auto& eachOutSpacePortal : m_levelDef->outSpacePortals)
	{
		Vec2 inPosition(eachOutSpacePortal.inX, eachOutSpacePortal.inY);
		Vec2 outPosition(eachOutSpacePortal.outX, eachOutSpacePortal.outY);
		OutSpacePortal* outSpacePortal = new OutSpacePortal(m_world, inPosition, outPosition, eachOutSpacePortal.id, eachOutSpacePortal.reactID, this);
		m_outSpacePortal.push_back(outSpacePortal);
	}

	//pushableBlocks
	for (auto& eachPushableBlock : m_levelDef->pushableBlocks)
	{
		Vec2 position(eachPushableBlock.x, eachPushableBlock.y);
		PushableBlock* pushableBlock = new PushableBlock(m_world, eachPushableBlock.id, position, this);
		m_pushableBlock.push_back(pushableBlock);
	}

	initializeDebugDraw();
	m_world.SetContactListener(&m_collisionHandler);
	return true;
}

void GameLayer::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags)
{
	Layer::draw(renderer, transform, flags);
	if (m_levelNumber == 2)
    {
        Director* director = Director::getInstance();
        director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
        director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, transform);

        GL::enableVertexAttribs(cocos2d::GL::VERTEX_ATTRIB_FLAG_POSITION);

        m_world.DrawDebugData();

        CHECK_GL_ERROR_DEBUG();

        director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    }
}

void GameLayer::update(float deltatime)
{
	CharacterModel* cmInGameLayer = static_cast<CharacterModel*>(m_character->getModel());
	Vec2 positionBeforeStep = Utils::meterPositionToPX(m_character->getPosition());
	m_world.Step(deltatime, 4, 4);

    m_character->updatePositionBasedOnPhysics();
    
    for (auto pushButton : m_pushButton)
    {
        pushButton->updatePositionBasedOnPhysics();
    }
    for (auto stepButton : m_stepButton)
    {
        stepButton->updatePositionBasedOnPhysics();
    }
    for (auto slidingDoor : m_slidingDoor)
    {
        slidingDoor->updatePositionBasedOnPhysics();
    }
    for (auto movingPlatform : m_movingPlatform)
    {
        movingPlatform->updatePositionBasedOnPhysics();
    }
    for (auto floor : m_floor)
    {
        floor->updatePositionBasedOnPhysics();
    }
    for (auto lift : m_lift)
    {
        lift->updatePositionBasedOnPhysics();
    }
    for (auto pushableBlock : m_pushableBlock)
    {
        pushableBlock->updatePositionBasedOnPhysics();
    }
    
    m_terminatingDoor->updatePositionBasedOnPhysics();
    
	Vec2 positionAfterStep = Utils::meterPositionToPX(m_character->getPosition());
	Vec2 positionOfScreen = Director::getInstance()->getVisibleSize();
	Vec2 positionOfCharacter = this->getPosition() + positionAfterStep;

	if (positionOfCharacter.x >= positionOfScreen.x / 2)
	{
		this->setPositionX(this->getPositionX() - (positionOfCharacter.x - (positionOfScreen.x / 2)));
	}

	if (positionOfCharacter.x <= positionOfScreen.x / 5)
	{
		this->setPositionX(this->getPositionX() + ((positionOfScreen.x / 5) - positionOfCharacter.x));
	}

	checkForSpacePortalEntrance(cmInGameLayer);

	checkForGameOver(cmInGameLayer);
}

void GameLayer::checkForSpacePortalEntrance(CharacterModel* characterModel)
{
	if (characterModel->getInSpacePortalModel() != nullptr)
	{
		b2Vec2 outPosition = characterModel->getInSpacePortalModel()->getOutPosition();
		characterModel->getPhysicsObject()->SetTransform(outPosition, 0);
		characterModel->getPhysicsObject()->ApplyForce(b2Vec2(1.0f, 0.0f), b2Vec2(0.0f, 0.0f), true);
		characterModel->setInSpacePortalModelNull();
	}
}

void GameLayer::checkForGameOver(CharacterModel* characterModel)
{
	if (characterModel->getPosition().y <= this->getPosition().y)
	{
		auto gameOverScene = GameOverScene::create();
		auto director = Director::getInstance();
		director->replaceScene(gameOverScene);
	}
}

void GameLayer::checkForInteraction()
{
	for (int i = 0; i < m_pushButton.size(); i++)
	{
		CCLOG("PUSH BUTTON SIZE : %d", m_pushButton.size());
		if (m_pushButton[i]->getInteractionStatus())
		{
			if (m_pushButton[i]->getPushButtonState() == PushButtonStates::OFF)
			{
				m_pushButton[i]->setPushButtonState(PushButtonStates::ON);
			}
			else
			{
				m_pushButton[i]->setPushButtonState(PushButtonStates::OFF);
			}
			m_pushButton[i]->dispatchEvent();
		}
	}
}

Character* GameLayer::getCharacter()
{
	return m_character;
}

void GameLayer::initializeDebugDraw()
{
	//for debug draw
	uint32 flags = 0;
	flags += b2Draw::e_shapeBit;
	//flags += b2Draw::e_jointBit;
	//flags += b2Draw::e_aabbBit;
	flags += b2Draw::e_centerOfMassBit;

	m_drawObj.SetFlags(flags);
	m_world.SetDebugDraw(&m_drawObj);
}
