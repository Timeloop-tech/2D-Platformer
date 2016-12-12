#ifndef _RECORD_TIME_H_
#define _RECORD_TIME_H_

#include "cocos2d.h"
#include "CommandInfo.h"

USING_NS_CC;

class RecordTime
{
private:
	std::vector<CommandInfo*>			m_recordingInfo;
public:
	void addElement(CommandInfo* commandInfo);
};
#endif // !_RECORD_TIME_H_

