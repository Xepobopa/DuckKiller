#include <iostream>
#include "AssertManager.h"
#include "DuckBlue.h"
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

	// create Game, contains background, coins, bullets and some other stuff
	Game* game = new Game(am);

	// create blue duck
	DuckBlue* duckBlue = new DuckBlue(am);
	Vector2f* pos;
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
			if (menu->checkButtonPlayClick(am)) { std::cout << "Play\n"; }

			menu->printAllSprites(win);
		}
#pragma endregion


#pragma region Draw Game
		if (!menu->menuStateIsOpen){ // if button play was clicked

			if (!duckBlue->shootDown) { // if duck not shoot down
				duckBlue->move(am, clock.getElapsedTime().asSeconds());
				duckBlue->animation(am, clock.getElapsedTime().asSeconds()); // show animation
			}  
			// if duck shoot down
			else { if (duckBlue->duckAnimationDeath(am, clock.getElapsedTime().asSeconds())) { win.close(); }; }
			clock.restart();  // restart clock for other funcs

			// if you shoot down the duck
			duckBlue->duckShootDown(am, clock.getElapsedTime().asSeconds(), game->checkMouseClickToShoot(am));

			// draw bg
			win.draw(*game->getBackgroundSprite());
			// draw bullet counter
			game->drawBulletCounters(win);
			// draw duck
			win.draw(*duckBlue->getDuck());
		}
		win.display();
#pragma endregion
	}
}