#include <iostream>
#include "AssertManager.h"
#include "Cursor.h"
#include "Game.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

int main()
{
	RenderWindow win(VideoMode(1920, 1080), "DuckKiller", Style::Fullscreen);
	win.setVerticalSyncEnabled(true);
	win.setMouseCursorVisible(false);


#pragma region Create all needed stuff
	// load all needed textures at once
	AssertManager am;

	// create cursor
	User_Cursor cursour(win, am);
	
	// create menu
	Menu* menu = new Menu(am);

	// create Game, contains background, coins, bullets and some other stuff
	Game* game = new Game(am);
#pragma endregion
	

	while (win.isOpen())
	{
		win.clear();
		Event event;
		while (win.pollEvent(event)) { if (event.type == Event::Closed) { win.close(); } }
#pragma region Menu Stuff
		if (menu->menuStateIsOpen) {
			// close window by pressing button
			if (menu->checkButtonQuitClick()) { win.close(); }
			// start game
			if (menu->checkButtonPlayClick(am)) { std::cout << "Play"; }

			menu->printAllSprites(win);
		}
#pragma endregion


#pragma region Draw Game
		if (!menu->menuStateIsOpen){ 
			win.draw(*game->getBackgroundSprite());
			win.draw(*game->getBulletCounter());
		}
		win.draw(*cursour.getGameCursor()); // draw at the end
		win.display();
#pragma endregion
	}
}