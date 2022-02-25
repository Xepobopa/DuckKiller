#pragma once
#include "AssertManager.h"
#include <SFML/Graphics.hpp>
//create Game, contains background, coins, bullets and some other stuff
class Game
{
private:
	sf::Sprite* background;
	sf::Sprite* bulletCounter;
public:
	Game(AssertManager& manager);
	
	sf::Sprite* getBackgroundSprite();
	sf::Sprite* getBulletCounter();
};

