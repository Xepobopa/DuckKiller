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
 	this->buttonQuit->setTextureRect(sf::IntRect(0, 111, 222, 111));
	// set position at the center
	this->buttonQuit->setPosition(sf::Vector2f((1920 - 222 - 10) / 2, 700));

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
}

bool Menu::checkButtonQuitClick()
{
	if (this->buttonQuit->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) { return true;   }
	return false;
}

bool Menu::checkButtonPlayClick(AssertManager& manager)
{
	if (this->buttonPlay->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) { 
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
		return true; }
	return false;
}
