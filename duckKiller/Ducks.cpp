#include "Ducks.h"

Ducks::Ducks(int speed, int cost)
{
	this->speed = speed;
	this->cost = cost;
	this->cur_frametime = 0;
	this->new_pos = sf::Vector2f(0, 0);
	this->reachDestination = false;
}

void Ducks::setPosition(sf::Vector2f pos)
{
	this->pos = pos;
}
