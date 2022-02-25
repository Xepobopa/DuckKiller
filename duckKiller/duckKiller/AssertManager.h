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
	sf::Texture* textureBullet;
	sf::Texture* textureMenuButtons;
	sf::Texture* textureBackground;
	sf::Texture* textureCursorAim;
	sf::Texture* textureMenuBackground;
	sf::Texture* textureMenuGameName;
	sf::Texture* textureBulletCounter;
	sf::SoundBuffer* buffer;
	sf::Sound* soundButtonClick;
	sf::Music* titleScreenMusic;
public:
	AssertManager();

	// get all loaded textures
	sf::Texture* getTextureDuckBlue();
	sf::Texture* getTextureDuckRed();
	sf::Texture* getTextureDuckDark();
	sf::Texture* getTextureDog();
	sf::Texture* getTextureBullet();
	sf::Texture* getTextureMenuButtons();
	sf::Texture* getTextureAim();
	sf::Texture* getTextureBackground();
	sf::Texture* getTextureMenuBackground();
	sf::Texture* getTextureMenuGameName();
	sf::Texture* getTextureBulletCounter();
	sf::Sound* getSoundButtonClick();
	sf::Music* getTitleScreenMusic();
};

