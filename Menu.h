#pragma once
#include "AssertManager.h"
#include "Save.h"
#include "Game.h"

class Menu
{
private:
	sf::Sprite* menu;
	sf::Sprite* gameName;
	sf::Sprite* buttonQuit;
	sf::Sprite* buttonPlay;
	sf::Sprite* buttonSave;
 	bool previousFrameClick;
public:
	bool menuStateIsOpen;
	Menu(AssertManager& manager);
	sf::Sprite* getMenuSprite();
	sf::Sprite* getButtonQuitSprite();
	sf::Sprite* getButtonPlaySprite();
	sf::Sprite* getButtonSaveSprite();
	sf::Sprite* getGameName();
	void printAllSprites(sf::RenderWindow& win);
	bool checkButtonQuitClick();
	bool checkButtonPlayClick(AssertManager& manager);
	bool checkButtonSaveClick(AssertManager& manager, Game& game, Save& save);
};

