#pragma once
#include "Ducks.h"
class DuckBlue : public Ducks
{
	sf::Sprite* duck;
	float length;
	// use to set texture straight direction
	float index;
	// transient variables ( переходня переменные 8==D )
	float stepX;
	float stepY;
	int frameX;
	int frameY;
public:
	bool shootDown;
	DuckBlue(AssertManager& manager);
	void animation(AssertManager& manager, float frametime);
	// return true if the duck go outside the window
	bool duckAnimationDeath(AssertManager& manager, float frametime);
	bool duckShootDown(AssertManager& manager, bool shoot);
	bool moveTo(AssertManager& manager, sf::Vector2f to, float frametime);
	sf::Vector2f getRandomPosition(sf::Vector2f pos);
	sf::Sprite* getDuck();

	~DuckBlue();
};

