#include "Cursor.h"
#include <iostream>

User_Cursor::User_Cursor(sf::RenderWindow& win, AssertManager& manager)
{
	this->cursor_sprite = new sf::Sprite(*manager.getTextureAim());
	cursor_sprite->setOrigin(sf::Vector2f(cursor_sprite->getScale().x, cursor_sprite->getScale().y));
	sf::Mouse::setPosition(sf::Vector2i(1920 / 2, 1080 / 2), win);
	std::cout << "Cursor\n";
}

sf::Sprite* User_Cursor::getGameCursor()
{
	this->cursor_sprite->setPosition(sf::Vector2f(sf::Mouse::getPosition()));
	return this->cursor_sprite;
}
