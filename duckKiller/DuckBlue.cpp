#include "DuckBlue.h"

DuckBlue::DuckBlue(AssertManager& manager) : Ducks(350, 5)
{
	// set duck sprite
	this->duck = new sf::Sprite(*manager.getTextureDuckBlue());
	this->duck->setTextureRect(sf::IntRect(0, 0, 75, 76.4));
	// set duck appearance ( at the random pos at the bottom ) 
	Ducks::setPosition(sf::Vector2f(1920 / 2 , 1200));

	this->shootDown = false;
	this->frameX = 1;
	this->frameY = 1;
	this->index = 1;
	this->stepX = -1;
	this->stepY = 0;
	this->length = 0;
	std::cout << "Duck Blue" << std::endl;
}

void DuckBlue::animation(AssertManager& manager, float frametime)
{
	//std::cout << frametime << std::endl;
	if (rand() % 100 == 1) { manager.getSoundQuack()->play(); }
	if (frametime + 0.2 <= cur_frametime)
	{
		cur_frametime = 0;
		this->duck->setTexture(*manager.getTextureDuckBlue());
		this->duck->setTextureRect(sf::IntRect((frameX - 1) * 75.3, (frameY - 1) * 76.4, 75.3, 76.4));
		
		// flapping
		if (frameX != 2) { manager.getSoundDuckFlapping()->play(); }

		// move frames
		if (frameX == 3) { index = -1; }
		else if (frameX == 1) { index = 1; }
		frameX += (float)index;
		
		//std::cout << frameX << " - frameX \n";
	}
	else { cur_frametime += frametime; }
}

bool DuckBlue::duckAnimationDeath(AssertManager& manager, float frametime)
{
	// increase speed
	this->speed += 10;

	if (duck->getPosition().y >= 1050) { manager.getSoundDeadDuckLands()->play(); }

	// if duck out of the window - return true
	if (duck->getPosition().y >= 1080) { return true; }

	// move to the bottom
	moveTo(manager, sf::Vector2f(this->duck->getPosition().x, 1090), frametime);

	// set texture of dead duck
	frameY = 5;
	duck->setScale(1, 1);
	animation(manager, frametime);

	return false;
}

bool DuckBlue::duckShootDown(AssertManager& manager, float frametime, bool shoot)
{
	// mouse coords touch duck and a shot was fired
	if (shoot == true && this->duck->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition()))) {
		frameY = 4;
		animation(manager, frametime);
		this->shootDown = true;

		// play sound dead duck falls
		manager.getSoundDeadDuckFalls()->play();

		return true;
	}
	return false;
}

bool DuckBlue::moveTo(AssertManager& manager, sf::Vector2f to, float frametime)
{  
	//std::cout << index << "\n";
	this->length = sqrt((to.x - this->pos.x) * (to.x - this->pos.x) + (to.y - pos.y) * (to.y - pos.y));
	//std::cout << length << std::endl;

	if (length > 2) {
		stepX = speed * frametime * (to.x - pos.x) / length;
		stepY = speed * frametime * (to.y - pos.y) / length;
		this->pos.x += stepX;
		this->pos.y += stepY;

		//std::cout << "X pos: " << stepX << "   Y pos: " << stepY << std::endl;
		// check direction
		// check X
		if (stepX > -0.6 && stepX < 0.6) { stepX = 0; }
		else if (stepX > 0) { stepX = 1; }
		else if (stepX < 0) { stepX = -1; }
		//check Y
		if (stepY > -0.6 && stepY < 0.6) { stepY = 0; }
		else if (stepY > 0) { stepY = -1; }
		else if (stepY < 0) { stepY = 1; }

		// set texture
		if (stepX == 0 && stepY == 1) { frameY = 3; this->duck->setScale(1, 1); }
		if (stepX == 1 && stepY == 1) { frameY = 2; this->duck->setScale(1, 1); }
		if (stepX == 1 && stepY == 0) { frameY = 1; this->duck->setScale(1, 1); }
		//
		if (stepX == 1 && stepY == -1) { frameY = 2; }
		if (stepX == 0 && stepY == -1) { frameY = 3; this->duck->setScale(1, -1); }
		if (stepX == -1 && stepY == -1) { frameY = 2;  this->duck->setScale(-1, 1); }
		//
		if (stepX == -1 && stepY == 0) { frameY = 1; this, duck->setScale(-1, 1); }
		if (stepX == -1 && stepY == 1) { frameY = 2; this->duck->setScale(-1, 1); }
		//

		
		//std::cout << "X: " << stepX << "    Y: " << stepY << std::endl;

		

		// std::cout << "pos x :" << speed * frametime * (to.x - pos.x) / length << "       pos y: " << speed * frametime * (to.y - pos.y) / length << std::endl;
		duck->setPosition(pos);
		return false;
	}
	else { return true; }
}

void DuckBlue::move(AssertManager& manager, float frametime)
{
	// if final position has reached - find new one and move
	if (reachDestination) {
		this->new_pos = sf::Vector2f(rand() % 1920, rand() % 1080);
		//std::cout << new_pos.x << "   " << new_pos.y << std::endl;
		
		moveTo(manager, new_pos, frametime);
		reachDestination = false;
	}
	// if final pos wasn't reached - continue moving
	else { reachDestination = moveTo(manager, new_pos, frametime); }
}

sf::Sprite* DuckBlue::getDuck()
{
	return duck;
}

DuckBlue::~DuckBlue()
{
	delete duck;
}

