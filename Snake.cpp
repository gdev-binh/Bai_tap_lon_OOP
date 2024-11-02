#include "Snake.h"

Snake::Snake()
{
	length = 3; // mac dinh do dai` con ran 
	dir = RIGHT; // mat dinh huong phai
	for (int i = 0; i < length; i++)
	{ // khoi tao con ran
		snake.push_back(sf::Vector2f(7 - i, 8));
	}
}

void Snake::drawSnake(sf::RenderWindow& window)
{
	sf::Texture T_blue_head, T_blue; // khai bao hinh anh? ran

	// load cac file hinh anh + gan cho bien
	T_blue_head.loadFromFile("images/blue_snake.png");
	T_blue.loadFromFile("images/blue.png");

	// hien thi cac hinh anh?
	sf::Sprite S_blue_head(T_blue_head);
	sf::Sprite S_blue(T_blue);

	for (float i = 0; i < snake.size(); i++)
	{
		if (i == 0)
		{
			S_blue_head.setPosition(snake[i].x * 32, snake[i].y * 32);
			window.draw(S_blue_head);
		}
		else
		{
			S_blue.setPosition(snake[i].x * 32, snake[i].y * 32);
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
	for (int i = snake.size() - 1; i > 0; --i)
	{	// snake.size() la` ham lay so luong phan tu 
		snake[i] = snake[i - 1];

	}
	if (dir == DOWN)
		snake[0].y += 1;
	if (dir == LEFT)
		snake[0].x -= 1;
	if (dir == RIGHT)
		snake[0].x += 1;
	if (dir == UP)
		snake[0].y -= 1;

	// kiem tra chay vuot bien 
	if (snake[0].x >= 17) // vuot qua bien phai
		snake[0].x = 1;
	if (snake[0].x < 1)	// vuot qua bien trai
		snake[0].x = 16;
	if (snake[0].y >= 18) // vuot qua bien duoi
		snake[0].y = 3;
	if (snake[0].y < 3)	// vuot qua bien tren
		snake[0].y = 17;

}

void Snake::grow()
{
	snake.push_back(snake.back());
}

float Snake::getHeadX()
{
	return snake[0].x;
}

float Snake::getHeadY()
{
	return snake[0].y;
}

int Snake::getSnakeSize()
{
	return snake.size();
}
