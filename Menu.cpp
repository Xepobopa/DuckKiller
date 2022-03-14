#include "Menu.h"
#include <iostream>
Menu::Menu(AssertManager& manager)
{
	this->previousFrameClick = false;
	this->menuStateIsOpen = true;

	this->menu = new sf::Sprite(*manager.getTextureMenuBackground());

	// set button to start game
	this->buttonPlay = new sf::Sprite(*manager.getTextureMenuButtons());
	this->buttonPlay->setTextureRect(sf::IntRect(0, 0, 222, 110));
	// set position at the center
	this->buttonPlay->setPosition(sf::Vector2f((1920 - 222 - 10) / 2, 700 - 110 - 50));

	// set button to quit the game
	this->buttonQuit = new sf::Sprite(*manager.getTextureMenuButtons());
 	this->buttonQuit->setTextureRect(sf::IntRect(0, 110, 222, 110));
	// set position at the center
	this->buttonQuit->setPosition(sf::Vector2f((1920 - 222 - 10) / 2, 700));

	// set button to save the game
	this->buttonSave = new sf::Sprite(*manager.getTextureMenuButtons());
	this->buttonSave->setTextureRect(sf::IntRect(0, 108 * 3, 222, 108));
	// set position at the center
	this->buttonSave->setPosition(sf::Vector2f((1920 - 222 - 10) / 2, 700 + 160));

	// play title screen / menu music
	manager.getTitleScreenMusic()->play();
	std::cout << "Menu\n";

	// set game name 
	this->gameName = new sf::Sprite(*manager.getTextureMenuGameName());
	// set position at the center
	this->gameName->setPosition(sf::Vector2f((1920 - 600) / 2, 200));
}

sf::Sprite* Menu::getMenuSprite()
{
	return this->menu;
}

sf::Sprite* Menu::getButtonQuitSprite()
{
	return this->buttonQuit;
}

sf::Sprite* Menu::getButtonPlaySprite()
{
	return this->buttonPlay;
}

sf::Sprite* Menu::getButtonSaveSprite()
{
	return buttonSave;
}

sf::Sprite* Menu::getGameName()
{
	return this->gameName;
}

void Menu::printAllSprites(sf::RenderWindow& win)
{
	win.draw(*this->menu);
	win.draw(*this->buttonPlay);
	win.draw(*this->buttonQuit);
	win.draw(*this->gameName);
	win.draw(*this->buttonSave);
}

bool Menu::checkButtonQuitClick()
{
	if (this->buttonQuit->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) { return true;   }
	return false;
}

bool Menu::checkButtonPlayClick(AssertManager& manager)
{
	if (this->buttonPlay->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition()))) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			this->previousFrameClick = true;
			this->getButtonPlaySprite()->setTexture(*manager.getTextureMenuButtons());
			this->getButtonPlaySprite()->setTextureRect(sf::IntRect(222, 0, 222, 110));
			return false;
		}
		else if (previousFrameClick) {
			manager.getSoundButtonClick()->play();
			this->menuStateIsOpen = false;
			this->previousFrameClick = false;
			manager.getTitleScreenMusic()->stop();
			manager.getBackgroundMusic()->play();
			return true;
		}
		return false;
	}
}

bool Menu::checkButtonSaveClick(AssertManager& manager, Game& game, Save& save)
{
	if (this->buttonSave->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition()))) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			this->previousFrameClick = true;
			this->buttonSave->setTexture(*manager.getTextureMenuButtons());
			this->buttonSave->setTextureRect(sf::IntRect(222, 108.5 * 3, 222, 108.5));
			return false;
		}
		else if (previousFrameClick) {
			// save coins
			save.addData(std::pair<std::string, int>("coins", game.coins));
			save.saveData();

			std::cout << "Save!\n";
			previousFrameClick = false;
			this->buttonSave->setTexture(*manager.getTextureMenuButtons());
			this->buttonSave->setTextureRect(sf::IntRect(0, 108 * 3, 222, 108));
			this->buttonSave->setPosition(sf::Vector2f((1920 - 222 - 10) / 2, 700 + 160));
			return true;
		}
		return false;
	}
}
