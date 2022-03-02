#include "DuckBlue.h"

DuckBlue::DuckBlue(AssertManager& manager) : Ducks(350, 5)
{
	// set duck sprite
	this->duck = new sf::Sprite(*manager.getTextureDuckBlue());
	this->duck->setTextureRect(sf::IntRect(0, 0, 75, 76.4));
	// set duck appearance ( at the random pos at the bottom ) 
	Ducks::setPosition(sf::Vector2f(0, 800));

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
	this->speed += 1;
	if (duck->getPosition().y >= 1080) { return true; }
	moveTo(manager, sf::Vector2f(this->duck->getPosition().x, 1920 - this->duck->getPosition().y - 100), frametime);
	frameY = 4;
	animation(manager, frametime);
	frameY = 5;
	return false;
}

bool DuckBlue::duckShootDown(AssertManager& manager, bool shoot)
{
	// mouse coords touch duck and a shot was fired
	if (shoot == true && this->duck->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition()))) {
		//std::cout << "coins: " << this->cost; 
		this->shootDown = true;
		return true;
	}
	return false;
}

// TODO: find pos:
// new_pos = sf::Vector2f(rand() % 1920, rand() % 1080);
// while (pos.x + 100 < new_pos.x _or_ pos.x - 100 < new_pos.x) // do same for Y
// { new_pos = sf::Vector2f(rand() % 1920, rand() % 1080)}
// return new_pos;

//TODO: add new pos check
// add sf::Vector2f pos_distination at Ducks file
// and bool reachDestination
// if (reachDestination) { если позиция достигнута (можно попробывать добавить саму функцию, ведь она тоже возвращает true если достигла)
// 	reachDestination = False;
// 	moveTo(findRandomPos());
// else { moveTo(getPosDestination())

// TODO: pos destination
// sf::Vector2f pos_destination = nullptr
// if (pos_destination == nullptr) { pos_destination = to; }
bool DuckBlue::moveTo(AssertManager& manager, sf::Vector2f to, float frametime)
{  
	// change "to" to pos_destination
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
		if (stepX == 1 && stepY == 1) { frameY = 2; this->duck->setScale(  1, 1); }
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
		
		
		// pos destination
	        // sf::Vector2f pos_destination = nullptr
                // if (pos_destination == nullptr) { pos_destination = to; }}
		
		duck->setPosition(pos);
		return false;
	}
	else { return true; }

sf::Vector2f DuckBlue::getRandomPosition(sf::Vector2f pos)
{
	this->pos = sf::Vector2f(rand() % 1920, rand() % 1080);
	while (pos.x - this->pos.x <= 100 && pos.x - this->pos.x >= -100 && pos.y - this->pos.y <= 100 && pos.y - this->pos.y >= -100){
		this->pos = sf::Vector2f(rand() % 1920, rand() % 1080);
	}
	return this->pos;
}

sf::Sprite* DuckBlue::getDuck()
{
	return duck;
}

DuckBlue::~DuckBlue()
{
	delete duck;
}

