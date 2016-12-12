//
//  LevelAssetsParser.cpp
//  SlotSimulator
//
//  Created by Hema Dubal on 22/10/15.
//
//

#include "LevelParser.h"

LevelParser::LevelParser()
{
}

LevelDef* LevelParser::parseLevelDef(const rapidjson::Document& jsonDoc)
{
    //In RapidJSON, there is a class called Value that represents any json value
    //such as an array
	const rapidjson::Value& floorSectionInfoArray = jsonDoc["floorSection"];
	const rapidjson::Value& pushButtonInfoArray = jsonDoc["pushButton"];
	const rapidjson::Value& stepButtonInfoArray = jsonDoc["stepButton"];
	const rapidjson::Value& slidingDoorInfoArray = jsonDoc["slidingDoor"];
	const rapidjson::Value& movingPlatformInfoArray = jsonDoc["movingPlatform"];
	const rapidjson::Value& liftInfoArray = jsonDoc["lift"];
	const rapidjson::Value& inSpacePortalInfoArray = jsonDoc["inSpacePortal"];
	const rapidjson::Value& outSpacePortalInfoArray = jsonDoc["outSpacePortal"];
	const rapidjson::Value& pushableBlockInfoArray = jsonDoc["pushableBlock"];
	
    //jsonDoc["pushButton"] will find the json value inside
    //jsonDoc which in the current case represents the root json object
    //of our json file LevelConfig.json.
	
    //Let us create an object of LevelDef to store all
    //the data that we extract

    LevelDef* levelDefObject = new LevelDef();
    
    //pushButtonInfoArray represents the pushButton array of our json file
    //pushButtonInfoArray.Size() will give us the length of that array.
    //we can access an object at index i of this array using pushButtonInfoArray[i]
    //(just like we use a regular c++ array). The only difference is that
    //in order to represent an index of a json-array RapidJSON library
    //provides us a special type called SizeType. So when we write
    //pushButtonInfoArray[i], i here should be of SizeType instead of int (as we have
    //in a regular array).


	//floor and floorsections
	for (rapidjson::SizeType i = 0; i < floorSectionInfoArray.Size(); ++i)
	{
		const rapidjson::Value& floorSectionInfo = floorSectionInfoArray[i];
		const int id = floorSectionInfo["sectionID"].GetInt();
		const rapidjson::Value& floorPointInfoArray = floorSectionInfo["floorPoint"];
		std::vector<FloorPoints> floorPointsObject;

		for (rapidjson::SizeType j = 0; j < floorPointInfoArray.Size(); ++j)
		{
			const rapidjson::Value& singlePointInfo = floorPointInfoArray[j];
			const float x = (float)(singlePointInfo["x"].GetDouble());
			const float y = (float)(singlePointInfo["y"].GetDouble());
			FloorPoints singlePoint;
			singlePoint.x = x;
			singlePoint.y = y;
			floorPointsObject.push_back(singlePoint);
		}

		FloorSectionDef floorSectionDefObject;
		floorSectionDefObject.sectionID = id;
		floorSectionDefObject.floorPoints = floorPointsObject;
		levelDefObject->floorSections.push_back(floorSectionDefObject);
	}

	//pushButton
    for (rapidjson::SizeType i = 0; i < pushButtonInfoArray.Size(); ++i)
    {
        //Again, inside pushButtonInfoArray, we have several json objects
        //Each json object of this array is represented by RapidJSON's Value class
        //We will now, iterate over each PushButton Information and store it
        //into the format we require - ie. objects of PushButtonDef struct
        const rapidjson::Value& pushButtonInfo = pushButtonInfoArray[i];
        
        //In order to get a sub-object's value, RapidJSON provides
        //Methods in Value class with names like GetInt, GetString, GetDouble etc.
        //pushButtonInfo represents the i-th object of PushButton Array
        //we now, get the sub-object "pushButtonID" (in int form) from pushButtonInfo
        const int id = pushButtonInfo["pushButtonID"].GetInt();
		const int reactID = pushButtonInfo["pushButtonReactID"].GetInt();

        //Similarly, we will extract the pushButtonPosition and store
        //x and y of it
        const rapidjson::Value& position = pushButtonInfo["pushButtonPosition"];
        const float x = (float)(position["x"].GetDouble());
        const float y = (float)(position["y"].GetDouble());
        
        //And now we store
        //First, lets create a PushButtonDef object
        PushButtonDef pushButtonDefObject;
        pushButtonDefObject.id = id;
		pushButtonDefObject.reactID = reactID;
        pushButtonDefObject.x = x;
        pushButtonDefObject.y = y;
        
        //Now, we will push the newly created pushButtonDefObject into
        //pushButtons vector of level-def object
        //vector has a method called push_back. It appends an object
        //after the last object of vector.
        levelDefObject->pushButtons.push_back(pushButtonDefObject);
    }

	//stepButton
	for (rapidjson::SizeType i = 0; i < stepButtonInfoArray.Size(); i++)
	{
		const rapidjson::Value& stepButtonInfo = stepButtonInfoArray[i];

		const int id = stepButtonInfo["stepButtonID"].GetInt();
		const int reactID = stepButtonInfo["stepButtonReactID"].GetInt();

		const rapidjson::Value& position = stepButtonInfo["stepButtonPosition"];
		const float x = (float)(position["x"].GetDouble());
		const float y = (float)(position["y"].GetDouble());

		StepButtonDef stepButtonDefObject;
		stepButtonDefObject.id = id;
		stepButtonDefObject.reactID = reactID;
		stepButtonDefObject.x = x;
		stepButtonDefObject.y = y;

		levelDefObject->stepButtons.push_back(stepButtonDefObject);
	}

	//slidingDoor
	for (rapidjson::SizeType i = 0; i < slidingDoorInfoArray.Size(); ++i)
	{
		const rapidjson::Value& slidingDoorInfo = slidingDoorInfoArray[i];
		const int id = slidingDoorInfo["slidingDoorID"].GetInt();
		const int reactID = slidingDoorInfo["slidingDoorReactID"].GetInt();
		const rapidjson::Value& position = slidingDoorInfo["slidingDoorPosition"];
		const float x = (float)(position["x"].GetDouble());
		const float y = (float)(position["y"].GetDouble());

		SlidingDoorDef slidingDoorDefObject;
		slidingDoorDefObject.id = id;
		slidingDoorDefObject.reactID = reactID;
		slidingDoorDefObject.x = x;
		slidingDoorDefObject.y = y;

		levelDefObject->slidingDoors.push_back(slidingDoorDefObject);
	}

	//movingPlatform
	for (rapidjson::SizeType i = 0; i < movingPlatformInfoArray.Size(); ++i)
	{
		const rapidjson::Value& movingPlatformInfo = movingPlatformInfoArray[i];

		const int id = movingPlatformInfo["movingPlatformID"].GetInt();

		const Type type = static_cast<Type>(movingPlatformInfo["movingPlatformType"].GetInt());

		const rapidjson::Value& startPosition = movingPlatformInfo["movingPlatformStartPosition"];
		const float startX = (float)(startPosition["x"].GetDouble());
		const float startY = (float)(startPosition["y"].GetDouble());

		const rapidjson::Value& endPosition = movingPlatformInfo["movingPlatformEndPosition"];
		const float endX = (float)(endPosition["x"].GetDouble());
		const float endY = (float)(endPosition["y"].GetDouble());

		const float velocityValue = movingPlatformInfo["movingPlatformVelocityValue"].GetInt();

		MovingPlatformDef movingPlatformDefObject;

		movingPlatformDefObject.id = id;
		movingPlatformDefObject.startX = startX;
		movingPlatformDefObject.startY = startY;
		movingPlatformDefObject.endX = endX;
		movingPlatformDefObject.endY = endY;
		movingPlatformDefObject.type = type;
		movingPlatformDefObject.velocityValue = velocityValue;

		levelDefObject->movingPlatforms.push_back(movingPlatformDefObject);
	}
	
	//lift
	for (rapidjson::SizeType i = 0; i < liftInfoArray.Size(); ++i)
	{
		const rapidjson::Value& liftInfo = liftInfoArray[i];
		
		const int id = liftInfo["liftID"].GetInt();
		const int reactID = liftInfo["liftReactID"].GetInt();
		const Type type = static_cast<Type>(liftInfo["liftType"].GetInt());

		const rapidjson::Value& startPosition = liftInfo["liftStartPosition"];
		const float startX = (float)(startPosition["x"].GetDouble());
		const float startY = (float)(startPosition["y"].GetDouble());

		const rapidjson::Value& endPosition = liftInfo["liftEndPosition"];
		const float endX = (float)(endPosition["x"].GetDouble());
		const float endY = (float)(endPosition["y"].GetDouble());

		const float velocityValue = (float)(liftInfo["liftVelocityValue"].GetDouble());

		LiftDef liftDefObj;

		liftDefObj.id = id;
		liftDefObj.reactID = reactID;
		liftDefObj.startX = startX;
		liftDefObj.startY = startY;
		liftDefObj.endX = endX;
		liftDefObj.endY = endY;
		liftDefObj.type = type;
		liftDefObj.velocityValue = velocityValue;

		levelDefObject->lifts.push_back(liftDefObj);
	}

	//inSpacePortal
	for (rapidjson::SizeType i = 0; i < inSpacePortalInfoArray.Size(); i++)
	{
		const rapidjson::Value& inSpacePortalInfo = inSpacePortalInfoArray[i];

		const int id = inSpacePortalInfo["inSpacePortalID"].GetInt();
		const int reactId = inSpacePortalInfo["inSpacePortalReactID"].GetInt();

		const rapidjson::Value& inPosition = inSpacePortalInfo["inSpacePortalInPosition"];
		const float inX = (float)(inPosition["x"].GetDouble());
		const float inY = (float)(inPosition["y"].GetDouble());

		const rapidjson::Value& outPosition = inSpacePortalInfo["inSpacePortalOutPosition"];
		const float outX = (float)(outPosition["x"].GetDouble());
		const float outY = (float)(outPosition["y"].GetDouble());

		InSpacePortalDef inSpacePortalDefObj;

		inSpacePortalDefObj.id = id;
		inSpacePortalDefObj.reactID = reactId;
		inSpacePortalDefObj.inX = inX;
		inSpacePortalDefObj.inY = inY;
		inSpacePortalDefObj.outX = outX;
		inSpacePortalDefObj.outY = outY;

		levelDefObject->inSpacePortals.push_back(inSpacePortalDefObj);
	}
	
	//outSpacePortal
	for (rapidjson::SizeType i = 0; i < outSpacePortalInfoArray.Size(); i++)
	{
		const rapidjson::Value& outSpacePortalInfo = outSpacePortalInfoArray[i];

		const int id = outSpacePortalInfo["outSpacePortalID"].GetInt();
		const int reactId = outSpacePortalInfo["outSpacePortalReactID"].GetInt();

		const rapidjson::Value& inPosition = outSpacePortalInfo["outSpacePortalInPosition"];
		const float inX = (float)(inPosition["x"].GetDouble());
		const float inY = (float)(inPosition["y"].GetDouble());

		const rapidjson::Value& outPosition = outSpacePortalInfo["outSpacePortalOutPosition"];
		const float outX = (float)(outPosition["x"].GetDouble());
		const float outY = (float)(outPosition["y"].GetDouble());
	
		OutSpacePortalDef outSpacePortalDefObj;

		outSpacePortalDefObj.id = id;
		outSpacePortalDefObj.reactID = reactId;
		outSpacePortalDefObj.inX = inX;
		outSpacePortalDefObj.inY = inY;
		outSpacePortalDefObj.outX = outX;
		outSpacePortalDefObj.outY = outY;

		levelDefObject->outSpacePortals.push_back(outSpacePortalDefObj);
	}

	//pushableBlock
	for (rapidjson::SizeType i = 0; i < pushableBlockInfoArray.Size(); i++)
	{
		const rapidjson::Value& pushableBlockInfo = pushableBlockInfoArray[i];

		const int id = pushableBlockInfo["pushableBlockID"].GetInt();
		const float x = (float)(pushableBlockInfo["x"].GetDouble());
		const float y = (float)(pushableBlockInfo["y"].GetDouble());

		PushableBlockDef pushableBlockDefObj;

		pushableBlockDefObj.id = id;
		pushableBlockDefObj.x = x;
		pushableBlockDefObj.y = y;

		levelDefObject->pushableBlocks.push_back(pushableBlockDefObj);
	}

	//Character 
	const rapidjson::Value& characterInfo = jsonDoc["character"];
	const float characterX = (float)(characterInfo["x"].GetInt());
	const float characterY = (float)(characterInfo["y"].GetInt());
	CharacterDef characterDefObject;
	characterDefObject.x = characterX;
	characterDefObject.y = characterY;
	levelDefObject->character = characterDefObject;

	//TerminatingDoor
	const rapidjson::Value& terminatingDoorInfo = jsonDoc["terminatingDoor"];
	const float terminatingDoorX = (float)(terminatingDoorInfo["x"].GetDouble());
	const float terminatingDoorY = (float)(terminatingDoorInfo["y"].GetDouble());
	TerminatingDoorDef terminatingDoorDefObject;
	terminatingDoorDefObject.x = terminatingDoorX;
	terminatingDoorDefObject.y = terminatingDoorY;
	levelDefObject->terminatingDoor = terminatingDoorDefObject;

    //Returning the levelDefObject
    return levelDefObject;
}
