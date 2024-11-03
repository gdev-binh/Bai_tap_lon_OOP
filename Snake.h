#pragma once
#include "Food.h"




// KHOI TAO BIEN ENUM 0	 1	2	3
enum Direction { DOWN, LEFT, RIGHT, UP }; // huong di chuyen?
class Snake
{
private:

	std::vector<sf::Vector2f> snake_part; // tung` doan cua con ran
	int length; // do dai` con ran ban dau
	Direction dir; // khai bao  huong di chuyen

public:
	Snake(); // khoi tao ran' ban dau
	void drawSnake(sf::RenderWindow& window);
	void setDirectionSnake(Direction newDir);
	void snakeMove();
	void grow(); // them duoi

	int getSnakeSize();

	// lay vi tri con ran
	float getSnakePositionX(int i);
	float getSnakePositionY(int i);


};

