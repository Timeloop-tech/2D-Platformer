#include "RecordTime.h"

void RecordTime::addElement(CommandInfo* commandInfo)
{
	m_recordingInfo.push_back(commandInfo);
}