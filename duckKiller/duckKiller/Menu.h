#pragma once
#include "AssertManager.h"

class Menu
{
private:
	sf::Sprite* menu;
	sf::Sprite* gameName;
	sf::Sprite* buttonQuit;
	sf::Sprite* buttonPlay;
	bool previousFrameClick;
public:
	bool menuStateIsOpen;
	Menu(AssertManager& manager);
	sf::Sprite* getMenuSprite();
	sf::Sprite* getButtonQuitSprite();
	sf::Sprite* getButtonPlaySprite();
	sf::Sprite* getGameName();
	void printAllSprites(sf::RenderWindow& win);
	bool checkButtonQuitClick();
	bool checkButtonPlayClick(AssertManager& manager);
};

