#pragma once
#include<SFML/Graphics.hpp>
#include "AssertManager.h"

class User_Cursor : public sf::Cursor
{
private:
	sf::Vector2i cur_pos;
	sf::Sprite* cursor_sprite;
public:
	User_Cursor(sf::RenderWindow& win, AssertManager& manager);
	
	sf::Sprite* getGameCursor();
};

