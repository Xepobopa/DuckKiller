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

	bool getDistanceTrue = true;
	Vector2f positionTo = Vector2f(0, 0);
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



		std::cout << positionTo.x << "    " << positionTo.y << std::endl;
#pragma region Draw Game
		if (!menu->menuStateIsOpen){ // if button play was clicked
			// move to point and set needed texture
			if (!duckBlue->shootDown){
				if (getDistanceTrue) {
					positionTo = duckBlue->getRandomPosition(positionTo);
					getDistanceTrue = duckBlue->moveTo(am, positionTo, clock.getElapsedTime().asSeconds());
				}
				else { getDistanceTrue = duckBlue->moveTo(am, positionTo, clock.getElapsedTime().asSeconds()); }
					
				duckBlue->animation(am, clock.getElapsedTime().asSeconds()); // show animation
			}
			else {
				duckBlue->duckAnimationDeath(am, clock.getElapsedTime().asSeconds());
			}
			clock.restart();
			// if you shoot down the duck
			duckBlue->duckShootDown(am, game->checkMouseClickToShoot(am));

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