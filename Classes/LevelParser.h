//
//  LevelParser.h
//
//  Created by Hema Dubal on 22/10/15.
//
//

#ifndef LevelParser_h__
#define LevelParser_h__

#include "json/document.h"
#include "LevelDef.h"
#include "cocos2d.h"

USING_NS_CC;

class LevelParser
{
private:
	

public:
    LevelParser();
    LevelDef* parseLevelDef(const rapidjson::Document& jsonDoc);
};

#endif //LevelParser_h__
