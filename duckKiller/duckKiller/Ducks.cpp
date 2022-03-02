#include "Ducks.h"

Ducks::Ducks(int speed, int cost)
{
	this->speed = speed;
	this->cost = cost;
	this->cur_frametime = 0;
}

void Ducks::setPosition(sf::Vector2f pos)
{
	this->pos = pos;
}
