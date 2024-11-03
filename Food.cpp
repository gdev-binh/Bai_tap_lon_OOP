#include "Food.h"

Food::Food()
{
	positionFood.x = 12;
	positionFood.y = 8;
}

void Food::drawFood(sf::RenderWindow& window)
{
	sf::Texture tFood;
	tFood.loadFromFile("images/apple.png");
	sf::Sprite	sFood(tFood);
	sFood.setPosition(positionFood.x * 32, positionFood.y * 32);
	window.draw(sFood);
}

void Food::foodRespawn()
{
	// phai khac voi vi tri con ran dang nam`
	positionFood.x = rand() % (15 - 1 + 1)+1;
	positionFood.y = rand() % (17 - 3 + 1)+3; // tu 3 -> 17
}

float Food::getPositionFoodX()
{
	return positionFood.x;
}
float Food::getPositionFoodY()
{
	return positionFood.y;
}