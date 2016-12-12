//
//  MainMenuScene.cpp
//  TimeTale
//
//  Created by Hema Dubal on 25/04/16.
//
//

#include "MainMenuScene.h"
#include "SelectLevelScene.h"
#include "InfoScene.h"

MainMenuScene::MainMenuScene()
{
    
}

MainMenuScene::~MainMenuScene()
{
    
}

bool MainMenuScene::init()
{
    addSearchPath();
    Node* rootNode = static_cast<Node*>(CSLoader::createNode("MainMenuLayer.csb"));
    Node* bottomCenter = static_cast<Node*>(rootNode->getChildByName("bottomCenter"));
    Button* playButton = static_cast<Button*>(bottomCenter->getChildByName("playButton"));
    playButton->addTouchEventListener(CC_CALLBACK_1(MainMenuScene::playButtonClicked, this));
	Node* topRight = static_cast<Node*>(rootNode->getChildByName("topRight"));
	Button* infoButton = static_cast<Button*>(topRight->getChildByName("infoButton"));
	infoButton->addTouchEventListener(CC_CALLBACK_1(MainMenuScene::infoButtonClicked, this));
    addChild(rootNode);
    return true;
}

void MainMenuScene::playButtonClicked(Ref* pSender)
{
    auto selectLevelScene = SelectLevelScene::create();
    auto director = Director::getInstance();
    director->replaceScene(selectLevelScene);
}

void MainMenuScene::addSearchPath()
{
    std::vector<std::string> searchPath = FileUtils::getInstance()->getSearchPaths();
    searchPath.push_back("CSB");
    searchPath.push_back("images");
    FileUtils::getInstance()->setSearchPaths(searchPath);
}

void MainMenuScene::infoButtonClicked(Ref* pSender)
{
	auto infoScene = InfoScene::create();
	auto director = Director::getInstance();
	director->replaceScene(infoScene);
}