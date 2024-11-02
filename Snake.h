#pragma once
#include "Food.h"

<<<<<<< HEAD
// KHOI TAO BIEN ENUM 0	 1	2	3
enum Direction { DOWN, LEFT, RIGHT, UP }; // huong di chuyen?
class Snake
{
private:

	std::vector<sf::Vector2f> snake; //
	int length; // do dai` con ran ban dau
	Direction dir; // khai bao  huong di chuyen


public:
	Snake(); // khoi tao ran' ban dau
	void drawSnake(sf::RenderWindow& window);
	void setDirectionSnake(Direction newDir);
	void snakeMove();
	void grow(); // them duoi
	float getHeadX();
	float getHeadY();

=======
class Snake
{
public:
    int x, y;
>>>>>>> main
};
