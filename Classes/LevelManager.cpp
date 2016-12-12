//
//  LevelAssetsManager.cpp
//  SlotSimulator
//
//  Created by Hema Dubal on 22/10/15.
//
//

#include "LevelManager.h"
#include "json/document.h"
//RapidJSON is a c++ library that helps in parsing json files
//Cocos2d comes with RapidJSON library (just like it comes with Box2d and similar
//other helpful code libraries. You can find the RapidJSON code in
//cocos2d-x-3.8.1/external/json directory. Since, we will be using RapidJSON, we
//include json/document.h header file

#include "LevelParser.h"

using namespace cocos2d;

LevelManager::LevelManager() : m_levelDef(nullptr)
{
	
}

void LevelManager::load(const int levelNumber)
{
    auto* fileUtils = FileUtils::getInstance();
	const char *format;
	format = "Levels/%d/LevelConfig.json";
	char str[100];
	sprintf(str, format, levelNumber);
	const std::string jsonfileName(str);
	if (fileUtils->isFileExist(jsonfileName))
	{
		const std::string jsonFileContents = fileUtils->getStringFromFile(jsonfileName);
        
        //One of the readymade classes in RapidJSON is Document
        //Document class represents parsed json document
        //By "parsed", it means that the text json contents are converted into
        //logical json objects represented in c++. What it facilitates is that you
        //can access hierarchical json objects and their methods (ex: finding length of
        //a json array).
		rapidjson::Document jsonDoc;
		jsonDoc.Parse<0>(jsonFileContents.c_str());
        assert(!jsonDoc.HasParseError() && "Levels JSON file contains error.");
        //This line parses the file contents and stores parsed json contents
        //in jsonDoc object
        
        //Now we will pass the parsed json document into levelParser
        LevelParser levelParser;
        //LevelParser's parseLevelDef method will find out the information
        //related to various objects from the json document, store all the information
        //in a LevelDefinition object and return a pointer to that object.
        //We will store that pointer in LevelManager.
		m_levelDef = levelParser.parseLevelDef(jsonDoc);
        
        //m_levelDef can get us the level-definition in the game's code.
	}
}

LevelDef* LevelManager::getLevelDef()
{
    return m_levelDef;
}
