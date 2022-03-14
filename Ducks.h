#pragma once
#include<SFML//Graphics.hpp>
#include "AssertManager.h"
#include "Game.h"
#include<iostream>
#include <cmath>
class Ducks
{
protected:
	int cost;
	int speed;
	float cur_frametime;
	sf::Vector2f pos;
	bool reachDestination;
	sf::Vector2f new_pos;

	float length;
	// use to set texture straight direction
	float index;
	// transient variables ( переходня переменные 8==D )
	float stepX;
	float stepY;
	int frameX;
	int frameY;
	sf::Texture* texture;

	sf::Sprite* duck;
public:
	bool shootDown;
	Ducks(sf::Texture* duckSprite, int speed, int cost);
	void setPosition(sf::Vector2f pos);

	// change textures depending on the every frame move. You should just call this function 
	void animation(AssertManager& manager, float frametime);
	// return true if the duck go outside the window
	bool duckAnimationDeath(AssertManager& manager, float frametime);
	bool duckShootDown(AssertManager& manager, Game& game, float frametime, bool shoot);
	// Move duck to the position "to". Return true if position was reached, else - false. 
	// You don't have to use this function, because function move() have all needed things
	bool moveTo(AssertManager& manager, sf::Vector2f to, float frametime);
	// Move duck to the random position, use moveTo();
	void move(AssertManager& manager, float frametime);

	// return duck sprite to display on the screen
	sf::Sprite* getDuck();
};