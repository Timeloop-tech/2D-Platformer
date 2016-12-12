//
//  LevelDef.h
//  
//
//  Created by Hema Dubal on 07/02/16.
//
//

#ifndef LevelDef_h
#define LevelDef_h

#include <vector>

struct PushButtonDef
{
    int id, reactID;
    float x, y;
};

struct StepButtonDef
{
	int id, reactID;
	float x, y;
};

struct CharacterDef
{
	float x, y;
};

struct FloorPoints
{
	float x, y;
};

struct FloorSectionDef
{
	int sectionID;
	std::vector<FloorPoints> floorPoints;
};

struct SlidingDoorDef
{
	int id;
	int reactID;
	float x, y;
};

enum class Type
{
	horizontal,
	vertical
};

struct MovingPlatformDef
{
	int id;
	float startX, endX, startY, endY;
	float velocityValue;
	Type type;
	
};

struct LiftDef {
	int id, reactID;
	float startX, startY, endX, endY;
	float velocityValue;
	Type type;
};

struct InSpacePortalDef {
	int id, reactID;
	float inX, inY, outX, outY;
};

struct OutSpacePortalDef {
	int id, reactID;
	float inX, inY, outX, outY;
};

struct PushableBlockDef {
	int id;
	float x, y;
};

struct TerminatingDoorDef {
	float x, y;
};

struct LevelDef
{
    std::vector<PushButtonDef> pushButtons;
	std::vector<StepButtonDef> stepButtons;
	CharacterDef character;
	std::vector<FloorSectionDef> floorSections;
	std::vector<SlidingDoorDef> slidingDoors;
	std::vector<MovingPlatformDef> movingPlatforms;
	std::vector<LiftDef> lifts;
	std::vector<InSpacePortalDef> inSpacePortals;
	std::vector<OutSpacePortalDef> outSpacePortals;
	std::vector<PushableBlockDef> pushableBlocks;
	TerminatingDoorDef terminatingDoor;
    //similarly represent other objects of
    //level in their respective "defs"
};

#endif /* LevelDef_h */
