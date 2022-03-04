#include "Game.h"
#include <assert.h>
#include <iostream>
Game::Game(AssertManager& manager)
{
	// set background
	this->background = new sf::Sprite; background->setTexture(*manager.getTextureBackground());
	
	// set bullet counter and position (corner)
	this->bulletCounterFull = new sf::Sprite; bulletCounterFull->setTexture(*manager.getTextureBulletCounterFull());
	this->bulletCounterFull->setPosition(sf::Vector2f(100, 1080 - 100 - 50));
	this->bulletCounterEmpty = new sf::Sprite; bulletCounterEmpty->setTexture(*manager.getTextureBulletCounterEmpty()); this->bulletCounterEmpty->setPosition(sf::Vector2f(100, 1080 - 100 - 50));
	this->bulletCounterOneBullet = new sf::Sprite; bulletCounterOneBullet->setTexture(*manager.getTextureBulletCounterOneBullet()); this->bulletCounterOneBullet->setPosition(sf::Vector2f(100, 1080 - 100 - 50));
	this->bulletCounterTwoBullets = new sf::Sprite; bulletCounterTwoBullets->setTexture(*manager.getTextureBulletCounterTwoBullet()); this->bulletCounterTwoBullets->setPosition(sf::Vector2f(100, 1080 - 100 - 50));
	
	// you have 3 bullets
	bullet_counter = 3;

	setBullets(bullet_counter);  // set bullet counter

	// set previous frame click
	this->previous_frame_click = false;

	std::cout << "Game\n";
}

sf::Sprite* Game::getBackgroundSprite()
{
	return this->background;
}

void Game::setBullets(int bullets)
{
	switch (bullets)
	{
	case 0:
		this->bulletCounterEmpty->setColor(sf::Color(255, 255, 255, 255)); // set visible
		this->bulletCounterOneBullet->setColor(sf::Color(255, 255, 255, 0)); // set invisible
		this->bulletCounterTwoBullets->setColor(sf::Color(255, 255, 255, 0)); // set invisible
		this->bulletCounterFull->setColor(sf::Color(255, 255, 255, 0)); // set invisible
		break;
	case 1:
		this->bulletCounterEmpty->setColor(sf::Color(255, 255, 255, 0)); // set invisible
		this->bulletCounterOneBullet->setColor(sf::Color(255, 255, 255, 255)); // set visible
		this->bulletCounterTwoBullets->setColor(sf::Color(255, 255, 255, 0)); // set invisible
		this->bulletCounterFull->setColor(sf::Color(255, 255, 255, 0)); // set invisible
		break;
	case 2:
		this->bulletCounterEmpty->setColor(sf::Color(255, 255, 255, 0)); // set invisible
		this->bulletCounterOneBullet->setColor(sf::Color(255, 255, 255, 0)); // set invisible
		this->bulletCounterTwoBullets->setColor(sf::Color(255, 255, 255, 255)); // set visible
		this->bulletCounterFull->setColor(sf::Color(255, 255, 255, 0)); // set invisible
		break;
	case 3:
		this->bulletCounterEmpty->setColor(sf::Color(255, 255, 255, 0)); // set invisible
		this->bulletCounterOneBullet->setColor(sf::Color(255, 255, 255, 0)); // set invisible
		this->bulletCounterTwoBullets->setColor(sf::Color(255, 255, 255, 0)); // set invisible
		this->bulletCounterFull->setColor(sf::Color(255, 255, 255, 255)); // set visible
		break;
	default:
		assert("You can set only digits from 0 to 3\n");
		break;
	}
}

void Game::drawBulletCounters(sf::RenderWindow& win)
{
	win.draw(*this->bulletCounterEmpty);
	win.draw(*this->bulletCounterFull);
	win.draw(*this->bulletCounterOneBullet);
	win.draw(*this->bulletCounterTwoBullets);
}

bool Game::checkMouseClickToShoot(AssertManager& manager)
{
	if (bullet_counter) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { this->previous_frame_click = true; return false; }
		else if (previous_frame_click) {
			manager.getSoundShoot()->play();
			this->setBullets(bullet_counter -= 1);
			this->previous_frame_click = false;
			return true;
		}
	}
	return false;
}
