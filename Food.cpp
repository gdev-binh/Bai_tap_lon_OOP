#include "Food.h"

Food::Food()
{
	positionFood.x = 12;
	positionFood.y = 8;
}

void Food::drawFood(sf::RenderWindow& window)
{
	sf::Texture tFood;
	tFood.loadFromFile("images/blue.png");
	sf::Sprite	sFood(tFood);
	sFood.setPosition(positionFood.x * 32, positionFood.y * 32);
	window.draw(sFood);
}

void Food::foodRespawn()
{
	positionFood.x = rand() % 15;
	positionFood.y = rand() % 17;
}

float Food::getPositionFoodX()
{
	return positionFood.x;
}
float Food::getPositionFoodY()
{
	return positionFood.y;
}