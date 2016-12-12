#include "LeftCommand.h"

void LeftCommand::execute(GameLayer* layer)
{
	layer->getCharacter()->moveLeft();
}