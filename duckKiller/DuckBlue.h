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
	// change textures depending on the every frame move. You should just call this function 
	void animation(AssertManager& manager, float frametime);
	// return true if the duck go outside the window
	bool duckAnimationDeath(AssertManager& manager, float frametime);
	bool duckShootDown(AssertManager& manager, float frametime, bool shoot);
	// Move duck to the position "to". Return true if position was reached, else - false. 
	// You don't have to use this function, because function move() have all needed things
	bool moveTo(AssertManager& manager, sf::Vector2f to, float frametime);
	// Move duck to the random position, use moveTo();
	void move(AssertManager& manager, float frametime);
	sf::Sprite* getDuck();

	~DuckBlue();
};

