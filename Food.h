#pragma once
#include <SFML/Graphics.hpp>
#include<vector>
#include <time.h>
#include<cstdlib> // thu vien dung` ham` rand()
#include<iostream>


class Food
{
private:
	sf::Vector2f positionFood;

public:
	Food();
	void drawFood(sf::RenderWindow& window);
	void foodRespawn();
	float getPositionFoodX();
	float getPositionFoodY();
};

