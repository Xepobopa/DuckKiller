#include <iostream>
#include "Save.h" // to save game data
#include "AssertManager.h"
#include "DuckBlue.h"
#include "DuckDark.h"
#include "DuckRed.h"
#include "Cursor.h"
#include "Game.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<cmath>

using namespace sf;

int main()
{
	// random
	srand(time(0));
	RenderWindow win(VideoMode(1920, 1080), "DuckKiller", Style::Fullscreen);
	win.setVerticalSyncEnabled(true);
	//win.setMouseCursorVisible(false);


#pragma region Create all needed stuff
	// load all needed textures at once
	AssertManager am;

	// create clock
	Clock clock;
	Time time;

	Cursor cursor;
	// create cursor
	User_Cursor cursour(win, am, cursor);
	
	// create menu
	Menu* menu = new Menu(am);

	// to make saves
	Save* save = new Save();

	// create Game, contains background, coins, bullets and some other stuff
	Game* game = new Game(am, *save);

	// create blue duck
	//Ducks* duck = new DuckDark(am);
	std::vector<Ducks*> ducks;
	ducks.push_back(new DuckDark(am));
	ducks.push_back(new DuckBlue(am));
	ducks.push_back(new DuckRed(am));
#pragma endregion
	
	for (auto duck : ducks) { std::cout << duck->shootDown << std::endl; }

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
			if (menu->checkButtonPlayClick(am)) { std::cout << "Play\n"; }

			menu->checkButtonSaveClick(am, *game, *save);

			menu->printAllSprites(win);
		}
#pragma endregion

#pragma region Draw Game
		if (Keyboard::isKeyPressed(Keyboard::Escape)) { menu->menuStateIsOpen = true; am.getBackgroundMusic()->stop(); am.getTitleScreenMusic()->play(); }

		if (!menu->menuStateIsOpen){ // if button play was clicked
			for (auto duck : ducks) 
			{
				if (!duck->shootDown) { // if duck not shoot down
					duck->move(am, clock.getElapsedTime().asSeconds());
					duck->animation(am, clock.getElapsedTime().asSeconds()); // show animation
				}  
				// if duck shoot down
				else { if (duck->duckAnimationDeath(am, clock.getElapsedTime().asSeconds())) { ducks.erase(std::find(ducks.begin(), ducks.end(), duck)); }; }

				// if you shoot down the duck
				duck->duckShootDown(am, *game, clock.getElapsedTime().asSeconds(), game->checkMouseClickToShoot(am));
			}
			clock.restart();  // restart clock for other funcs

			// draw bg
			win.draw(*game->getBackgroundSprite());
			// draw bullet counter
			game->drawBulletCounters(win);
			// draw amount of coins
			win.draw(*game->getCoinText());

			// draw ducks
			for (auto duck : ducks) { win.draw(*duck->getDuck()); }
			//win.draw(*duck->getDuck());
		}
		win.display();
#pragma endregion
	}
}