#include "Cursor.h"
#include <iostream>

User_Cursor::User_Cursor(sf::RenderWindow& win, AssertManager& manager, sf::Cursor& cursor)
{
	if (!cursor.loadFromPixels(manager.getTextureAim()->getPixelsPtr(), manager.getTextureAim()->getSize(), { 0, 0 })) { ; }
	win.setMouseCursor(cursor);
	std::cout << "Cursor\n";
}
