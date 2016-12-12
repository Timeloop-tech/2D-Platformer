#include "Utils.h"

Vec2 Utils::meterPositionToPX(b2Vec2 meterPos)
{
	Vec2 convertedValue(meterPos.x * PTM_RATIO, meterPos.y * PTM_RATIO);
	return convertedValue;
}

b2Vec2 Utils::pixelPositionToMeter(Vec2 pixelPos)
{
	b2Vec2 convertedValue(pixelPos.x / PTM_RATIO, pixelPos.y / PTM_RATIO);
	return convertedValue;
}