//
//  InfoScene.cpp
//  TimeTale
//
//  Created by Hema Dubal on 25/04/16.
//
//

#include "InfoScene.h"
#include "MainMenuScene.h"

InfoScene::InfoScene()
{
    
}

InfoScene::~InfoScene()
{
    
}

bool InfoScene::init()
{
    addSearchPath();
    Node* rootNode = static_cast<Node*>(CSLoader::createNode("InfoLayer.csb"));
    Node* topLeft = static_cast<Node*>(rootNode->getChildByName("topLeft"));
    Button* backButton = static_cast<Button*>(topLeft->getChildByName("btnBack"));
    backButton->addTouchEventListener(CC_CALLBACK_1(InfoScene::backButtonClicked, this));
    addChild(rootNode);
    return true;
}

void InfoScene::backButtonClicked(Ref* pSender)
{
    auto mainMenuScene = MainMenuScene::create();
    auto director = Director::getInstance();
    director->replaceScene(mainMenuScene);
}

void InfoScene::addSearchPath()
{
    std::vector<std::string> searchPath = FileUtils::getInstance()->getSearchPaths();
    searchPath.push_back("CSB");
    searchPath.push_back("images");
    FileUtils::getInstance()->setSearchPaths(searchPath);
}