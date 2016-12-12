#include "RightCommand.h"

void RightCommand::execute(GameLayer* layer)
{
	layer->getCharacter()->moveRight();
}