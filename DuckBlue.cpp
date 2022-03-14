#include "DuckBlue.h"
#include "Game.h"

DuckBlue::DuckBlue(AssertManager& manager) : Ducks(manager.getTextureDuckBlue(), 300, 5)
{
	std::cout << "Duck Blue" << std::endl;
}

