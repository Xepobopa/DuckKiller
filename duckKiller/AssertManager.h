#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class AssertManager
{
private:
	sf::Texture* textureDuckBlue;
	sf::Texture* textureDuckRed;
	sf::Texture* textureDuckDark;
	sf::Texture* textureDog;
	sf::Texture* textureMenuButtons;
	sf::Texture* textureBackground;
	sf::Image* textureCursorAim;
	sf::Texture* textureMenuBackground;
	sf::Texture* textureMenuGameName;
	sf::Texture* textureBulletCounterFull;
	sf::Texture* textureBulletCounterOneBullet;
	sf::Texture* textureBulletCounterTwoBullets;
	sf::Texture* textureBulletCounterEmpty;
	sf::SoundBuffer* buffer;
	sf::SoundBuffer* bufferDeadDuck;
	sf::Sound* soundButtonClick;
	sf::Sound* soundShoot;
	sf::Sound* soundQuack;
	sf::Sound* soundDeadDuckFalls;
	sf::Sound* soundDeadDuckLands;
	sf::Sound* soundDuckFlapping;
	sf::Music* titleScreenMusic;
	sf::Music* backgroundMusic;
public:
	AssertManager();

	// get all loaded textures
	sf::Texture* getTextureDuckBlue();
	sf::Texture* getTextureDuckRed();
	sf::Texture* getTextureDuckDark();
	sf::Texture* getTextureDog();
	sf::Texture* getTextureMenuButtons();
	sf::Image* getTextureAim();
	sf::Texture* getTextureBackground();
	sf::Texture* getTextureMenuBackground();
	sf::Texture* getTextureMenuGameName();
	sf::Texture* getTextureBulletCounterFull();
	sf::Texture* getTextureBulletCounterOneBullet();
	sf::Texture* getTextureBulletCounterTwoBullet();
	sf::Texture* getTextureBulletCounterEmpty();
	sf::Sound* getSoundButtonClick();
	sf::Sound* getSoundQuack();
	sf::Sound* getSoundShoot();
	sf::Sound* getSoundDeadDuckFalls();
	sf::Sound* getSoundDeadDuckLands();
	sf::Sound* getSoundDuckFlapping();
	sf::Music* getTitleScreenMusic();
	sf::Music* getBackgroundMusic();
};

