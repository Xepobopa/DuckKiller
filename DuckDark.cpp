#include "DuckDark.h"

DuckDark::DuckDark(AssertManager& manager) : Ducks(manager.getTextureDuckDark(), 450, 15)
{
	std::cout << "Duck dark\n";
}
