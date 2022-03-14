#pragma once
#include "AssertManager.h"
#include "Save.h"
#include <SFML/Graphics.hpp>
//create Game, contains background, coins, bullets and some other stuff
class Game
{
private:
	sf::Sprite* background;
	sf::Sprite* bulletCounterFull;
	sf::Sprite* bulletCounterEmpty;
	sf::Sprite* bulletCounterOneBullet;
	sf::Sprite* bulletCounterTwoBullets;

	bool previous_frame_click;
	int bullet_counter;
protected:

	sf::Text* coinText;
public:
	int coins;
	Game(AssertManager& manager, Save& save);
	Game()
	{}
	
	sf::Sprite* getBackgroundSprite();
	// get number from 0 to 3. And draw texture with needed amount of bullets
	void setBullets(int bullets);
	void drawBulletCounters(sf::RenderWindow& win);
	bool checkMouseClickToShoot(AssertManager& manager);

	void setCoin(int coins);
	void addCoins(int coins);
	sf::Text* getCoinText();
};

