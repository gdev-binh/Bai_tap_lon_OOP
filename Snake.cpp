#include "Snake.h"

Snake::Snake()
{
	length = 3; // mac dinh do dai` con ran 
	dir = RIGHT; // mat dinh huong phai
	for (int i = 0; i < length; i++)
	{ // khoi tao con ran
		snake_part.push_back(sf::Vector2f(7 - i, 8));
	}
}

void Snake::drawSnake(sf::RenderWindow& window)
{
	sf::Texture T_blue_head, T_blue; // khai bao hinh anh? ran

	// load cac file hinh anh + gan cho bien
	T_blue_head.loadFromFile("images/4d65b4-head.png");
	T_blue.loadFromFile("images/4d65b4.png");

	// hien thi cac hinh anh?
	sf::Sprite S_blue_head(T_blue_head);
	sf::Sprite S_blue(T_blue);

	for (float i = 0; i < snake_part.size(); i++)
	{
		if (i == 0)
		{
			S_blue_head.setPosition(snake_part[i].x * 32, snake_part[i].y * 32);
			window.draw(S_blue_head);
		}
		else
		{
			S_blue.setPosition(snake_part[i].x * 32, snake_part[i].y * 32);
			window.draw(S_blue);
		}


	}

}

void Snake::setDirectionSnake(Direction newDir)
{
	dir = newDir;
}

void Snake::snakeMove()
{
	Food f;
	for (int i = snake_part.size() - 1; i > 0; --i)
	{	// snake.size() la` ham lay so luong phan tu 
		snake_part[i] = snake_part[i - 1];

	}
	if (dir == DOWN)
		snake_part[0].y += 1;
	if (dir == LEFT)
		snake_part[0].x -= 1;
	if (dir == RIGHT)
		snake_part[0].x += 1;
	if (dir == UP)
		snake_part[0].y -= 1;

	// kiem tra chay vuot bien 
	if (snake_part[0].x >= 17) // vuot qua bien phai
		snake_part[0].x = 1;
	if (snake_part[0].x < 1)	// vuot qua bien trai
		snake_part[0].x = 16;
	if (snake_part[0].y >= 18) // vuot qua bien duoi
		snake_part[0].y = 3;
	if (snake_part[0].y < 3)	// vuot qua bien tren
		snake_part[0].y = 17;

}

void Snake::grow()
{
	snake_part.push_back(snake_part.back()); // them vao duoi
}

bool Snake::checkFoodEqualSnake(Food food) // kiem tra ran trung voi food
{
	for (int i = 0; i < snake_part.size() ; i++)
	{
		if (food.getPositionFoodX() == snake_part[i].x &&
			food.getPositionFoodY() == snake_part[i].y)
		{
			return false;
		}
	}
	return true;


}




int Snake::getSnakeSize()
{
	return snake_part.size();
}

float Snake::getSnakePositionX(int i)
{
	return snake_part[i].x;
}

float Snake::getSnakePositionY(int i)
{
	return snake_part[i].y;
}

