//
//  GameOverScene.cpp
//  TimeTale
//
//  Created by Hema Dubal on 25/04/16.
//
//

#include "GameOverScene.h"
#include "MainMenuScene.h"

GameOverScene::GameOverScene()
{
    
}

GameOverScene::~GameOverScene()
{
    
}

bool GameOverScene::init()
{
    addSearchPath();
    Node* rootNode = static_cast<Node*>(CSLoader::createNode("GameOverLayer.csb"));
    Node* center = static_cast<Node*>(rootNode->getChildByName("center"));
    Button* mainMenuButton = static_cast<Button*>(center->getChildByName("btnMainMenu"));
    mainMenuButton->addTouchEventListener(CC_CALLBACK_1(GameOverScene::mainMenuButtonClicked, this));
    addChild(rootNode);
    return true;
}

void GameOverScene::mainMenuButtonClicked(Ref* pSender)
{
    auto mainMenuScene = MainMenuScene::create();
    auto director = Director::getInstance();
    director->replaceScene(mainMenuScene);
}

void GameOverScene::addSearchPath()
{
    std::vector<std::string> searchPath = FileUtils::getInstance()->getSearchPaths();
    searchPath.push_back("CSB");
    searchPath.push_back("images");
    FileUtils::getInstance()->setSearchPaths(searchPath);
}