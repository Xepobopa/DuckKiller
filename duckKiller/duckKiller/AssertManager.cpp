#include "AssertManager.h"
#include<assert.h>
#include<iostream>

AssertManager::AssertManager()
{

	// load ducks' textures 
	this->textureDuckBlue = new sf::Texture; textureDuckBlue->loadFromFile("img//ducks//blue duck.png");
	this->textureDuckDark = new sf::Texture;  textureDuckDark->loadFromFile("img//ducks//dark duck.png");
	this->textureDuckRed = new sf::Texture; textureDuckRed->loadFromFile("img//ducks//red duck.png");

	// load dog texture
	this->textureDog = new sf::Texture; textureDog->loadFromFile("img//dog laugh.png");

	// load background texture
	this->textureBackground = new sf::Texture; textureBackground->loadFromFile("img//bg.png");

	// load menu buttons
	this->textureMenuButtons = new sf::Texture; textureMenuButtons->loadFromFile("img//menuButtons.png");
	
	// load menu background
	this->textureMenuBackground = new sf::Texture; textureMenuBackground->loadFromFile("img//menubg.png");

	// load aim texture
	this->textureCursorAim = new sf::Image; textureCursorAim->loadFromFile("img//aim.png");

	// load button click sound
	this->buffer = new sf::SoundBuffer; buffer->loadFromFile("sound//buttonClick.wav");

	// set button click sound 
	this->soundButtonClick = new sf::Sound;
	this->soundButtonClick->setBuffer(*buffer);
	this->soundButtonClick->setVolume(70.0f);

	// set title screen / menu music
	this->titleScreenMusic = new sf::Music; titleScreenMusic->openFromFile("sound//title screen.wav");

	// load texture game name
	this->textureMenuGameName = new sf::Texture; textureMenuGameName->loadFromFile("img//menuGameName.png");

	// load texture bullet counter
	this->textureBulletCounterFull = new sf::Texture; textureBulletCounterFull->loadFromFile("img//bulletCounterFull.png");
	this->textureBulletCounterOneBullet = new sf::Texture; textureBulletCounterOneBullet->loadFromFile("img//bulletCounterOneBullet.png");
	this->textureBulletCounterTwoBullets = new sf::Texture; textureBulletCounterTwoBullets->loadFromFile("img//bulletCounterTwoBullets.png");
	this->textureBulletCounterEmpty = new sf::Texture; textureBulletCounterEmpty->loadFromFile("img//bulletCounterEmpty.png");
	
	// set background music
	this->backgroundMusic = new sf::Music; backgroundMusic->openFromFile("sound//audioBackground.ogg");

	// set sound shoot
	this->soundShoot = new sf::Sound; soundShoot->setVolume(200.0f);

	std::cout << "Assert Manager\n";
}

sf::Texture* AssertManager::getTextureDuckBlue()
{
	return this->textureDuckBlue;
}

sf::Texture* AssertManager::getTextureDuckRed()
{
	return this->textureDuckRed;
}

sf::Texture* AssertManager::getTextureDuckDark()
{
	return this->textureDuckDark;
}

sf::Texture* AssertManager::getTextureDog()
{
	return this->textureDog;
}

sf::Texture* AssertManager::getTextureMenuButtons()
{
	return this->textureMenuButtons;
}

sf::Image* AssertManager::getTextureAim()
{
	return this->textureCursorAim;
}

sf::Texture* AssertManager::getTextureBackground()
{
	return this->textureBackground;
}

sf::Texture* AssertManager::getTextureMenuBackground()
{
	return this->textureMenuBackground;
}

sf::Texture* AssertManager::getTextureMenuGameName()
{
	return this->textureMenuGameName;
}

sf::Texture* AssertManager::getTextureBulletCounterFull()
{
	return this->textureBulletCounterFull;
}

sf::Texture* AssertManager::getTextureBulletCounterOneBullet()
{
	return this->textureBulletCounterOneBullet;
}

sf::Texture* AssertManager::getTextureBulletCounterTwoBullet()
{
	return this->textureBulletCounterTwoBullets;
}

sf::Texture* AssertManager::getTextureBulletCounterEmpty()
{
	return this->textureBulletCounterEmpty;
}

sf::Sound* AssertManager::getSoundButtonClick()
{
	return this->soundButtonClick;
}

sf::Music* AssertManager::getTitleScreenMusic()
{
	return this->titleScreenMusic;
}

sf::Music* AssertManager::getBackgroundMusic()
{
	return this->backgroundMusic;
}

sf::Sound* AssertManager::getSoundShoot(std::string path)
{
	this->buffer->loadFromFile(path);
	this->soundShoot->setBuffer(*buffer);
	return soundShoot;
}

