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

	// load bullet texture
	this->textureBullet = new sf::Texture; textureBullet->loadFromFile("img//bullet.png");

	// load background texture
	this->textureBackground = new sf::Texture; textureBackground->loadFromFile("img//bg.png");

	// load menu buttons
	this->textureMenuButtons = new sf::Texture; textureMenuButtons->loadFromFile("img//menuButtons.png");
	
	// load menu background
	this->textureMenuBackground = new sf::Texture; textureMenuBackground->loadFromFile("img//menubg.png");

	// load aim texture
	this->textureCursorAim = new sf::Texture; textureCursorAim->loadFromFile("img//aim.png");

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
	this->textureBulletCounter = new sf::Texture; textureBulletCounter->loadFromFile("img//bulletCounter.png");
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

sf::Texture* AssertManager::getTextureBullet()
{
	return this->textureBullet;
}

sf::Texture* AssertManager::getTextureMenuButtons()
{
	return this->textureMenuButtons;
}

sf::Texture* AssertManager::getTextureAim()
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

sf::Texture* AssertManager::getTextureBulletCounter()
{
	return this->textureBulletCounter;
}

sf::Sound* AssertManager::getSoundButtonClick()
{
	return this->soundButtonClick;
}

sf::Music* AssertManager::getTitleScreenMusic()
{
	return this->titleScreenMusic;
}

