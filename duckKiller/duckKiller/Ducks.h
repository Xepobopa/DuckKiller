#pragma once
#include<SFML//Graphics.hpp>
#include<iostream>
#include "AssertManager.h"
#include <cmath>
class Ducks
{
protected:
	int cost;
	int speed;
	float cur_frametime;
	sf::Vector2f pos;
public:
	Ducks(int speed, int cost);
	void setPosition(sf::Vector2f pos);
};