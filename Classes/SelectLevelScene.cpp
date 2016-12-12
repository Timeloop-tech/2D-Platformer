//
//  InfoScene.cpp
//  TimeTale
//
//  Created by Hema Dubal on 25/04/16.
//
//

#include "SelectLevelScene.h"
#include "MainMenuScene.h"
#include "GameScene.h"

SelectLevelScene::SelectLevelScene()
{
    
}

SelectLevelScene::~SelectLevelScene()
{
    
}

bool SelectLevelScene::init()
{
    addSearchPath();
    Node* rootNode = static_cast<Node*>(CSLoader::createNode("SelectLevelLayer.csb"));
    Node* topLeft = static_cast<Node*>(rootNode->getChildByName("topLeft"));
    Button* backButton = static_cast<Button*>(topLeft->getChildByName("btnBack"));
    backButton->addTouchEventListener(CC_CALLBACK_1(SelectLevelScene::backButtonClicked, this));
	Node* center = static_cast<Node*>(rootNode->getChildByName("center"));
	Button* level1Button = static_cast<Button*>(center->getChildByName("btnLevel1"));
	level1Button->addTouchEventListener(CC_CALLBACK_1(SelectLevelScene::level1Clicked, this));
	Button* level2Button = static_cast<Button*>(center->getChildByName("btnLevel2"));
	level2Button->addTouchEventListener(CC_CALLBACK_1(SelectLevelScene::level2Clicked, this));
	Button* level3Button = static_cast<Button*>(center->getChildByName("btnLevel3"));
	level3Button->addTouchEventListener(CC_CALLBACK_1(SelectLevelScene::level3Clicked, this));
    addChild(rootNode);
    return true;
}

void SelectLevelScene::addSearchPath()
{
	std::vector<std::string> searchPath = FileUtils::getInstance()->getSearchPaths();
	searchPath.push_back("CSB");
	searchPath.push_back("images");
	FileUtils::getInstance()->setSearchPaths(searchPath);
}

void SelectLevelScene::backButtonClicked(Ref* pSender)
{
    auto mainMenuScene = MainMenuScene::create();
    auto director = Director::getInstance();
    director->replaceScene(mainMenuScene);
}

void SelectLevelScene::level1Clicked(Ref* pSender)
{
	auto gameScene = GameScene::create(1);
	auto director = Director::getInstance();
	director->replaceScene(gameScene);
}

void SelectLevelScene::level2Clicked(Ref* pSender)
{
	auto gameScene = GameScene::create(2);
	auto director = Director::getInstance();
	director->replaceScene(gameScene);
}

void SelectLevelScene::level3Clicked(Ref* pSender)
{
	//Do nothing
}