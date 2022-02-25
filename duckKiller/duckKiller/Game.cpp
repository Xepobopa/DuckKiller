#include "Game.h"
#include <iostream>
Game::Game(AssertManager& manager)
{
	// set background
	this->background = new sf::Sprite; background->setTexture(*manager.getTextureBackground());
	
	// set bullet counter and position (corner)
	this->bulletCounter = new sf::Sprite; bulletCounter->setTexture(*manager.getTextureBulletCounter());
	this->bulletCounter->setPosition(sf::Vector2f(100, 1080 - 100 - 50));

	std::cout << "Game";
}

sf::Sprite* Game::getBackgroundSprite()
{
	return this->background;
}

sf::Sprite* Game::getBulletCounter()
{
	return this->bulletCounter;
}
